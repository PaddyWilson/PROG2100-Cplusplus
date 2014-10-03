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

	RationalNumber operator* (RationalNumber &rightObj)
	{
		return RationalNumber(this->numerator * rightObj.numerator, this->denominator * rightObj.denominator);
	}

	RationalNumber operator/ (RationalNumber &rightObj)
	{
		return RationalNumber(this->numerator * rightObj.denominator, this->denominator * rightObj.numerator);
	}

	//for testing
	void print()
	{
		cout << numerator << "/" << denominator << endl;
	}

};

int main()
{
	RationalNumber rationaal(5, 4);
	RationalNumber ration(1, 6);
	RationalNumber radd = rationaal + ration;
	RationalNumber rsub = rationaal - ration;
	RationalNumber rmult = rationaal * ration;
	RationalNumber rdiv = rationaal / ration;
	rationaal.print();
	ration.print();
	radd.print();
	rsub.print();
	rmult.print();
	rdiv.print();


	_getch();
	return 0;
}
