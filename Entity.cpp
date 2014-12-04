#include "Entity.h"
#include <iostream>
#include <string>

Entity::Entity()
{
  name = "Justin Crawford";
  attackDam = 0;
	totalHealth = 0;
  health = 0;
  armor = 0;
  speed = 0;
}

Entity::Entity(int att, int heal, int totHeal, int arm, int spe)
{
  attackDam = att;
  health = heal;
	totalHealth = totHeal;
  armor = arm;
  speed = spe;
}

int Entity::getHealth()
{
  return health;
}

int Entity::getTotalHealth()
{
	return totalHealth;
}

int Entity::getAttack()
{
  return attackDam;
}

int Entity::getArmor()
{
  return armor;
}

int Entity::getSpeed()
{
  return speed;
}

string Entity::getName()
{
  return name;
}

void Entity::setName(string nam)
{
  name = nam;
}
void Entity::setSpeed(int spe)
{
  speed = spe;
}

void Entity::setHealth(int heal)
{
  health = heal;
}

void Entity::setTotalHealth(int totHeal)
{
	totalHealth = totHeal;
}

void Entity::setAttack(int att)
{
  attackDam = att;
}

void Entity::setArmor(int arm)
{
  armor = arm;
}

void Entity::displayEntityStats(Entity entity)
{
	cout << "___________________\n";
	cout << "\nName: " << entity.getName() << "\nAttack: " << entity.getAttack()
			<< "\nHealth: " << entity.getHealth() << "/" << entity.getTotalHealth()
			<< "\nArmor: " << entity.getArmor() << "\nSpeed: " << entity.getSpeed()
			<< endl;
	cout << "___________________\n";
}
