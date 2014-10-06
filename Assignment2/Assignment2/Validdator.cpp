#include "Validator.h"

bool Validator::inputMechanism(string *inputString)
{
	char tempKey;
	const static int maxLineLength = 10;

	do{
		tempKey = _getch();
		if ((tempKey >= 48 && tempKey <= 57) || tempKey == 47)//ascii range 49 to 50
		{
			size_t find = (*inputString).find("/");
			if (find != string::npos && tempKey == 47)
			{
				(*inputString) += tempKey;
				printf("%c", tempKey);
				break;
			}

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
