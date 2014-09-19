
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
				//i++;
			}
		}
		if (count == 8)
		{
			return 2;
		}

		return 0;
	}

	bool move(int i, string x_o)
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
		srand(static_cast<unsigned int>(time(NULL)));
		int i;
		do
		{
			i = 0 + rand() % 10;//picks random number
			int r = 0;
			int c = 0;
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
				//cout << "That spot is taken. Enter a number between 1-9" << endl;
			}
			else
			{
				p[r][c] = x_o;
				break;
			}
		} while (true);

		return i;
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
				pickLocation(game.board);
				cout << "Player" << endl;
				game.drawBoard();

				if (game.checkWin(player) == 1)
				{
					cout << player << " Wins" << endl;
					break;
				}

				comp.AIpick(game.board, computer);
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
				comp.AIpick(game.board, computer);
				cout << "Computer" << endl;
				game.drawBoard();

				if (game.checkWin(computer) == 1)
				{
					cout << computer << " Wins" << endl;
					break;
				}

				pickLocation(game.board);
				cout << "Player" << endl;
				game.drawBoard();

				if (game.checkWin(player) == 1)
				{
					cout << player << " Wins" << endl;
					break;
				}
			}

			if (game.checkWin(player) == 2)	
			{
				cout << "Its a Tie" << endl;
				break;
			}
		}

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
				p[r][c] = player;
				break;
			}
		}
		else
		{
			cout << "Enter a number between 1-9" << endl;
		}

	} while (true);

	return i;
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
