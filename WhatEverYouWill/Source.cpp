//Topic: Arrays 1D,2D, array args,identifiers
//Note: passing arrays in C++ by value isn't possible. You may instead
//use a vector. If you want to do this because you want the array to be
//copied for you, this is unfortunatly not possible with C++ arrays so you
//just have to copy it yourself.

//Note: for clarity, use pointer notation when passing an array

#include <iostream>
#include <conio.h>
using namespace std;



//int main()
//{
//
//
//
//	//1D Array solution
//	//int a[3]; //declare and empty 1D array
//	//a[0] = 0;
//	//a[1] = 1;
//	//a[2] = 2;
//
//	//int b[] = { 0, 1, 2 };//declare and fill array
//
//	//for (int row = 0; row < 3; row++)
//	//{
//	//	cout << b[row] << endl;
//	//}
//	//_getch();
//
//	//2D Array Example
//
//	//int my2Darray[][3] = { { 0, 100, 200 }, { 1, 300, 400 }, { 2, 500, 600 } };
//
//	//for (int row = 0; row < 3; row++){
//	//	for (int col = 0; col < 3; col++)
//	//	{
//	//		cout << my2Darray[row][col];
//	//		if (col < 2)
//	//			cout << ", ";
//	//		else
//	//			cout << endl;
//	//	}//end col for
//	//}//end row for
//
//	int a[] = { 1, 2, 3 };//declare 1D array
//	int *p;//create a pointer
//	p = a;//make pointer point to array
//
//	//addTen(a, 3);//call sending array name and size
//	addTen(p, 3);//call sending pointer to array and size
//
//	for (int row = 0; row < 3; row++)
//	{
//		cout << a[row] << endl;
//	}
//
//
//	_getch();
//	return 0;
//}//end main

//void addTen(int *p, int size)//array passed via pointer
//{
//	for (int row = 0; row < 3; row++)
//	{
//		p[row] += 10;
//	}
//}

//prototypes
void addTen(int *p, int);

void addTen(int *p, int size)//array passed using and array arg
{
	for (int row = 0; row < size; row++)
	{
		p[row] += 10;
	}
}

void addTen2(int *p, int size)//array passed using and array arg
{
	for (int row = 0; row < size; row++)
	{
		p[row] += 10;
	}
}

int main()
{
	////1d array example
	//int a[] = {0, 1, 2};

	//for (int i = 0; i < 3; i++)
	//{
	//	cout << a[i] << endl;
	//}

	//2d array example
	/*int a[][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};

	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			cout << a[row][col];
			if (col < 2)
				cout << ", ";
			else
				cout << endl;
		}
	}
*/

	int a[] = {1, 2, 3};
	int *p;
	p = a;
	
	for (int i = 0; i < 3; i++)
	{
		cout << a[i] << endl;
	}

	addTen(p, 3);

	for (int i = 0; i < 3; i++)
	{
		cout << a[i] << endl;
	}


	_getch();
	return 0;
}
