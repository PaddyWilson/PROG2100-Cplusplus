#include "header.h"

string player;
string computer;

class Validator
{
public:
	bool inputMechanism(string* inputString, int topOfASCIIRange)
	{
		char tempKey;
		const static int maxLineLength = 1;
		bool empty = true;

		do
		{
			tempKey = _getch();
			if ((tempKey >= 49 && tempKey <= topOfASCIIRange))//ascii range 49 + other range
			{
				//when valid char pressed, accept and print to screen
				if (maxLineLength > (*inputString).length())
				{
					(*inputString) += tempKey;
					printf("%c", tempKey);
					empty = false;
				}
			}//end if
			else if (tempKey == 8)//ascii backspace
			{
				//if back pressed, pop char off string, and erase from screen
				if ((*inputString).length() > 0)
				{
					(*inputString).erase((*inputString).length() - 1, 1);
					printf("\b \b");
					empty = true;
				}
			} //end else if
			else if (tempKey == -32)//drop off any arrow key pressed
			{
				_getch();
			}// end else if

			if (tempKey == 13 && empty != true)
			{
				break;
			}
		}while (true);

		printf("\n");
		return true;
	}//end method inputMechanism
};//end class

int main()
{
	OutputDebugString("Game Starts\n");
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
				else if (game.checkTie())	
				{
					cout << "Its a Tie" << endl;
					break;
				}


				int move = comp.AIpick(game.board, computer);
				game.move(move, computer);
				cout << "The Computer Picked: " << move << endl;
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
				int move = comp.AIpick(game.board, computer);
				game.move(move, computer);
				cout << "The Computer Picked: " << move << endl;
				game.drawBoard();

				if (game.checkWin(computer) == 1)
				{
					cout << computer << " Wins" << endl;
					break;
				}
				else if (game.checkTie())	
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
	Validator myVal;//declare val obj
	string select;
	int i;

	cout << "Pick a location 1-9" << endl;
		
	while (true)
	{
		select = "";
		while (true)
		{
			//call mechanism to interactively handle keyboard input
			if (myVal.inputMechanism(&select, 57))
				break;
			else
				cout << "Enter a Valid Number" << endl;	
		}

		i = atoi(select.c_str());

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
		}//end switch

		if (p[r][c] == "O" || p[r][c] == "X")//checks to see if the selected board slot is taken
		{
			cout << "That spot is taken. Enter a number between 1-9" << endl;
		}
		else
		{
			return i;
		}

	}//end while (cin >> select)

	return 0;
}//end method

//displayes who goes first
int goFirst()
{
	string select;
	Validator myVal;//declare val obj

	cout << "Who goes first? 1 = You, 2 = Computor" << endl;

	while (true)
	{
		//call mechanism to interactively handle keyboard input
		if (myVal.inputMechanism(&select, 50))
			break;
		else
			cout << "Enter a Valid Number" << endl;	
	}
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
}

bool playAgain()
{
	Validator myVal;//declare val obj
	string select;
	cout << "Play agian? 1 = Yes, 2 = No(Quits Application)" << endl;

	while (true)
	{
		//call mechanism to interactively handle keyboard input
		if (myVal.inputMechanism(&select, 50))
			break;
		else
			cout << "Enter a Valid Number" << endl;	
	}

	if(select == "1")
	{
		return true;
	}
	else if (select == "2")
	{
		return false;
	}
}