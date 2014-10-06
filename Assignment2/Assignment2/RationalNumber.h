#ifndef RATIONALNUMBER_H //if not defined
#define RATIONALNUMBER_H

#include <string.h>
#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <sstream>

using namespace std;

class RationalNumber
{
private:
	int numerator;
	int denominator;

public:
	RationalNumber();
	RationalNumber(int numerator);
	RationalNumber(int numerator, int denominator);

	RationalNumber normalize(RationalNumber rational);

	//addition
	RationalNumber operator+ (RationalNumber &rightObj);

	//subtration
	RationalNumber operator- (RationalNumber &rightObj);

	//multiplication
	RationalNumber operator* (RationalNumber &rightObj);

	//divide
	RationalNumber operator/ (RationalNumber &rightObj);

	//equal to
	bool operator== (RationalNumber &rightObj);

	//greater than
	bool operator> (RationalNumber &rightObj);

	//less than 
	bool operator< (RationalNumber &rightObj);

	//prints operators
	friend void operator>> (istream &input, RationalNumber &num);
	friend ostream& operator<< (ostream &output, RationalNumber &num);
};

#endif