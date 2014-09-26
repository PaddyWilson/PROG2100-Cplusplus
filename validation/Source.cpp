//this validation prevents the user from crashing your program
//using input such as 'ctrl z'

#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <stdlib.h>
using namespace std;



class Validator
{
public:
	bool inputMechanism(string* inputString)
	{
		cout << "method inputMechansim involked" << endl;
		char tempKey;
		const static int maxLineLength = 1;

		do{
			tempKey = _getch();
			if ((tempKey >= 49 && tempKey <= 50))//ascii range 49 to 50
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

			}while (tempKey != 13);

			printf("\n");
			return true;
	}//end method inputMechanism
};//end class


int main()
{
	string strStuff;
	Validator myVal;//declare val obj

	//call mechanism to interactively handle keyboard input
	if (myVal.inputMechanism(&strStuff))
		cout << "The input string: " << strStuff << " is valid" << endl;
	else
		cout << "The input string: " << strStuff << " is NOT valid!" << endl;
	_getch();
	return 0;
}//end main

//int main()
//{
//	string strStuff;
//	Validator myVal;//declare val obj
//
//	//call mechanism to interactively handle keyboard input
//	if (myVal.inputMechanism(&strStuff))
//		cout << "The input string: " << strStuff << " is valid" << endl;
//	else
//		cout << "The input string: " << strStuff << " is NOT valid!" << endl;
//	_getch();
//	return 0;
//}//end main
