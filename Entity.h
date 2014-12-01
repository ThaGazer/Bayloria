#ifndef _ENTITY_H
#define _ENTITY_H

#include <string>

using namespace std;

class Entity
{
private:
	int attackDam;
  int health;
	int totalHealth;
  int armor;
  int speed;
  string name;

public:
  Entity();
  Entity(int, int, int, int, int);
  int getHealth();
	int getTotalHealth();
  int getAttack();
  int getArmor();
  int getSpeed();
  string getName();
  void setName(string);
  void setSpeed(int);
  void setHealth(int);
	void setTotalHealth(int);
  void setAttack(int);
  void setArmor(int);
	void displayEntityStats(Entity);
};

#endif
