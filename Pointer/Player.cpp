#include <iostream>
#include "Player.h"


int Player::GetHealth()
{
	return health;
}

char Player::GetName()
{
	return name[64];
}

void Player::SetHealth()
{
	std::cout << "how much health do you have?" << std::endl;
	std::cin >> health;
	std::cout << "You have " << health << " Hit Points" << std::endl;
}

void Player::SetName()
{
	std::cout << "What is your characters name?" << std::endl;
	std::cin >> name;
	std::cout << "Your name is " << name << std::endl;
}
