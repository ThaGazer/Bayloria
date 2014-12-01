#ifndef _PLAYER_H
#define _PLAYER_H

#include "Entity.h"
#include <string>

class Player : public Entity
{
private:
	static const int INVENTORY_MAX = 25;
	int gold;

	bool inventory[INVENTORY_MAX];
	string inventoryString[INVENTORY_MAX];
	int inventoryStats[INVENTORY_MAX + 1];
	string inventoryType[INVENTORY_MAX + 1];
	int inventoryNum[INVENTORY_MAX];

public:
  Player();
  Player(int, int, int, int, int, string, int, bool [], string [], int [], string [], int []);
	int getGold();
	void setGold(int);
	void addGold(Player &, int);
	void subtGold(Player &, int);
	void getInventory(Player &);
	void setInventory(bool [], string [], int [], string [], int []);
	void addItemToInventory(int, Player &);

	string getInventoryString(int);
	int sumInventory();
	void displayPlayerStats(Player);
};

#endif
