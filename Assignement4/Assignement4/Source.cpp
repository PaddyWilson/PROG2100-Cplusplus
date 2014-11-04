#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <vector>

#include <Windows.h>

using namespace std;

vector<string> openFile(string filePath);
void changeFile(vector<string>& list, char find, string replace);
void writeFile(vector<string> list);

//couts a vector<string>
void coutVector(vector<string> list)
{
	for (int i = 0; i < list.size(); i++)
	{
		cout << list.at(i) << endl;
	}
}

int main()
{
	// use double back slashes in files paths
	string filePath = "D:\\Google Drive\\NSCC\\PROG 2100 (C++)\\validation code.cpp";
	vector<string> list;

	cout << "opening file" << endl;
	list = openFile(filePath);

	cout << "Changing file" << endl;
	changeFile(list, '<', "&lt;");
	changeFile(list, '>', "&gt;");

	cout << "writing file" << endl;
	writeFile(list);

	cout << "Good Bye" << endl;
	
	_getch();
	return 0;
}//end main

//opens a file at the path provided
vector<string> openFile(string filePath)
{
	ifstream myfile;
	vector<string> list;
	string line;

	myfile.open(filePath);
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			getline(myfile, line);
			list.push_back(line);
		}
	}
	else{
		myfile.close();
		exit(1);//quits the program
	}

	//close file in streams
	myfile.close();

	return list;
}

//changes a char to some other thing
void changeFile(vector<string>& list, char find, string replaceString)
{
	for (int i = 0; i < list.size(); i++)
	{
		//replace
		for (int j = list.at(i).length() - 1; j >= 0; j--)
		{
			if (list.at(i).at(j) == find)
			{
				list.at(i).erase(j, 1);
				list.at(i).insert(j, replaceString);
			}
		}
	}
}

//writes a vector to a .html file
void writeFile(vector<string> list)
{
	ofstream outFile;
	outFile.open("out.html");

	//writes to a file
	outFile << "<PRE>" << endl;
	for (int i = 0; i < list.size(); i++)
	{
		outFile << list.at(i) << endl;
	}
	outFile << "</PRE>" << endl;

	outFile.close();
}

