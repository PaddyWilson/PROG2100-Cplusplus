#include "Student.h"
#include <conio.h>
#include <iostream>

#include <Windows.h>//OutputDebugString()

//default constuctor
Student::Student() :name(""), numCourses(0)
{
	cout << "**Default Contructor Fired**" << endl;
	this->courseList = new string[0];
}

//copy constructor
Student::Student(const Student& studentIn)
{
	cout << "**Copy Contructor Fired**" << endl;

	this->name = studentIn.name;//copy name
	this->numCourses = studentIn.numCourses;//copy numCourses

	//copy array courseList
	this->courseList = new string[numCourses + 1];
	for (int i = 0; i < this->numCourses; i++)
	{
		this->courseList[i] = studentIn.courseList[i];
	}
}

//deconstuctor
Student::~Student()
{
	cout << "**Decontructor Fired**" << endl;
	//clears the courseList array from RAM
	if (this->courseList != NULL)
	{
		delete[] this->courseList;
	}
}

//get the value for all the things
void Student::getValuesForEverything(string name, string *courseList, int numCourses)
{
	this->name = name;
	this->numCourses = numCourses;
	if (this->courseList != NULL)
	{
		delete[] this->courseList;
	}

	this->courseList = new string[this->numCourses];
	for (int i = 0; i < this->numCourses; i++)
	{
		this->courseList[i] = courseList[i];
	}
	
}

//resets 
//name to blank string
//numCourses to 0
//clears the courseList Array from RAM
void Student::resetEveryThing()
{
	name = "";
	numCourses = 0;
	if (this->courseList != NULL)
	{
		delete[] this->courseList;
	}
	courseList = new string[0];
}

//resets 
//numCourses to 0
//clears the courseList Array from RAM
void Student::resetCourses()
{
	numCourses = 0;
	if (this->courseList != NULL)
	{
		delete[] this->courseList;
	}
	courseList = new string[0];
}

//displayes
string Student::displayStudent()
{
	string output = "Name: " + name + "\n"
		+ "Number of Course: " + to_string(numCourses) + "\n"
		+ "Courses" + "\n";

	for (int i = 0; i < numCourses; i++)
	{
		output += courseList[i] + "\n";
	}
	return output;
}

ostream& operator<<(ostream& output, Student& studentIn)
{
	output << "Name: " << studentIn.name << endl 
			<< "Number of Course: " << studentIn.numCourses << endl
			<< "Courses:" << endl;

	for (int i = 0; i < studentIn.numCourses; i++)
	{
		output << studentIn.courseList[i] << endl;
	}

	return output;
}

Student Student::operator=(Student& studentIn)
{
	cout << "**operator = Fired**" << endl;
	this->name = studentIn.name;
	this->numCourses = studentIn.numCourses;

	this->courseList = new string[numCourses + 1];
	for (int i = 0; i < numCourses; i++)
	{
		this->courseList[i] = studentIn.courseList[i];
	}
	return *this;
}

//getter setter
string Student::getName()
{
	return name;
}
void Student::setName(string name)
{
	this->name = name;
}

int Student::getNumCourses()
{
	return numCourses;
}
void Student::setNumCourses(int numCourses)
{
	this->numCourses = numCourses;
}

string Student::getCourseList()
{
	return *courseList;
}
void Student::setCourseList(string *courseList)
{
	this->courseList = courseList;
}


