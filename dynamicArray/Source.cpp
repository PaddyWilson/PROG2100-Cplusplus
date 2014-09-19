
#include <iostream>
#include <string>
#include <conio.h>
#include <iostream>

using namespace std;

int main()
{
	int myArray[10];//fixed array
	//int size  = 0;
	const int SIZE = 10;

	//cout << "Enter array size: ";
	//cin >> size;
	
	//int anArray[size];//error must have a const value
	//int anArray[SIZE];

	//int size = 10;
	//cout << "Enter array size: ";
	//cin >> size;
	//int *p;
	//p = new int[size];//declare array dynamically - on heap

	//const int MAX = 5;
	//int nonD[MAX];
	//int c = 0;

	//cout << "enter a number (int)";
	////cin >> c;
	////nonD[10] = c;
	//while (cin >> nonD[c])
	//{
	//	c++;
	//	if (c > 5)
	//	{
	//		cout << c << " elemant used" << " Max is:" << MAX << endl;
	//	}
	//	else
	//	{
	//		cout << "At max - next will exceed array size" << endl;
	//	}
	//	cout << "Enter an interger ";
	//	for (int i = 0; i < 5; i++)
	//	{
	//		cout << nonD[i] << endl;
	//	}
	//}

	//dynamically make arrays
	//starts with small array and get bigger
	//it is only limited by the amount of ram you have. although array and pointer syntax have the same effect for clarity, use the pointer notation when passing an array

	int max = 5;
	int *dyArray = new int[max];
	int c = 0;
	//read into array
	//cout << "enter an interger: " << endl;
	while (true)
	{
		c++;
		if (c >= max)//if array is full
		{
			max = max * 2;
			int *temp  = new int[max];
			for (int i = 0; i < c; i++)
			{
				temp[i] = dyArray[i];
			}
			//don't forget to do this
			delete []dyArray;
			//assign address of temp to dyArray
			dyArray = temp;
		}
		cout << "array size is " << max << ". " << max -c << " elements left."<< endl;
		//cout << "enter an int: ";


	}
	_getch();
	return 0;
}
