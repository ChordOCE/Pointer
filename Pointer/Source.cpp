#include <iostream>
#include <fstream>

#include "Player.h"

using namespace std;

int main()
{
	int CurrentPlayers = 0;
	char Action[5];
	char Add[4];
	char Sort[4];
	char Save[64];
	char Load[64];
	char Search[64];
	Player** database = new Player * [CurrentPlayers];
	std::cout << "What would you like to do?" << std::endl;
	std::cout << "Add, Sort, Save, Load, Search" << std::endl;

	std::cin >> Action;
	while (true)
	{
		if (strcmp(Action, "Add") == 0)
		{
			system("cls");
			std::cout << CurrentPlayers << std::endl;
			database[CurrentPlayers]->SetName();
			database[CurrentPlayers]->SetHealth();
			CurrentPlayers + 1;
			break;
		};

		if (strcmp(Action, "Sort") == 0)
		{
			std::cout << "WIP" << std::endl;
			break;
		}

		if (strcmp(Action, "Save") == 0)
		{
			std::fstream file;
			file.open("Database.txt", std::ios_base::binary);
			if (file.is_open())
			{
				for (int i = 0; 1 < CurrentPlayers; ++i)
				{
					file.write((char*)database[i], sizeof(Player));
				}
				file.close();
			}
		}

		if (strcmp(Action, "Load") == 0)
		{
			std::fstream file;
			file.open("Database.txt", std::ios_base::in | std::ios_base::binary);
			if (file.is_open())
			{
				while (!file.eof() && file.peek() != EOF)
				{
					file.read((char*)database, sizeof(Player));
					std::cout << database[CurrentPlayers]->name << "," << database[CurrentPlayers]->health << std::endl;
				}
				file.close();
			}
		}

		if (strcmp(Action, "Search") == 0)
		{
			std::cout << "WIP";
		}
	}
	delete[] database;
	return 0;
}