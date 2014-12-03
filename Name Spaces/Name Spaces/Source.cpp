//a namespace is a collection of class definitions
//and variable declarations (aka name definitions).
//The std namespace contains all the names defined
//in many standard C++ library files such as
//<iostream>. #include <iostream> places all the name
//definitions for names such as cin and cout into
//the std namespace. You must use the 'using namespace'
//directive to establish the link between your program
// and the definitions you have placed in it.


#include <iostream>
#include <conio.h>

using namespace std;

namespace NS1
{
	int square(int a);
}

namespace NS2
{
	int square(int a);
}

namespace NS1
{
	int square(int a)
	{
		return a * a;
	}
}

namespace NS2
{
	int square(int a)
	{
		return a + a;
	}
}

int main()
{
	int answer;
	{
		using namespace NS1;
		answer = square(3);
		cout << answer << endl;
	}
	{
		using namespace NS2;
		answer = square(3);
		cout << answer << endl;
	}


	_getch();
	return 0;
}

