#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

bool inputValidation(string* inputString)
{
	char tempKey;
	const static int maxLineLength = 20;

	do
	{
		tempKey = _getch();

		if ((tempKey >= 32 && tempKey < 126))
		{
			//when valid charaters pressed, accept and print to screen
			if (maxLineLength  > (*inputString).length())
			{
				(*inputString) += tempKey;
				printf("%c",  tempKey);
			}
			else if (tempKey == 8)
			{
				//if backspace is pressed, pop char off of string and remove from screen
				if ((*inputString).length() >0)
				{
					(*inputString).erase((*inputString).length() - 1, 1);
					printf("\b \b");
				}
			}//end of if else
			else if (tempKey == -32)//arrow keys
			{
				_getch();
			}
		}

	} while (tempKey != 13); //end do

	printf("\n");

	return true;
}


