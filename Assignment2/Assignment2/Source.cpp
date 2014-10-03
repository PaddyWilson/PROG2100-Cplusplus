#include <string.h>
#include <conio.h>
#include <iostream>
#include <stdio.h>

using namespace std;

class RationalNumber
{
private:
	int numerator;
	int denominator;

public:
	RationalNumber() :numerator(0), denominator(1){}//default
	RationalNumber(int numerator) :numerator(numerator), denominator(1){}//if one number is entered
	RationalNumber(int numerator, int denominator) :numerator(numerator), denominator(denominator){}//two numbers entered

	//addition
	RationalNumber operator+ (RationalNumber &rightObj)
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
	RationalNumber operator- (RationalNumber &rightObj)
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
	RationalNumber operator* (RationalNumber &rightObj)
	{
		return RationalNumber(this->numerator * rightObj.numerator, this->denominator * rightObj.denominator);
	}

	//divide
	RationalNumber operator/ (RationalNumber &rightObj)
	{
		return RationalNumber(this->numerator * rightObj.denominator, this->denominator * rightObj.numerator);
	}

	//equal to
	bool operator== (RationalNumber &rightObj)
	{
		if ((this->numerator * rightObj.denominator) == (this->denominator * rightObj.numerator))
		{
			return true;
		}
		return false;
	}

	//greater than
	bool operator> (RationalNumber &rightObj)
	{
		if ((this->numerator * rightObj.denominator) == (this->denominator * rightObj.numerator))
		{
			return true;
		}
		return false;
	}

	//less than
	bool operator< (RationalNumber &rightObj)
	{
		return RationalNumber(this->numerator * rightObj.denominator, this->denominator * rightObj.numerator);
	}

	//prints operators
	friend void operator>> (istream &input, RationalNumber &num);
	friend ostream& operator<< (ostream &output, RationalNumber &num);
	//{
	//	output << num.numerator << "/" << num.denominator;
	//	return output;// return outstream object
	//}
};

//void operator>> (istream &input, RationalNumber &num)
//{
//	string str;
//	getline(input, str);//assign input to string var
//	num = RationalNumber(str);//call string constructor for "a+bi"
//}

//clean - output is an output stream in a+bi format
ostream &operator<< (ostream &output, RationalNumber &num)
{
	output << num.numerator << "/" << num.denominator;
	return output;// return outstream object
}


int main()
{
	RationalNumber rational1(5, 4);
	RationalNumber rational2(1, 6);
	RationalNumber rational3(1, 6);
	RationalNumber radd = rational1 + rational2;
	RationalNumber rsub = rational1 - rational2;
	RationalNumber rmult = rational1 * rational2;
	RationalNumber rdiv = rational1 / rational2;

	cout << "First: " << rational1 << endl;
	cout << "Second: " << rational2 << endl;
	cout << "Add: " << radd << endl;
	cout << "Sub: " << rsub << endl;
	cout << "Mult: " << rmult << endl;
	cout << "Div: " << rdiv << endl;

	if (rational2 == rational3)
	{
		cout << "true" << endl;
	}

	_getch();
	return 0;
}
