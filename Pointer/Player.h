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
		std::cin >> savedHealth;
		std::cout << "You have " << savedHealth << " Hit Points" << std::endl;
	}

	char* GetName()
	{
		return savedName;
	}

	void SetName()
	{
		std::cout << "What is your characters name?" << std::endl;
		std::cin >> savedName;
		std::cout << "Your name is " << savedName << std::endl;
	}

	char savedName[64];
	int savedHealth;
};
