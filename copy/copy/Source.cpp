	// ___ ___  ___  ___ _    ___ __  __   ___  ___  _ __   _____ _  _  ___
	//| _ \ _ \/ _ \| _ ) |  | __|  \/  | / __|/ _ \| |\ \ / /_ _| \| |/ __|
	//|  _/   / (_) | _ \ |__| _|| |\/| | \__ \ (_) | |_\ V / | || .` | (_ |
	//|_| |_|_\\___/|___/____|___|_|  |_| |___/\___/|____\_/ |___|_|\_|\___|
	//                    ___ ___  ___   ___ ___ ___ ___
	//                   | _ \ _ \/ _ \ / __| __/ __/ __|
	//                   |  _/   / (_) | (__| _|\__ \__ \
    //                   |_| |_|_\\___/ \___|___|___/___/


	//               YES   =============================   NO
	//        +-----------|| Does the Darn Thing work? ||-----------+
	//        |            =============================            |
	//        V                                                     V
	//   +----------+     +---------+                          +---------+
	//   |   Don't  |  NO |   Does  |       +-------+     YES  | Did you |
	//   |   mess   | +---|  anyone |<------|  YOU  |<---------|   mess  |
	//   | with it! | |   |  know?  |       | MORON |          | with it |
	//   +----------+ |   +---------+       +-------+          +---------+
	//        |       V        | YES                                |  NO
	//        |    +------+    +-----------+                        |
	//        |    | HIDE |                V                        V
	//        |    |  IT  |            +--------+             +-----------+
	//        |    +------+            |  YOU   |        YES  | WILL THEY |
	//        |       |       +------->|  POOR  |<------------| CATCH YOU?|
	//        |       |       |        |BASTARD!|             +-----------+
	//        |       |       |        |________|                   |  NO
	//        |       |       |             |                       |
	//        |       |       |             V                       V
	//        |       |       |      +---------------+        +-----------+
	//        |       |       |  NO  | CAN YOU BLAME |        |DESTROY THE|
	//        |       |       +------| SOMEONE ELSE? |        |  EVIDENCE |
	//        |       |              +---------------+        +-----------+
	//        |       |                     |  YES                  |
	//        |       |                     v                       |
	//        |       |      ============================           |
	//        |       +---->||           N O            ||<---------+
	//        +------------>||      P R O B L E M       ||
	//                       ============================

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>

using namespace std;

class String
{
private:
	char *member;

public:
	String()
	{
		cout << "default construtor" << endl;
		this->member = NULL;
	}

	String(char *stringIn)
	{	
		cout << "string in construtor" << endl;
		int length = strlen(stringIn);//get length of string
		this->member = new char[length + 1];
		strcpy(this->member, stringIn);
	}

	String(const String& stringIn)
	{
		cout << "copy construtor" << endl;
		int length = strlen(stringIn.member);//get length of string
		this->member = new char[length + 1];
		strcpy(this->member, stringIn.member);
	}

	~String()
	{
		cout << "destrutor" << endl;
		if (this->member != NULL)
		{
			delete[] this->member;
			//delete this->member;//not this for arrarys
		}
	}

	String operator=(String& string)
	{
		cout << "=" << endl;
		int len = strlen(string.member);
		this->member = new char[len + 1];
		strcpy(this->member, string.member);
		return *this; 
//IMPORTANT -'[;/p00.olikujhy76gtv5fr4c45vhy67nujm8iol9pol.,iuj7yh6gtrf45v g6y7nu89ikujyhgtrfedcrfvtby7u8iukjyhngtrfedcw evrtyu'
	}

};

int main()
{
	String str = "hi";
	_getch();
	return 47;
}