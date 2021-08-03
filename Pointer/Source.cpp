#include <iostream>
#include <fstream>
#include <cstdlib>

#include "Player.h"

using namespace std;

int main()
{
	int maxPlayers = 100;
	int currentPlayers = 0;

	char Action[5];
		
	Player** database = new Player * [maxPlayers];
	for (int i = 0; i < maxPlayers; ++i)
	{
		database[i] = new Player();
	}
	int count = sizeof(database) / sizeof(Player);

	while (true)
	{
		std::cout << "What would you like to do?" << std::endl;
		std::cout << "Add, View, Sort, Save, Load, Search, Quit" << std::endl;

		std::cin >> Action;
		if (strcmp(Action, "Add") == 0)
		{
			std::cout << "Player Number: " << currentPlayers + 1 << std::endl;
			database[currentPlayers]->SetName();
			database[currentPlayers]->SetHealth();

			maxPlayers = maxPlayers + 1;
			currentPlayers = currentPlayers + 1;
			
		};

		if (strcmp(Action, "View") == 0)
		{
			for (int i = 0; i < currentPlayers; ++i)
			{
				std::cout << "Player " << i + 1 << std::endl << "Name: " << database[i]->savedName << std::endl << "Health: " << database[i]->savedHealth << std::endl;
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
			file.open("Database.txt", std::ios::out | std::ios_base::binary);
			if (file.is_open())
			{
				for (int i = 0; 1 < count; ++i)
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
			file.open("Database.dat", std::ios_base::in | std::ios_base::binary);
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