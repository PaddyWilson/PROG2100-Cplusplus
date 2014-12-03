#include <iostream>
#include <sstream>
#include <conio.h>
using namespace std;

class ComplexNumber
{
private:
	double real;
	double imaginary;

public:
	ComplexNumber()//default
		:real(0), imaginary(0){}
	ComplexNumber(double real, double imaginary)//const with args
		: real(real), imaginary(imaginary){}
	ComplexNumber(string s)//const with string arg for "a+bi"
	{
		//parse routine goes here
		this->real = 3; //hard coded stub
		this->imaginary = 8; //hard coded stub
	}

	ComplexNumber operator+ (ComplexNumber &rightObj)
	{
		return ComplexNumber(this->real + rightObj.real, this->imaginary + rightObj.imaginary);
	}

	//code rest of operators here

	/*void print() //dirty
	{
	cout << this->real << " + " << this->imaginary << "i";
	_getch();
	}
	*/
	string toString()//clean - output is a string in a+bi format
	{
		stringstream strStream;
		string x, y;
		//next 5 lines used to do conversions from double to strings
		strStream << this->real;//place prop in stream ie buffer
		strStream >> x; //receive it back converted to a string
		strStream.clear();
		strStream << this->imaginary;//place prop in stream ie buffer
		strStream >> y; //receive it back converted to a string

		return(x + "+" + y + "i");//concat into a+bi format
	}
	friend void operator>> (istream &input, ComplexNumber &num);
	friend ostream& operator<< (ostream &output, ComplexNumber &num);

};//end class ComplexNumber

//implementation of friend methods

void operator>> (istream &input, ComplexNumber &num)
{
	string str;
	getline(input, str);//assign input to string var
	num = ComplexNumber(str);//call string constructor for "a+bi"
}

//clean - output is an output stream in a+bi format
ostream &operator<< (ostream &output, ComplexNumber &num)
{
	output << num.real << " + " << num.imaginary << "i";
	return output;// return outstream object
}



int main()
{
	//ComplexNumber cn;
	//cn.print();
	//cout << cn.toString() << endl;
	//_getch();

	cout << "Press any key to begin test of ComplexNumber Class" << endl;
	_getch();
	ComplexNumber cn;
	cout << cn << endl;
	_getch();

	//test of + operator and toString method
	cout << "Test of + operator and toString method" << endl;
	ComplexNumber cn1(8, 8);//create complex numbers
	ComplexNumber cn2(9, 9);
	ComplexNumber cnAns = cn1 + cn2;
	cout << cn1.toString() << " + " << cn2.toString() << " = " << cnAns.toString() << endl;

	//note: this is stubbed with values 3 and 8
	ComplexNumber CNd;
	cout << "Enter your complex number as a string: " << endl;
	cin >> CNd;//use of overridden >> operator
	cout << CNd << endl; /// output using friend method
	cout << "\n" << endl;
	cout << "Test complete" << endl;
	_getch();

	return 0;
}