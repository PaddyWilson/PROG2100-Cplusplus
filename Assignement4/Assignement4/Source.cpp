#include "Header.h"

int main()
{
	// use double back slashes in files paths
	string filePath;// = "D:\Google Drive\NSCC\PROG 2100\validation code.cpp";
	string outFileName;
	vector<string> list;//stores the inputed file for manipulation

	boost::regex regex("([^\s]+(\.(?i)(cpp))$)");

	//get 
	int t = 0;
	cout << "Enter a file along with its path" << endl << "ie. C:\\test\\test.cpp" << endl;
	do
	{
		if (t == 1)
		{
			cout << "Enter a valid file" << endl;
		}
		getline(cin, filePath);//gets the file path
		removeChar(filePath, '"');//removes the " from the file path
		t = 1;
	} while (!boost::filesystem::exists(filePath) && !boost::regex_search(filePath, regex) );//needs a .cpp file extention and a file that exists
	
	t = 0;
	//gets file outout name
	cout << "Enter a file name for output" << endl;
	do
	{
		if (t==1)
		{
			cout << "Enter a valid file name" << endl;
		}
		getline(cin, outFileName);
		//validation for file names
		if (outFileName == "")
			t = 1;
		else
			t = 0;
	} while (t == 1);

	//opens the file and stores it in a vector
	cout << "opening file" << endl;
	if (!openFile(list, filePath))
	{//if fails
		cout << "Failed to open file" << endl << "Good By" << endl;
		_getch();
		return 1;
	}

	//changes < to &lt; and > to &gt;
	cout << "Changing file" << endl;
	changeFile(list, '<', "&lt;");
	changeFile(list, '>', "&gt;");

	//writes the vector to a file
	cout << "writing file" << endl;
	if (!writeFile(list, outFileName))
	{//if fails
		cout << "Failed to write file" << endl << "Good By" << endl;
		_getch();
		return 2;
	}

	cout << "Good Bye" << endl;
	
	_getch();
	return 0;
}//end main

//removes a char from a string
void removeChar(string& filePath, char a)
{
	for (int j = filePath.length() - 1; j >= 0; j--)
		if (filePath.at(j) == a)
			filePath.erase(j, 1);
}

//opens a file at the path provided
bool openFile(vector<string>& list, string filePath)
{
	ifstream myfile;
	//vector<string> list;
	string line;

	myfile.open(filePath);
	if (myfile.fail())//if the file failed to open
	{
		myfile.close();//close file in streams
		return false;
	}

	try{
		while (!myfile.eof())
		{
			getline(myfile, line);//reads 1 line of file
			list.push_back(line);//stores line in list vector
		}
	} 
	catch (exception e){
		myfile.close();//close file in streams
		e.what();
		return false;
	}

	//close file in streams
	myfile.close();

	return true;
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

//writes a vector to a .html file with <PRE> at start and </PRE> at end
bool writeFile(vector<string> list, string name)
{
	ofstream outFile;
	outFile.open(name + ".html");

	if (outFile.fail())//if the file failed to open
	{
		outFile.close();//close file in streams
		return false;
	}

	try{
		//writes to a file
		outFile << "<PRE>" << endl;
		for (int i = 0; i < list.size(); i++)
		{
			outFile << list.at(i) << endl;
		}
		outFile << "</PRE>" << endl;
	}
	catch (exception e){
		outFile.close();//close file in streams
		e.what();
		return false;
	}

	outFile.close();
	return true;
}

