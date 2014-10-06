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
	RationalNumber() :numerator(0), denominator(1){}//default
	RationalNumber(int numerator) :numerator(numerator), denominator(1){}//if one number is entered
	RationalNumber(int numerator, int denominator) :numerator(numerator), denominator(denominator){}//two numbers entered

	void normalize()
	{

	}

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
		//broken
		if ((this->numerator * rightObj.denominator) > (this->denominator * rightObj.numerator))
		{
			return true;
		}
		return false;
	}

	//less than 
	bool operator< (RationalNumber &rightObj)
	{
		if ((this->numerator * rightObj.denominator) < (this->denominator * rightObj.numerator))
		{
			return true;
		}
		return false;
	}

	//prints operators
	friend void operator>> (istream &input, RationalNumber &num);
	friend ostream& operator<< (ostream &output, RationalNumber &num);
	//{
	//	output << num.numerator << "/" << num.denominator;
	//	return output;// return outstream object
	//}
};

void operator>> (istream &input, RationalNumber &num)
{
	string str;
	getline(input, str);//assign input to string var




	//char string[] = str.str();


	//num = RationalNumber(str);//call string constructor for "a+bi"
}

//clean - output is an output stream in a+bi format
ostream &operator<< (ostream &output, RationalNumber &num)
{
	/*if (num.denominator == 1)
	{
		output << num.numerator;
	}
	else
	{*/
		output << num.numerator << "/" << num.denominator;
	//}
	
	return output;// return outstream object
}

//strtok example
void strtokExample()
{
	int numT = 0;
	char str[] = "1/9";
	char * pch;
	printf("Splitting string \"%s\" into tokens:\n\n", str);
	pch = strtok(str, "/");
	while (pch != NULL)
	{
		printf("%s\n", pch);
		pch = strtok(NULL, " ,.-");
		numT++;
	}
	cout << "\nTotal tolkens: " << numT << endl;
	cout << "press any key for next example" << endl;
	cin.get();

}//end method strtokExample()

int main()
{
	string input;
	int n;
	int d;

	cout << "number 1" << endl;
	cout << "numerator" << endl;
	getline(cin, input);
	n = atoi(input.c_str());
	cout << "denom" << endl;
	getline(cin, input);
	d = atoi(input.c_str());

RationalNumber rational1(n, d);

cout << endl;
	cout << "number 2" << endl;
	cout << "numerator" << endl;
	getline(cin, input);
	n = atoi(input.c_str());
	cout << "denom" << endl;
	getline(cin, input);
	d = atoi(input.c_str());

	RationalNumber rational2(n, d);

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

	strtokExample();

	_getch();
	return 0;
}
