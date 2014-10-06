#include <string.h>
#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <sstream>
#include "RationalNumber.h"

using namespace std;

int main()
{
	RationalNumber rational1;
	RationalNumber rational2;

	//get number one
	cout << "number 1" << endl;
	cin >> rational1;
	//get number two
	cout << "number 2" << endl;
	cin >> rational2;

	//do math on the rational numbers
	cout << endl;
	cout << "First Rational: " << rational1 << endl;
	cout << "Second Rational: " << rational2 << endl;
	cout << "Add: " << rational1 + rational2 << endl;
	cout << "Sub: " << rational1 - rational2 << endl;
	cout << "Mult: " << rational1 * rational2 << endl;
	cout << "Div: " << rational1 / rational2 << endl;
	
	cout << "Rational1 == Rational2: ";
	if (rational1 == rational2)
		cout << "True" << endl;
	else
		cout << "False" << endl;

	cout << "Rational1 > Rational2: ";
	if (rational1 > rational2)
		cout << "True" << endl;
	else
		cout << "False" << endl;

	cout << "Rational1 < Rational2: ";
	if (rational1 < rational2)
		cout << "True" << endl;
	else
		cout << "False" << endl;

	_getch();
	return 0;
}
