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
	int k = 10;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//// you can loop k higher to see more color choices
	//for (k = 1; k < 255; k++)
	//{
	//	// pick the colorattribute k you want
	//	SetConsoleTextAttribute(hConsole, k);//15 is white text black background
	//	cout << k << " I want to be nice today!" << endl;
	//}

	//cin.get(); // wait

	while (true)
	{
		SetConsoleTextAttribute(hConsole, 15);
		cout << "Number of Organisums: " << world.getCountOfObject(1)+world.getCountOfObject(2) << endl
			<< "Ants: " << world.getCountOfObject(1) << endl
			<< "Ant Lions: " << world.getCountOfObject(2) << endl
			<< "Round: " << world.getRound() << endl;
		cout << world;// << endl;
		//std::this_thread::sleep_for(std::chrono::seconds(1));//pauses the program for 1 second
		cin.get();
		//system("cls");//clears the console - bad for some resone
		
		//moves things
		world.move();
	}
	_getch();
	return 1;
}