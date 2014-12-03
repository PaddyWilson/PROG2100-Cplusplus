#include "World.h"
#include <conio.h>
#include <thread>         // std::this_thread::sleep_for
#include <chrono> 
#include <Windows.h>//for console colours

int main()
{
	cout << "Running" << endl;
	string a;
	World world;// = new World;

	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	bool run = true;
	int i = 0;

	while (run)
	{
		i++;
		if (i % 1000 == 0)
		{
			cout << ".";
		}
		SetConsoleTextAttribute(hConsole, 15);//sets the console text color to white
		cout << "Number of Organisums: " << world.getCountOfObject(1) + world.getCountOfObject(2) << endl
			<< "Ants: " << world.getCountOfObject(1) << endl
			<< "Ant Lions: " << world.getCountOfObject(2) << endl
			<< "Round: " << world.getRound() << endl;
		cout << world;// << endl;
		//std::this_thread::sleep_for(std::chrono::milliseconds(1000));//pauses the program for .5 second
		//cin.get();
		system("cls");//clears the console - bad for some resone
		
		//moves things in the world
		world.move();

		//checks if all of one of the species have died
		if (world.getCountOfObject(1) == 0 || world.getCountOfObject(2) == 0)
		{
			SetConsoleTextAttribute(hConsole, 15);
			run = false;
			cout << "They All Died" << endl
				<< "What a shame" << endl
				<< "After " << world.getRound() << " rounds"<< endl;
			cout << world << endl;
			//break;
		}

	}
	cin.get();
	return 1;
}