/*
  Author:         Justin Ritter, Cole Crawford, Nannan
  Title:          Bayloria
  Descriptions:   Text base game. There are 4 main lvls to the map.
                  In each lvl there is a boss and once you defeat the boss
                  you get a special key. There are 4 other keys hidden on the lvl
                  that are need to get intot the boss room. At the 4th lvl
                  all 20 room keys are need to fight the ultimate boss.
                  Once you defeat him you win the game.
  Date Created:   10/23/2014
*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>

using namespace std;

class Entity
{
private:
	int attackDam;
  int health;
  int armor;
  double speed;
  string name;

public:
  Entity();
  Entity(int, int, int, double);
  int getHealth();
  int getAttack();
  int getArmor();
  double getSpeed();
  string getName();
  void setName(string);
  void setSpeed(double);
  void setHealth(int);
  void setAttack(int);
  void setArmor(int);
};

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
  Player(int, int, int, double, string, int, bool [], string [], int [], string [], int []);
	int getGold();
	void setGold(int);
	void getInventory();
	void setInventory(bool [], string [], int [], string [], int []);
	void addItemToInventory(int);
  
};

void instructions();
void loc1();
void loc2();
void loc3();
void loc4();

void attack(Player, Entity);
void store(Player);

void createWizard(Entity);
void createKnight(Entity);
void createArcher(Entity);

void createPrimusRatticus(Entity);
void createSecondusSerpent(Entity);
void createStagOfTertius(Entity);
void createLordFarquaad(Entity);

#endif
