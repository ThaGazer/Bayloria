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
  std::string name;

public:
  Entity();
  Entity(int, int, int, double);
  int getHealth();
  int getAttack();
  int getArmor();
  double getSpeed();
  std::string getName();
  void setName(string);
  void setSpeed(double);
  void setHealth(int);
  void setAttack(int);
  void setArmor(int);
};

class Player : public Entity
{
private:
  static const int INVENTORY_MAX = 30;
  bool inventory[INVENTORY_MAX];
  std::string inventoryString[INVENTORY_MAX];

public:
  Player();
  Player(int, int, int, double, std::string, bool [], std::string []);
  void getInventory();
  void setInventory(bool [], std::string []);
  void addItemToInventory(int);
  
};

void instructions();
void loc1();
void loc2();
void loc3();
void loc4();

void attack(Player, Entity);

#endif
