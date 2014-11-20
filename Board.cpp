#include "Board.h"
#include <iostream>
#include <string>
#include "Main_DLL.h"
#include <fstream>

using namespace std;

void Board::initializeBoard(States *state)
{
	/*N and L used for the loop*/
	int N =0, L =0;

	for(N=0;N<=7;N++)
	{
		for(L=0;L<=7;L++)
		{
			state->board[N][L] = '0';

			if(N==1) state->board[N][L] = 'P';
			if(N==6) state->board[N][L] = 'p';			
			
		}
	}

	// white pieces
	state->board[0][0] = 'R';
	state->board[0][1] = 'N';
	state->board[0][2] = 'B';
	state->board[0][3] = 'Q';
	state->board[0][4] = 'K';
	state->board[0][7] = 'R';
	state->board[0][6] = 'N';
	state->board[0][5] = 'B';

	//black pieces
	state->board[7][0] = 'r';
	state->board[7][1] = 'n';
	state->board[7][2] = 'b';
	state->board[7][3] = 'q';
	state->board[7][4] = 'k';
	state->board[7][7] = 'r';
	state->board[7][6] = 'n';
	state->board[7][5] = 'b';

	state->castle[0] = true;
	state->castle[1] = true;

	state->currentPlayer = white;
	
	for(N=0;N<8;N++)
	{
		state->enpass[0][N] = true;
		state->enpass[1][N] = true;
	}
}

/*
get the state as the parameter and print the 
board on screen
*/
void Board::printBoard(States *state)
{
	/*variables used for loop*/
	int indexY ;
	int indexX ;
	cout<<endl;

	for(indexY=7;indexY>=0;indexY--){

		/*print the row number*/
		cout << " "<<(indexY+1)<<" "; 

		/*print content of the board(array)*/
		for(indexX=0;indexX<=7;indexX++)
		{
			if(state->board[indexY][indexX]=='0')
			{
				cout<<"   "<<".";
			}
			else
			{
				cout<<"   "<<state->board[indexY][indexX];
			}			
		}
		
		cout << endl<<endl;
	}

	/*print the column letter*/
	
	cout<<endl<<"     A   B   C   D   E   F   G   H" <<endl<<endl;
}


void Board::startGame(States *state)
{
	int player =0;
	char data[100]; // get input from the file
	bool continueGame = true; // used to terminate if invalid move given

	cout<<"---------initial state---------"<<endl;
	printBoard(state);

	ifstream infile("C:\\Users\\tharindu\\Desktop\\test.txt");

	while(!infile.eof() && continueGame)
	{

		/******** altering the player*******/
		player++;		
		player = (player)%2;

		if(player == 1)
		{
			state->currentPlayer = white;
		}
		else
		{
			state->currentPlayer = black;
		}
		/**********************************/


		/*******printing the player color*************/
		if(player==1)
		{
			cout<<"---------White's Move---------"<<endl;
		}
		else
		{
			cout<<"---------Black's Move---------"<<endl;
		}

		/******************************************/


		/*command should not contain white spaces*/
		 infile >> data; 

		 cout<<"  "<<data<<endl; // print recieved data

		 /*returan false if invalid command found*/
		continueGame = ChessBoard::invokeMove(data,state);

		printBoard(state);

		cout<<endl;		
	
	}
		

	 infile.close();
}