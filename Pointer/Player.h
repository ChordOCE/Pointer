#pragma once

class Player
{
public:
	int GetHealth()
	{
		return health;
	}

	void SetHealth()
	{
		std::cout << "how much health do you have?" << std::endl;
		std::cin >> health;
		std::cout << "You have " << health << " Hit Points" << std::endl;
	}

	char GetName()
	{
		return name[64];
	}

	void SetName()
	{
		std::cout << "What is your characters name?" << std::endl;
		std::cin >> name;
		std::cout << "Your name is " << name << std::endl;
	}

	char name[64];
	int health;
};
