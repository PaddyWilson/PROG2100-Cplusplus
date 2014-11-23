#include "World.h"
#include <conio.h>
#include <thread>         // std::this_thread::sleep_for
#include <chrono> 
#include <Windows.h>

int main()
{
	string a;
	World world;// = new World;

	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	bool run = true;

	while (run)
	{
		SetConsoleTextAttribute(hConsole, 15);//sets the console text color to white
		cout << "Number of Organisums: " << world.getCountOfObject(1)+world.getCountOfObject(2) << endl
			<< "Ants: " << world.getCountOfObject(1) << endl
			<< "Ant Lions: " << world.getCountOfObject(2) << endl
			<< "Round: " << world.getRound() << endl;
		cout << world;// << endl;
		//std::this_thread::sleep_for(std::chrono::seconds(1));//pauses the program for 1 second
		cin.get();
		//system("cls");//clears the console - bad for some resone
		
		//moves things in the world
		world.move();

		//checks if all of one of the species have died
		if (world.getCountOfObject(1) == 0 || world.getCountOfObject(2) == 0)
		{
			run = false;
			cout << "They All Died" << endl
				<< "What a shame" << endl;
			//break;
		}

	}
	cin.get();
	return 1;
}