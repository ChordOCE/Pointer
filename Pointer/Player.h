#pragma once

class Player
{
public:
	int GetHealth()
	{
		return savedHealth;
	}

	void SetHealth()
	{
		std::cout << "how much health do you have?" << std::endl;
		std::cin >> health;
		savedHealth = health;
		std::cout << "You have " << health << " Hit Points" << std::endl;
	}

	char GetName()
	{
		return savedName[64];
	}

	void SetName()
	{
		std::cout << "What is your characters name?" << std::endl;
		std::cin >> name;
		savedName[64] = name;
		std::cout << "Your name is " << savedName << std::endl;

	}

	char savedName[64];
	char name;
	int health;
	int savedHealth;
};
