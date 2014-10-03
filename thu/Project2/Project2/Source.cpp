//Notes:
//There are many ways and technologies to parse a string.
//Imagine the string as an array and that you need to examine each character in that array
//based on an olgorithm matched to your requirements. Some may find it useful to use 
//technologies such as tolkenizers or the more modern split functions to tolkenize/split 
//a string up based on the discovery of a specific character (called a delimiter) in the string.
//Each part of the string you isolate in this way is called a tolken.

//You may also use the <ctype> library for individual character functionality such as 'toupper',
//'isalpha', etc.The basic string class in C++ is lacking much of the functionality you find in 
//Java's String class so the <ctype> library can provide these. Some programmers even create their
//own custom string classes for this reason.


#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

void strtokExample(); //prototype strtok example
void chartokExample(string strIn); //prototype chartokExample

int main()
{
	strtokExample();

	string s = "Hello $";
	chartokExample(s);
	return 0;
}

//strtok example
void strtokExample()
{
	int numT = 0;
	char str[] = "- This, a sample string.";
	char * pch;
	printf("Splitting string \"%s\" into tokens:\n\n", str);
	pch = strtok(str, " ,.-");
	while (pch != NULL)
	{
		printf("%s\n", pch);
		pch = strtok(NULL, " ,.-");
		numT++;
	}
	cout << "\nTotal tolkens: " << numT << endl;
	cout << "press any key for next example" << endl;
	cin.get();

}//end method strtokExample()

//chartokExample
void chartokExample(string strIn)
{
	char dol;
	cout << "parsing into characters\n" << endl;
	char cArray[20]; // create a character array
	strIn.copy(cArray, 20); //copy string into character array

	for (int i = 0; i<20; i++)
	{
		if (cArray[i] == '$')
			dol = cArray[i];
	}
	cout << dol << endl;
	cin.get();
}//end method chartokExample