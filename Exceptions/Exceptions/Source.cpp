#include <conio.h>
#include <iostream>

using namespace std;

struct e1
{
	const char* message;

	e1() :message("Construct e1")
	{}
};

struct e2
{
	const char* message;

	e2() :message("Construct e2")
	{}
};

void f()
{
	try{
		cout << "try catch" << endl;
		cout << "throw exception of e1" << endl;
		e1 e1;
		e2 e2;
		throw e1;
	}
	catch (e1 e1)
	{
		cout << "caught in e1 " << e1.message << endl;
	}
	catch (e2 e2)
	{
		cout << "caught in e1 " << e2.message << endl;
	}
	catch (exception e)
	{
		cout << "Gen" << endl;
	}
	catch (...)
	{
		cout << "catch ..." << endl;
	}
}

int main()
{
	try{
		f();
	}
	catch (e1 e1)
	{
		cout << "main e1 exception" << endl;
	}
	catch (...)
	{
		cout << "main ... exception" << endl;
	}


	_getch();
	return 0;
}