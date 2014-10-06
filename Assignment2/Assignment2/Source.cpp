#include <string.h>
#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <sstream>

#include <regex>

#include "RationalNumber.h"

using namespace std;

int main()
{
	RationalNumber rational1;
	RationalNumber rational2;

	string input;

	do
	{	
		//get number one
		cout << "Enter the first rational number. ie: 1, 1/9" << endl;
		cin >> rational1;
	
		//get number two
		cout << "Enter the second rational number. ie: 1, 1/9" << endl;
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

		cout << endl;

	} while (true);
	
	return 0;
}
