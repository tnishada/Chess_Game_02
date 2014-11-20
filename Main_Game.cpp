// Chess_Game_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Main_DLL.h"
#include "CommandReader.h"
#include <iostream>
#include "Board.h"


using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{		
	States *state = new States();
	
	Board::initializeBoard(state);
	Board::startGame(state);	
					
	return 0;
}
