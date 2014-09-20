
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class gameBoard
{
	//string board[3][3];// = {{"1", "2", "3"}, {"4", "5", "6"}, {"7", "8", "9"}};
	//string (*p)[3];
	public:gameBoard()
	{
		resetBorad();
		//p = board;
	}

	//string (*p)[3];
	string board[3][3];

	void resetBorad()
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
	int checkWin(string x_o)
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

		//tie
		int i = 0;
		int count = 0;
		for (int r = 0; r < 3; r++)
		{
			for (int c = 0; c < 3; c++)
			{
				i++;
				if (board[r][c] == to_string(i))
				{
					return 0;
				}
				else
				{
					count++;
				}
			}
		}
		//cout << count << endl;
		if (count == 9)
		{
			return 2;
		}

		return 0;
	}

	//gets the move and places a X or O there
	void move(int i, string x_o)
	{
		int r, c;
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
	void drawBoard()
	{
		for (int r = 0; r < 3; r++)
		{
			for (int c = 0; c < 3; c++)
			{
				cout << "[" << board[r][c] << "]";
				if (c < 2)
				{}
				else
					cout << endl;
			}
		}
	}

};

class computerAI
{
	public:computerAI()
	{

	}

	//ai picks locaton
	int AIpick(string p[][3], string x_o)
	{
		string player;
		/*
			1|2|3
		   -------
			4|5|6
		   -------
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
			return 1;
		}

		//rest of game
		//checks to see if it can win
		int x = move(p, x_o, player);
		//cout << x << " comp win" << endl;
		if (x != 0)
		{
			return x;
		}

		//checks for blocks
		x = move(p, player, x_o);
		//cout << x << " comp block" << endl;
		if (x!=0)
		{
			return x;
		}

		//if it cant win or block


		//for (int i = 0; i < 3; i++)
		//{
		//	if (p[i][0] == computer && p[i][1] == computer)//1, 2
		//	{
		//		return 3 + (i * 3);
		//	}
		//	else if (p[i][0] == computer && p[i][2] == computer)//1, 3
		//	{
		//		return 2 + (i * 3);
		//	}
		//	else if (p[i][1] == computer && p[i][2] == computer)//1, 3
		//	{
		//		return 1 + (i * 3);
		//	}
		//}
		////col
		//for (int i = 0; i < 3; i++)
		//{
		//	if (p[0][i] == computer && p[1][i] == computer)
		//	{
		//		return 7 + i;
		//	}
		//	else if (p[0][i] == computer && p[2][i] == computer)//1, 3
		//	{
		//		return 4 + i;
		//	}
		//	else if (p[i][i] == computer && p[i][i] == computer)//1, 3
		//	{
		//		return 1 + i;
		//	}
		//}
		////diagnal
		//if (p[0][0] == computer && p[1][1] == computer)
		//{
		//	return 9;
		//}
		//else if (p[0][0] == computer && p[2][2] == computer)
		//{
		//	return 5;
		//}
		//else if (p[1][1] == computer && p[2][2] == computer)
		//{
		//	return 1;
		//}
		//else if (p[0][3] == computer && p[1][1] == computer)
		//{
		//	return 7;
		//}
		//else if (p[0][3] == computer && p[2][0] == computer)
		//{
		//	return 5;
		//}
		//else if (p[1][1] == computer && p[2][0] == computer)
		//{
		//	return 3;
		//}

		//blocks



		//randomly select a spot and validate its not taken
		//if it is taken it tries again

		srand(static_cast<unsigned int>(time(NULL)));
		int randomNumber;
		do
		{
			randomNumber = 0 + rand() % 10;//picks random number
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

			if (p[r][c] != "O" || p[r][c] != "X")//checks to see if the selected board slot is taken
			{
				return randomNumber;//cout << "That spot is taken. Enter a number between 1-9" << endl;
			}
		} while (true);

		//return i;
	}

	int move(string p[][3], string computer, string player)
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

};

int pickLocation(string p[][3]);
int goFirst();
bool playAgain();

string player;
string computer;

int main()
{
	gameBoard game;
	computerAI comp;
	do
	{
		game.resetBorad();
		int first = goFirst();//who goes first

		game.drawBoard();
		while (true)
		{
			if (first == 1)
			{
				//player goes first
				game.move(pickLocation(game.board), player);
				cout << "Player" << endl;
				game.drawBoard();

				if (game.checkWin(player) == 1)
				{
					cout << player << " Wins" << endl;
					break;
				}
				else if (game.checkWin("") == 2)	
				{
					cout << "Its a Tie" << endl;
					break;
				}

				game.move(comp.AIpick(game.board, computer), computer);
				cout << "Computer" << endl;
				game.drawBoard();

				if (game.checkWin(computer) == 1)
				{
					cout << computer << " Wins" << endl;
					break;
				}

			}
			else if (first == 2)
			{
				//computer goes first
				game.move(comp.AIpick(game.board, computer), computer);
				cout << "Computer" << endl;
				game.drawBoard();

				if (game.checkWin(computer) == 1)
				{
					cout << computer << " Wins" << endl;
					break;
				}
				else if (game.checkWin("") == 2)	
				{
					cout << "Its a Tie" << endl;
					break;
				}

				game.move(pickLocation(game.board), player);
				cout << "Player" << endl;
				game.drawBoard();

				if (game.checkWin(player) == 1)
				{
					cout << player << " Wins" << endl;
					break;
				}
			}
		}//end while

	} while (playAgain());//end do while. Sees if the user want to play again

	return 0;
}

//user picks a location and it validates that the spot is not taken
int pickLocation(string p[][3])
{
	string input;
	cout << "Pick a location 1-9" << endl;
	
	int i;

	do
	{
		getline(cin, input);
		i = atoi(input.c_str());

		if (i > 0 && i < 10)//checks to see if the input is between 1 and 9
		{
			int r, c;
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

			if (p[r][c] == "O" || p[r][c] == "X")//checks to see if the selected board slot is taken
			{
				cout << "That spot is taken. Enter a number between 1-9" << endl;
			}
			else
			{
				return i;
			}
		}
		else
		{
			cout << "Enter a number between 1-9" << endl;
		}

	} while (true);

	return 0;
}

//displayes who goes first
int goFirst()
{
	string select;
	do
	{
		cout << "Who goes first? 1 = You, 2 = Computor " << endl;
		getline(cin, select);
		
		if (select == "1")
		{
			player = "X";
			computer = "O";
			return 1;
		}
		else if(select == "2")
		{
			player = "O";
			computer = "X";
			return 2;
		}
		else
		{
			cout << "error" << endl;
		}			
	} while (true);
}

bool playAgain()
{
	do
	{
		string select;
		cout << "Play agian? 1 = Yes, 2 = No(Quits Application) " << endl;
		getline(cin, select);
		if(select == "1")
		{
			return true;
		}
		else if (select == "2")
		{
			return false;
		}
	} while (true);
}