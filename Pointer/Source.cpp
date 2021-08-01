#include <iostream>

#include "Player.cpp"

int main()
{
	int amount;
	std::cout << "How Many Players Are There?" << std::endl;
	std::cin >> amount;
	if (amount)
	{
		Player Thing;
		Player** database = new Player * [amount];
		for (int i = 1; i <= amount; ++i)
		{
			database[i] = new Player();
			while (i <= amount)
			{
				database[i]->SetName();
				database[i]->SetHealth();
				break;
			}
			std::cout << database << std::endl;


		}
		delete database;
	}


	return 0;
}