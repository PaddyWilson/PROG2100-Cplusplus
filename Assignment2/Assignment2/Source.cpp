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

	void print()
	{
		cout << numerator << "/" << denominator << endl;
	}

};

int main()
{
	RationalNumber rationaal(1, 21);
	RationalNumber ration(1, 6);
	RationalNumber r = rationaal + ration;
	rationaal.print();
	ration.print();
	r.print();


	_getch();
	return 0;
}
