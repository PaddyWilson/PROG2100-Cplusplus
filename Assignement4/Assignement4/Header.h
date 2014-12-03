#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <vector>
#include <boost/filesystem.hpp>
#include <boost/regex.hpp>

using namespace std;

bool openFile(vector<string> &list, string filePath);
void changeFile(vector<string>& list, char find, string replace);
bool writeFile(vector<string> list, string name);

void removeChar(string& filePath, char a);