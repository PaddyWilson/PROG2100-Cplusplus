#include "header.h"

gameBoard::gameBoard()
{
	resetBorad();
}

void gameBoard::resetBorad()
{
	int i = 0;
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			i++;
			board[r][c] = to_string(i);
		}
	}
}

//checks for wins or ties
int gameBoard::checkWin(string x_o)
{
	//check rows
	for (int i = 0; i < 3; i++)
	{
		//cout << "Check 1" << endl;
		if (board[i][0] == x_o && board[i][1] == x_o && board[i][2] == x_o)
		{
			//cout << "Check 1 true" << endl;
			return 1;
		}
	}

	//check col
	for (int i = 0; i < 3; i++)
	{
		//cout << "Check 2" << endl;
		if (board[0][i] == x_o && board[1][i] == x_o && board[2][i] == x_o)
		{
			//cout << "Check 2 true" << endl;
			return 1;
		}
	}

	//diagnial 
	if (board[0][0] == x_o && board[1][1] == x_o && board[2][2] == x_o)
	{
		return 1;
	}

	if (board[0][2] == x_o && board[1][1] == x_o && board[2][0] == x_o)
	{
		return 1;
	}

	return 0;
}

bool gameBoard::checkTie()
{
	//tie
	int i = 0;
	int count = 0;
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			i++;
			if (board[r][c] != to_string(i))
			{
				count++;
			}
		}
	}
	//cout << count << endl;
	if (count >= 9)
	{
		return true;
	}
	return false;
}

//gets the move and places a X or O there
void gameBoard::move(int i, string x_o)
{
	int r = -1;
	int c = -1;

	switch (i)
	{
		case 1:
			r = 0;
			c = 0;
			break;
		case 2:
			r = 0;
			c = 1;
			break;
		case 3:
			r = 0;
			c = 2;
			break;
		case 4:
			r = 1;
			c = 0;
			break;
		case 5:
			r = 1;
			c = 1;
			break;
		case 6:
			r = 1;
			c = 2;
			break;
		case 7:
			r = 2;
			c = 0;
			break;
		case 8:
			r = 2;
			c = 1;
			break;
		case 9:
			r = 2;
			c = 2;
			break;
		default:
			break;
	}
	board[r][c] = x_o;
}

//draws board to screen
void gameBoard::drawBoard()
{
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			cout << "[" << board[r][c] << "]";
			if (c == 2)
				cout << endl;
		}
	}
}
