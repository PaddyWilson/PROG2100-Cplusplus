#include "RationalNumber.h"
#include "Validator.h"

RationalNumber::RationalNumber() :numerator(0), denominator(1){}//default
RationalNumber::RationalNumber(int numerator) : numerator(numerator), denominator(1){}//if one number is entered
RationalNumber::RationalNumber(int numerator, int denominator) : numerator(numerator), denominator(denominator){}//two numbers entered

RationalNumber RationalNumber::normalize(RationalNumber rational)
{
	if (rational.denominator < 0)
	{
		rational.numerator = -rational.numerator;
		rational.denominator = -rational.denominator;
	}

	int x = rational.numerator;
	int y = rational.denominator;

	if (x < 0)
	{
		x = -x;
	}
	if (y < 0)
	{
		y = -y;
	}
	if ((x + y) == 0)
	{
		return 0; /* Error, both parameters zero */
	}
	int g = y;
	/* Iterate until x = 0 */
	while (x > 0)
	{
		g = x;
		x = y % x;
		y = g;
	}

	//rational.numerator = rational.numerator / g;
	//rational.denominator = rational.denominator / g;

	return RationalNumber(rational.numerator / g, rational.denominator / g);
}

//addition 
RationalNumber RationalNumber::operator+ (RationalNumber &rightObj)
{
	//if they have the same denominator
	if (this->denominator == rightObj.denominator)
	{
		//return normalize(RationalNumber(this->numerator + rightObj.numerator, this->denominator));
		return normalize(RationalNumber(this->numerator + rightObj.numerator, this->denominator));
	}
	else// dont have same denominator
	{
		return normalize(RationalNumber((this->numerator * rightObj.denominator)+(rightObj.numerator * this->numerator),
								this->denominator * rightObj.denominator));
	}
}

//subtration 
RationalNumber RationalNumber::operator- (RationalNumber &rightObj)
{
	//same denominator
	if (this->denominator == rightObj.denominator)
	{
		return normalize(RationalNumber(this->numerator - rightObj.numerator, this->denominator));
	}
	else//different denominator
	{
		return normalize(RationalNumber((this->numerator * rightObj.denominator) - (rightObj.numerator * this->numerator),
								this->denominator * rightObj.denominator));
	}
}

//multiplication
RationalNumber RationalNumber::operator* (RationalNumber &rightObj)
{
	return normalize(RationalNumber(this->numerator * rightObj.numerator, this->denominator * rightObj.denominator));
}

//divide
RationalNumber RationalNumber::operator/ (RationalNumber &rightObj)
{
	return normalize(RationalNumber(this->numerator * rightObj.denominator, this->denominator * rightObj.numerator));
}

//equal to
bool RationalNumber::operator== (RationalNumber &rightObj)
{
	if ((this->numerator * rightObj.denominator) == (this->denominator * rightObj.numerator))
	{
		return true;
	}
	return false;
}

//greater than
bool RationalNumber::operator> (RationalNumber &rightObj)
{
	//broken
	if ((this->numerator * rightObj.denominator) > (this->denominator * rightObj.numerator))
	{
		return true;
	}
	return false;
}

//less than 
bool RationalNumber::operator< (RationalNumber &rightObj)
{
	if ((this->numerator * rightObj.denominator) < (this->denominator * rightObj.numerator))
	{
		return true;
	}
	return false;
}

//prints operators
void operator>> (istream &input, RationalNumber &num)
{
	Validator val;
	int n = 1;
	int d = 1;

	string str;

	while (true)
	{
		if (val.inputMechanism(&str))
			break;
		//else
			//cout << "Enter a Valid Number" << endl;
	}

	string word;
	stringstream stream(str);

	try
	{
		getline(stream, word, '/');
		n = stoi(word);
	}
	catch (...)
	{
		//cout << "Error" << endl;
	}
	
	try
	{
		getline(stream, word, '/');
		d = stoi(word);
	}
	catch (...)
	{
		//cout << "Error" << endl;
	}
	
	if (n == d)
	{
		num = num.normalize(RationalNumber(1));
	}
	else
	{
		num = num.normalize(RationalNumber(n, d));
	}
}

ostream& operator<< (ostream &output, RationalNumber &num)
{
	if (num.denominator == 1)
	{
		output << num.numerator;
	}
	else
	{
		output << num.numerator << "/" << num.denominator;
	}
	return output;// return outstream object
}
