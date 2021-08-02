#include <iostream>
#include <fstream>

#include "Player.h"

using namespace std;

int main()
{
	int totalPlayers = 1;
	int currentPlayers = 0;
	char Action[5];
	Player** database = new Player * [totalPlayers];
	for (int i = 0; i < totalPlayers; ++i)
	{
		database[i] = new Player();
	}

	while (true)
	{
		std::cout << "What would you like to do?" << std::endl;
		std::cout << "Add, View, Sort, Save, Load, Search, Quit" << std::endl;

		std::cin >> Action;
		if (strcmp(Action, "Add") == 0)
		{
			std::cout << totalPlayers << std::endl;
			database[currentPlayers]->SetName();
			database[currentPlayers]->SetHealth();
			totalPlayers = totalPlayers + 1;
			currentPlayers = currentPlayers + 1;
			
		};

		if (strcmp(Action, "View") == 0)
		{
			for (int i = 0; i < currentPlayers; ++i)
			{
				std::cout << "Name: " << database[i]->savedName << " Health: " << database[i]->savedHealth << std::endl;
			}

		};

		if (strcmp(Action, "Sort") == 0)
		{
			std::cout << "WIP" << std::endl;
			
		}

		//Save Function that saves the players information in binary
		if (strcmp(Action, "Save") == 0)
		{
			std::fstream file;
			file.open("Database.dat", std::ios_base::binary);
			if (file.is_open())
			{
				for (int i = 0; 1 < currentPlayers; ++i)
				{
					file.write((char*)database[i], sizeof(Player));
				}
				file.close();
			}
		}

		//Reads and prints the players profiles
		if (strcmp(Action, "Load") == 0)
		{
			std::fstream file;
			file.open("Database.txt", std::ios_base::in | std::ios_base::binary);
			if (file.is_open())
			{
				while (!file.eof() && file.peek() != EOF)
				{
					file.read((char*)database, sizeof(Player));
					std::cout << database[currentPlayers]->GetName() << "," << database[currentPlayers]->GetHealth() << std::endl;
				}
				file.close();
			}
		}

		if (strcmp(Action, "Search") == 0)
		{
			std::cout << "WIP";
		}

		if (strcmp(Action, "Quit") == 0)
		{
			exit(0);
		}

		system("pause");
		system("cls");
	}
	delete[] database;
	return 0;
}