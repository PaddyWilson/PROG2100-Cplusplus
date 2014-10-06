#include "RationalNumber.h"

RationalNumber::RationalNumber() :numerator(0), denominator(1){}//default
RationalNumber::RationalNumber(int numerator) : numerator(numerator), denominator(1){}//if one number is entered
RationalNumber::RationalNumber(int numerator, int denominator) : numerator(numerator), denominator(denominator){}//two numbers entered

void RationalNumber::normalize()
{

}

//addition
RationalNumber RationalNumber::operator+ (RationalNumber &rightObj)
{
	if (this->denominator == rightObj.denominator)
	{
		return RationalNumber(this->numerator + rightObj.numerator, this->denominator);
	}
	else
	{
		int i = 1;
		int tempDenominator1 = this->denominator;
		int tempDenominator2;
		while (true)
		{
			tempDenominator1 = i * this->denominator;
			for (int z = 1; z < 15; z++)
			{
				tempDenominator2 = z * rightObj.denominator;
				if (tempDenominator1 == tempDenominator2)
				{
					return RationalNumber((this->numerator * i) + (rightObj.numerator * z), tempDenominator1);
				}
			}
			i++;
		}
	}
}

//subtration
RationalNumber RationalNumber::operator- (RationalNumber &rightObj)
{
	if (this->denominator == rightObj.denominator)
	{
		return RationalNumber(this->numerator + rightObj.numerator, this->denominator);
	}
	else
	{
		int i = 1;
		int tempDenominator1 = this->denominator;
		int tempDenominator2;
		while (true)
		{
			tempDenominator1 = i * this->denominator;
			for (int z = 1; z < 15; z++)
			{
				tempDenominator2 = z * rightObj.denominator;
				if (tempDenominator1 == tempDenominator2)
				{
					return RationalNumber((this->numerator * i) - (rightObj.numerator * z), tempDenominator1);
				}
			}
			i++;
		}
	}
}

//multiplication
RationalNumber RationalNumber::operator* (RationalNumber &rightObj)
{
	return RationalNumber(this->numerator * rightObj.numerator, this->denominator * rightObj.denominator);
}

//divide
RationalNumber RationalNumber::operator/ (RationalNumber &rightObj)
{
	return RationalNumber(this->numerator * rightObj.denominator, this->denominator * rightObj.numerator);
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
	string str;
	getline(input, str);//assign input to string var

	char *inputString = new char[str.size() + 1];
	inputString[str.size()] = 0;
	memcpy(inputString, str.c_str(), str.size());

	char * pch;
	pch = strtok(inputString, "/");

	int n = atoi(pch);
	int d;
	while (pch != NULL)
	{
		d = atoi(pch);
		pch = strtok(NULL, "/");
	}

	if (d == NULL)
	{
		num = RationalNumber(n);
		return;
	}
	else
	{
		num = RationalNumber(n, d);
		return;
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
