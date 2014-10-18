#include <iostream>
#include <conio.h>
#include <stdlib.h>

#include "Student.h"

using namespace std;

string getInput();
void display(string *courseList, int max);

int main()
{
	//never said it had to end
	while (true)
	{
		Student student1;
		string input;
		string name;

		//get name for student1
		cout << "Enter 1st students name" << endl;
		name = getInput();

		//get courses
		int max = 1;
		string *courseList = new string[max];
		int c = 0;
		do
		{
			if (c >= max) //if array is full make larger
			{
				max = max + 1;
				string *temp = new string[max];//create temp array
				for (int i = 0; i < c; i++)
				{
					temp[i] = courseList[i];//write original to temp
				}

				delete[]courseList; //delete original smaller array
				courseList = temp; //switch pointer to larger temp array
			}//end if

			cout << "Enter a courses for first student" << endl;
			courseList[c] = getInput();

			cout << "Are You Done? y/n" << endl;
			input = getInput();
			c++;
		} while (input != "y");

		student1.getValuesForEverything(name, courseList, c);
		//done getting course

		//dispaly student 1 information
		cout << "1st student’s Information" << endl;
		cout << student1 << endl;

		//enter name for student 2
		cout << "Enter 2nd student’s name" << endl;
		name = getInput();
		Student student2 = student1;//copys info from student 1 to 2
		student2.setName(name);//sets students 2 name to the name entered

		//displays student 2 info
		cout << "2nd student’s Information" << endl;
		cout << student2 << endl;

		//display student 1 info after reset
		cout << "1st student’s Information" << endl;
		student1.resetCourses();
		cout << student1 << endl;

		cout << endl;
		cout << "****************************************************" << endl;
		cout << endl;
	}//repeat forever
	_getch();
}

//gets input
//won't return input if nothing entered
string getInput()
{
	string input;
	do
	{
		getline(cin, input);
	} while (input.length() == 0);//done return if blank string
	return input;
}

void display(string *courseList, int max)
{
	for (int i = 0; i < max; i++)
	{
		cout << "Course entered so far: " << courseList[i] << endl;
	}
}
