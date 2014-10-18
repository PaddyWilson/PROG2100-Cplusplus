#include "Student.h"
#include <conio.h>
#include <iostream>

//default constuctor
Student::Student() :name(""), numCourses(0)
{
	this->courseList = new string[0];
}

//copy constructor
Student::Student(const Student& studentIn)
{
	this->name = studentIn.name;
	this->numCourses = studentIn.numCourses;

	this->courseList = new string[numCourses + 1];
	for (int i = 0; i < numCourses; i++)
	{
		this->courseList[i] = studentIn.courseList[i];
	}
}

//deconstuctor
Student::~Student()
{
	if (this->courseList != NULL)
	{
		delete[] this->courseList;
	}
}

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

//resets the 
void Student::reset()
{
	name = "";
	numCourses = 0;
	if (this->courseList != NULL)
	{
		delete[] this->courseList;
	}
	courseList = new string[0];
}

void Student::resetCourses()
{
	numCourses = 0;
	if (this->courseList != NULL)
	{
		delete[] this->courseList;
	}
	courseList = new string[0];
}

void Student::displayStudent()
{
	cout << "Name: " << name << endl
		<< "Number of Course: " << numCourses << endl
		<< "Courses" << endl;

	for (int i = 0; i < numCourses; i++)
	{
		cout << courseList[i] << endl;
	}
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


