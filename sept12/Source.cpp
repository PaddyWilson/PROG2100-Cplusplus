
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
	string phrase1 = "1";
	string phrase2 = "2";
	string phrase3 = "3";
	string phrase4 = "4";

	string *p1 = &phrase1;
	string *p2 = &phrase2;
	string *p3 = &phrase3;
	string *p4 = &phrase4;


	cout << p1 << endl;
	cout << *p1 << endl;

	cout << p2 << endl;
	cout << *p2 << endl;


	//how to make 'nameless' var aka dynamic variable 
	int *pNless; // pointer
	pNless = new int;//pointer to a dynamic var

	*pNless = 42;


	 cout << *pNless << endl;
	_getch();
	return 0;

}