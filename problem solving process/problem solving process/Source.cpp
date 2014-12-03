// ___ ___  ___  ___ _    ___ __  __   ___  ___  _ __   _____ _  _  ___
//| _ \ _ \/ _ \| _ ) |  | __|  \/  | / __|/ _ \| |\ \ / /_ _| \| |/ __|
//|  _/   / (_) | _ \ |__| _|| |\/| | \__ \ (_) | |_\ V / | || .` | (_ |
//|_| |_|_\\___/|___/____|___|_|  |_| |___/\___/|____\_/ |___|_|\_|\___|
//                    ___ ___  ___   ___ ___ ___ ___
//                   | _ \ _ \/ _ \ / __| __/ __/ __|
//                   |  _/   / (_) | (__| _|\__ \__ \
//                   |_| |_|_\\___/ \___|___|___/___/


//               YES   =============================   NO
//        +-----------|| Does the Darn Thing work? ||-----------+
//        |            =============================            |
//        V                                                     V
//   +----------+     +---------+                          +---------+
//   |   Don't  |  NO |   Does  |       +-------+     YES  | Did you |
//   |   mess   | +---|  anyone |<------|  YOU  |<---------|   mess  |
//   | with it! | |   |  know?  |       | MORON |          | with it |
//   +----------+ |   +---------+       +-------+          +---------+
//        |       V        | YES                                |  NO
//        |    +------+    +-----------+                        |
//        |    | HIDE |                V                        V
//        |    |  IT  |            +--------+             +-----------+
//        |    +------+            |  YOU   |        YES  | WILL THEY |
//        |       |       +------->|  POOR  |<------------| CATCH YOU?|
//        |       |       |        |BASTARD!|             +-----------+
//        |       |       |        |________|                   |  NO
//        |       |       |             |                       |
//        |       |       |             V                       V
//        |       |       |      +---------------+        +-----------+
//        |       |       |  NO  | CAN YOU BLAME |        |DESTROY THE|
//        |       |       +------| SOMEONE ELSE? |        |  EVIDENCE |
//        |       |              +---------------+        +-----------+
//        |       |                     |  YES                  |
//        |       |                     v                       |
//        |       |      ============================           |
//        |       +---->||           N O            ||<---------+
//        +------------>||      P R O B L E M       ||
//                       ============================

#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <stdlib.h>
using namespace std;


using namespace std;

string input();
void poor(string select);

class Validator
{
public:
	bool inputMechanism(string* inputString)
	{
		char tempKey;
		const static int maxLineLength = 1;

		do{
			tempKey = _getch();
			if ((tempKey == 121 || tempKey == 110))//ascii range 32 to 126
			{
				//when valid char pressed, accept and print to screen
				if (maxLineLength > (*inputString).length())
				{
					(*inputString) += tempKey;
					printf("%c", tempKey);
				}
			}//end if
			else if (tempKey == 8)//ascii backspace
			{
				//if back pressed, pop char off string, and erase from screen
				if ((*inputString).length() > 0)
				{
					(*inputString).erase((*inputString).length() - 1, 1);
					printf("\b \b");
				}
			} //end else if
			else if (tempKey == -32)//drop off any arrow key pressed
			{
				_getch();
			}// end else if

		} while (tempKey != 13);

		printf("\n");
		return true;
	}//end method inputMechanism
};//end class

int main()
{
	string select;
	while (true)
	{
		cout << "Does the darn thing work" << endl;
		select = input();
		if (select == "y")
		{
			cout << "Don't Mess With It" << endl;
		}
		else if (select == "n")
		{
			cout << "Did You Mess With It" << endl;
			select = input();
			if (select == "y")
			{
				cout << "You Moron" << endl;
				cout << "Does Anyone Know" << endl;
				select = input();
				if (select == "y")
				{
					poor(select);
				}
				else if (select == "n")
				{
					cout << "Hide it" << endl;
				}
			}
			else if (select == "n")
			{
				cout << "Will they catch you" << endl;
				select = input();
				if (select == "y")
				{
					poor(select);
				}
				else if (select == "n")
				{
					cout << "Distroy the evidence" << endl;
				}
			}
		}
		cout << "No Problem" << endl;
		_getch();
		cout << endl;
	}
	return 0;
}

void poor(string select)
{
	do
	{
		cout << "You Poor Bastard" << endl;
		cout << "Can You Blame Someone Else" << endl;
		select = input();
	} while (select == "n");
}

string input()
{
	Validator val;
	string select;
	while (true)
	{
		//call mechanism to interactively handle keyboard input
		if (val.inputMechanism(&select))
			break;
		else
			cout << "Enter a Valid Number" << endl;
	}
	return select;
}