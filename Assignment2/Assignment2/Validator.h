//this validation prevents the user from crashing your program
//using input such as 'ctrl z'

#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

class Validator
{
public:
	bool inputMechanism(string* inputString);
};//end class