#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

int main()
{
	string line;

	string filePath;
	string fileName;

	ifstream myfile;
	ofstream outFile;
	outFile.open("out.html");

	cout << "What file would you like to open?" << endl;
	getline(cin, filePath);
	myfile.open(filePath);


	if (myfile.is_open())
	{
		cout << "Opened file" << endl;
		outFile << "<PRE>" << endl;
		while (!myfile.eof())
		{
			getline(myfile, line);
			
			//replace < and >
			for (int i = 0; i < line.length(); i++)
			{
				try
				{
					line.replace(line.find("<"), sizeof("<") - 1, "&lt;");
					line.replace(line.find(">"), sizeof(">") - 1, "&gt;");
				}
				catch (exception e)
				{

				}
			}
			outFile << line << endl;
			cout << line << endl;
		}
		outFile << "</PRE>" << endl;
	}
	else 
		cout << "Unable to open file" << endl << "Good Bye" << endl;
	
	//close file in out streams
	myfile.close();
	outFile.close();
	
	_getch();
	return 0;
}//end main


