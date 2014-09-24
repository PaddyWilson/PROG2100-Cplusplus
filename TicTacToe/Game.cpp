#include "header.h"

string player;
string computer;

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
				else if (game.checkWin("") == 2)	
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
			else if (first == 3)//computer fight
			{
				int move = comp.AIpick(game.board, computer);
				game.move(move, computer);
				cout << "The Computer 1 Picked: " << move << endl;
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

				move = comp.AIpick(game.board, player);
				game.move(move, player);
				cout << "The Computer 2 Picked: " << move << endl;
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
	string select;
	int i;

	cout << "Pick a location 1-9" << endl;
	
	do
	{
		while (cin >> select == false)
		{

			if(cin.eof()) // quit if Ctrl+Z
				break; 
			if(cin == "1" || cin == "2" || cin == "3" || cin == "4" || cin == "5" || cin == "6" || cin == "7" || cin == "8" || cin == "9") 
				break;
			cin.clear(); // otherwise clear error states
			cout << "Enter a Valid Number" << endl;
		} 

		i = atoi(select.c_str());

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
	} while (true);

	return 0;
}

//displayes who goes first
int goFirst()
{
	string select;

	cout << "Who goes first? 1 = You, 2 = Computor, 3 = computer fight " << endl;

	while (cin >> select == false)
	{
		if(cin.eof()) // quit if Ctrl+Z
			break; 
		if(cin == "1" || cin == "2" || cin == "3") 
			break;
		cin.clear(); // otherwise clear error states
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
	else if(select == "3")
	{
		player = "O";
		computer = "X";
		return 3;
	}			
}

bool playAgain()
{
	string select;
	cout << "Play agian? 1 = Yes, 2 = No(Quits Application) " << endl;

	while (cin >> select == false)
	{
		if(cin.eof()) // quit if Ctrl+Z
			break; 
		if(cin == "1" || cin == "2") 
			break;
		cin.clear(); // otherwise clear error states
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