#pragma once

class Player
{
public:
	int GetHealth();

	void SetHealth();

	char GetName();

	void SetName();

private:
	char name[64];
	int health;
};
