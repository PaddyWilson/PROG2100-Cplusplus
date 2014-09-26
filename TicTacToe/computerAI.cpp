#include "header.h"

//ai picks locaton
int computerAI::AIpick(string p[][3], string x_o)
{
	OutputDebugString("Computer Pick Start *******************************\n");
	string player;
	/*
		1|2|3
		-----
		4|5|6
		-----
		7|8|9
	*/
		
	if (x_o == "X")
	{
		player = "O";
	}
	else
	{
		player = "X";
	}

	//checks to see if its the first play of the game
	OutputDebugString("Computer: First Move\n");
	int i = 0;
	int count = 0;
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			i++;
			if (p[r][c] == to_string(i))
			{
				count++;
			}
		}
	}
	if (count == 9)
	{
		OutputDebugString("Computer: First Move Yes\n");
		return 5;
	}

	int x = 0;

	//rest of game
	//checks to see if it can win
	OutputDebugString("Computer: Check Wins\n");
	x = checkWinsOrBlocks(p, x_o, player);
	//cout << x << " comp win" << endl;
	if (x != 0)
	{
		OutputDebugString("Computer: Check Wins Yes\n");
		return x;
	}

	//checks for blocks
	OutputDebugString("Computer: Check Blocks\n");
	x = checkWinsOrBlocks(p, player, x_o);
	//cout << x << " comp block" << endl;
	if (x!=0)
	{
		OutputDebugString("Computer: Check Block Yes\n");
		return x;
	}
	
	
	if (p[1][1] == player && (p[0][0] != x_o && p[0][0] != player))
	{
		return 1;
	}
	else if (p[0][0] == player && (p[1][1] != x_o && p[1][1] != player))
	{
		return 5;
	}
	else if (p[0][2] == player && (p[1][1] != x_o && p[1][1] != player))
	{
		return 5;
	}
	else if (p[2][0] == player && (p[1][1] != x_o && p[1][1] != player))
	{
		return 5;
	}
	else if (p[2][2] == player  && (p[1][1] != x_o && p[1][1] != player))
	{
		return 5;
	}
	else if (p[0][1] == player  && (p[1][1] != x_o && p[1][1] != player))
	{
		return 5;
	}
	else if (p[1][0] == player  && (p[1][1] != x_o && p[1][1] != player))
	{
		return 5;
	}
	else if (p[2][1] == player  && (p[1][1] != x_o && p[1][1] != player))
	{
		return 5;
	}
	else if (p[1][2] == player  && (p[1][1] != x_o && p[1][1] != player))
	{
		return 5;
	}
	else if (p[0][0] == player && (p[2][2] != x_o && p[2][2] != player))
	{
		return 9;
	}
	else if (p[0][2] == player && (p[2][0] != x_o && p[2][0] != player))
	{
		return 7;
	}	
	else if (p[2][2] == player  && (p[0][0] != x_o && p[0][0] != player))
	{
		return 1;
	}
	else if ((p[2][2] == player && p[0][0] == player) && (p[0][1] != x_o && p[0][1] != player))
	{
		return 2;
	}
	else if ((p[0][2] == player && p[2][0] == player)  && p[0][1] != x_o)
	{
		return 2;
	}
	else if (p[1][1] == player && p[2][2] == player && (p[0][2] != x_o && p[0][2] != x_o))
	{
		return 3;
	}
	else if (p[2][0] == player && (p[0][2] != x_o && p[0][2] != player))
	{
		return 3;
	}
	else if (p[1][2] == player && p[2][1] == player && (p[2][2] != x_o && p[2][2] != player))
	{
		return 9;
	}
	else if (p[1][0] == player && p[2][1] == player && (p[2][0] != x_o && p[2][0] != player))
	{
		return 7;
	}
	else if (p[0][2] == player && p[1][2] == player && (p[0][2] != x_o && p[0][2] != x_o))
	{
		return 3;
	}
	else if (p[0][1] == player && p[1][0] == player && (p[0][0] != x_o && p[0][0] != x_o))
	{
		return 1;
	}

	//uses rng as a last resort
	OutputDebugString("Computer: Random Number\n");
	srand(static_cast<unsigned int>(time(NULL)));
	int a = 0;
	int randomNumber;
	do
	{
		a++;
		randomNumber = 0 + rand() % 9;//picks random number
		int r = 0;
		int c = 0;
		switch (randomNumber)
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

		if (p[r][c] != "O" && p[r][c] != "X")//checks to see if the selected board slot is taken
		{
			OutputDebugString("Computer: Random Number Yes\n");
			return randomNumber;//cout << "That spot is taken. Enter a number between 1-9" << endl;
		}
		//if (a >= 9)//if random goes more than 9 times or more it breaks
		//{
		//	OutputDebugString("Computer: Random Number Went 9 or more times\n");
		//	break;
		//}
		OutputDebugString("Computer: Random Number Pick Again\n");
	} while (true);

	return x;
}

int computerAI::checkWinsOrBlocks(string p[][3], string computer, string player)
{
	//check for wins in rows
	for (int i = 0; i < 3; i++)
	{
		//cout << "check row " << computer << endl;
		if (p[i][0] == computer && p[i][1] == computer && p[i][2] != player)//1, 2
		{
			return 3 + (i * 3);
		}
		else if (p[i][0] == computer && p[i][2] == computer && p[i][1] != player)//1, 3
		{
			return 2 + (i * 3);
		}
		else if (p[i][1] == computer && p[i][2] == computer && p[i][0] != player)//1, 3
		{
			return 1 + (i * 3);
		}
	}
	//col
	for (int i = 0; i < 3; i++)
	{
		//cout << "check col " << computer << endl;
		if (p[0][i] == computer && p[1][i] == computer && p[2][i] != player)
		{
			return 7 + i;
		}
		else if (p[0][i] == computer && p[2][i] == computer && p[1][i] != player)
		{
			return 4 + i;
		}
		else if (p[1][i] == computer && p[2][i] == computer && p[0][i] != player)
		{
			return 1 + i;
		}
	}
	//diagnal
	//cout << "check diag " << computer << endl;
	if (p[0][0] == computer && p[1][1] == computer  && p[2][2] != player)
	{
		return 9;
	}
	else if (p[0][0] == computer && p[2][2] == computer && p[1][1] != player)
	{
		return 5;
	}
	else if (p[1][1] == computer && p[2][2] == computer && p[0][0] != player)
	{
		return 1;
	}
	else if (p[0][2] == computer && p[1][1] == computer && p[2][0] != player)
	{
		return 7;
	}
	else if (p[0][2] == computer && p[2][0] == computer && p[1][1] != player)
	{
		return 5;
	}
	else if (p[1][1] == computer && p[2][0] == computer && p[0][2] != player)
	{
		return 3;
	}

	return 0;
}