
#define _SCI_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <conio.h>

using namespace std;

//prototype
void strToTokens();
void charToToken(string s);

int main()
{
	string s = "Hello %";
	cout << "String token example" << endl;
	strToTokens();
	
	//cout << "char token example" << endl;
	//charToToken(s);

	_getch();
	return 1;
}


void strToTokens()
{
	int numT = 0;
	char str[] = "Hello,World";
	char* pch = NULL;
	printf("Splitting string %s", str);

	pch = strtok(str, " ,.");
	while (pch != NULL)
	{
		printf("%s", pch);
		pch = strtok(str, " ,.");
		numT++;
	}

	cout << "end" << endl;


}




