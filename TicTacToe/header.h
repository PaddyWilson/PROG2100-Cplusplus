#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

#include <Windows.h> // for the OutputDebugString("");

using namespace std;

int pickLocation(string p[][3]);
int goFirst();
bool playAgain();

class gameBoard
{
	public:
		string board[3][3];

		gameBoard();	
		//resets the board
		void resetBorad();
		//checks for wins or ties
		int checkWin(string x_o);
		//gets the move and places a X or O there
		void move(int i, string x_o);
		//draws board to screen
		void drawBoard();
};

class computerAI
{
	public:
		//ai picks locaton
		int AIpick(string p[][3], string x_o);

		int checkWinsOrBlocks(string p[][3], string computer, string player);
};



