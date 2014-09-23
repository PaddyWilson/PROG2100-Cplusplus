
#include "header.h"

#include <Windows.h>// for outputdebugstring function

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
				game.move(comp.AIpick(game.board, player), player);
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