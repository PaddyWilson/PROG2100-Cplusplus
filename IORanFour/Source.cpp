//demo of 
//input and outout
//random number

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <conio.h>

using namespace std;

int main()
{

	srand(time(0));

	for (int i = 0; i < 100; i++)
	{
		cout << i+1 << " " << 1 + rand() % 9 << endl;
	}


	//**********************************************************************

	//string myString;
	//float price = 0;
	//int quant = 0;

	//cout << "enter price ";
	//getline(cin, myString);
	////price = myString;
	//stringstream(myString) >> price;

	//cout << "enter quant ";
	//getline(cin, myString);
	//stringstream(myString) >> quant;

	//cout << "total cost is $" << price * quant << endl;

	//**********************************************************************

	/*string myString; 
	cout << "enter your name ";
	getline(cin, myString);
	cout << "Hi " << myString << " enter a sport ";
	getline(cin, myString);
	cout << "Thinger " << myString << ".\n";
	*/

	_getch();
	return 0;
}






