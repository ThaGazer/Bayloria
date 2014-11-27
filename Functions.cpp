/*
  Author:         Justin Ritter, Cole Crawford, Nannan
  Title:          Bayloria
  Descriptions:   Text base game. There are 4 main lvls to the map.
                  In each lvl there is a boss and once you defeat the boss
                  you get a special key. There are 4 other keys hidden on
                  the lvl that are need to get intot the boss room.
                  At the 4th lvl all 20 room keys are need to fight
                  the ultimate boss. Once you defeat him you win the game.
  Date Created:   10/23/2014
*/

#include <string>
#include <iostream>
#include "Functions.h"

using namespace std;

Entity::Entity()
{
  name = "Justin Crawford";
  attackDam = 0;
  health = 0;
  armor = 0;
  speed = 0;
}

Entity::Entity(int att, int heal, int arm, double spe)
{
  attackDam = att;
  health = heal;
  armor = arm;
  speed = spe;
}

int Entity::getHealth()
{
  return health;
}

int Entity::getAttack()
{
  return attackDam;
}

int Entity::getArmor()
{
  return armor;
}

double Entity::getSpeed()
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
void Entity::setSpeed(double spe)
{
  speed = spe;
}

void Entity::setHealth(int heal)
{
  health = heal;
}

void Entity::setAttack(int att)
{
  attackDam = att;
}

void Entity::setArmor(int arm)
{
  armor = arm;
}

Player::Player()
{
  setName("Bob The Slayer");
  setAttack(0);
  setHealth(0);
  setArmor(0);
  setSpeed(0);

	// initializes the arrays to false for the bool and empty space for the strings
	for (int i = 0; i < INVENTORY_MAX; i++)
	{
		inventory[i] = false;
	}

	//inventoryString[INVENTORY_MAX] = {"sword", 
}

Player::Player(int att, int heal, int arm, double spe, string nam, bool inv[], string invStr[])
{
  setName(nam);
  setAttack(att);
  setHealth(heal);
  setArmor(arm);
  setSpeed(spe);
	setInventory(inv, invStr);
}

void Player::getInventory()
{
	for (int i = 0; i < INVENTORY_MAX; i++)
	{
		cout << inventory[i] << endl;
	}

	cout << "invstr" << endl;

	for (int i = 0; i < INVENTORY_MAX; i++)
	{
		if (inventory[i] == true)
		{
			cout << inventoryString[i] << endl;
		}
	}
}

void Player::setInventory(bool inv[], string invStr[])
{
	for (int i = 0; i < INVENTORY_MAX; i++)
	{
		inventory[i] = inv[i];
		inventoryString[i] = invStr[i];
	}
}

void Player::addItemToInventory(int itemNumber)
{
	for (int i = 0; i < (itemNumber - 1); i++)
	{
		inventory[i] = true;
		/*if (inventoryString[i] == "sword")
		{
			attackDam += 10;
		}*/
		//else if (inventory[i] == "
	}
}

void instructions()
{
  cout <<  "\nThe point of the game is to defeat all four of the main "
              "bosses\n and progress through the 4 levels of Bayloria\n"
              "To play the game all you have to do is enter the four numbers\n"
              "that relate to the door you want to go through\n"
              "1 to go up, 2 to go down, 3 to go right, and 4 to go right\n"
              "Certain door will be locked, you can unlock these doors\n"
              "but only if you find the door keys"
              "There are treasure chest that are placed throughout the 4 maps\n"
              "They also have keys that are spread throughout the map\n"
              "You must collect all 4 items on the floor then kill the Boss\n"
              "on the floor and receive item of the floor\n"
              "To finish the game you must kill the final Boss and present\n"
              "all 20 items collect throughout the game.\n\n";
}

void loc1()
{
  int locRoom1 = 1;
  int direct = 0;

  cout << "Map loc 1\n";
  while(locRoom1 < 6)
  {
    switch(locRoom1)
    {
      case 1:;
        cout << "Room 1\n";
        cout << "Which direction would you like to move?\n";
        cin >> direct;
        while(direct != 4)
        {
          cout << "That door is closed\n";
          cin >> direct;
        }
        if(direct == 4)
           locRoom1++;
      break; //locRoom1 1

      case 2:;
        cout << "Room 2\n";
        cout << "Which direction would you like to move?\n";
        while(direct != 4)
        {
          cout << "That door is closed\n";
          cin >> direct;
        }
        if(direct == 4)
           locRoom1++;
      break; //locRoom1 2

      case 3:;
        cout << "Room 3\n";
        locRoom1++;
      break; //locRoom1 3

      case 4:;
        cout << "Room 4\n";
        locRoom1++;
      break; //locRoom1 4

      case 5:;
        cout << "Room 5\n";
        locRoom1++;
      break; //locRoom1 5
    } //swtich locRoom1
  } //while locRoom1
}

void loc2()
{
  int locRoom2 = 1;
  int direct = 0;

  cout << "Map loc 2\n";
  while(locRoom2 < 9)
  {
    switch(locRoom2)
    {
      case 1:;
        cout << "Room 1\n";
        locRoom2++;
      break; //locRoom2 1

      case 2:;
        cout << "Room 2\n";
        locRoom2++;
      break; //locRoom2 2

      case 3:;
        cout << "Room 3\n";
        locRoom2++;
      break; //locRoom2 3

      case 4:;
        cout << "Room 4\n";
        locRoom2++;
      break; //locRoom2 4

      case 5:;
        cout << "Room 5\n";
        locRoom2++;
      break; //locRoom2 5

      case 6:;
        cout << "Room 6\n";
        locRoom2++;
      break; //locRoom2 6

      case 7:;
        cout << "Room 7\n";
        locRoom2++;
      break; //locRoom2 7

      case 8:;
        cout << "Room 8\n";
        locRoom2++;
      break; //locRoom2 8
    } //swtich locRoom2
  } //while locRoom2
}

void loc3()
{
  int locRoom3 = 1;
  int direct = 0;

  cout << "Map loc 3\n";
  while(locRoom3 < 12)
  {
    switch(locRoom3)
    {
      case 1:;
        cout << "Room 1\n";
        locRoom3++;
      break; //locRoom3 1

      case 2:;
        cout << "Room 2\n";
        locRoom3++;
      break; //locRoom3 2

      case 3:;
        cout << "Room 3\n";
        locRoom3++;
      break; //locRoom3 3

      case 4:;
        cout << "Room 4\n";
        locRoom3++;
      break; //locRoom3 4

      case 5:;
        cout << "Room 5\n";
        locRoom3++;
      break; //locRoom3 5

      case 6:;
        cout << "Room 6\n";
        locRoom3++;
      break; //locRoom3 6

      case 7:;
        cout << "Room 7\n";
        locRoom3++;
      break; //locRoom3 7

      case 8:;
        cout << "Room 8\n";
        locRoom3++;
      break; //locRoom3 8

      case 9:;
        cout << "Room 9\n";
        locRoom3++;
      break; //locRoom3 9

      case 10:;
        cout << "Room 10\n";
        locRoom3++;
      break; //locRoom3 10

      case 11:;
        cout << "Room 11\n";
        locRoom3++;
      break; //locRoom3 11
    } //swtich locRoom3
  } //while locRoom3
}

void loc4()
{
  int locRoom4 = 1;
  int direct = 0;

  cout << "Map loc 4\n";
  while(locRoom4 < 15)
  {
    switch(locRoom4)
    {
      case 1:;
        cout << "Room 1\n";
        locRoom4++;
      break; //locRoom4 1

      case 2:;
        cout << "Room 2\n";
        locRoom4++;
      break; //locRoom4 2

      case 3:;
        cout << "Room 3\n";
        locRoom4++;
      break; //locRoom4 3

      case 4:;
        cout << "Room 4\n";
        locRoom4++;
      break; //locRoom4 4

      case 5:;
        cout << "Room 5\n";
        locRoom4++;
      break; //locRoom4 5

      case 6:;
        cout << "Room 6\n";
        locRoom4++;
      break; //locRoom4 6

      case 7:;
        cout << "Room 7\n";
        locRoom4++;
      break; //locRoom4 7

      case 8:;
        cout << "Room 8\n";
        locRoom4++;
      break; //locRoom4 8

      case 9:;
        cout << "Room 9\n";
        locRoom4++;
      break; //locRoom4 9

      case 10:;
        cout << "Room 10\n";
        locRoom4++;
      break; //locRoom4 10

      case 11:;
        cout << "Room 11\n";
        locRoom4++;
      break; //locRoom4 11

      case 12:;
        cout << "Room 12\n";
        locRoom4++;
      break; //locRoom4 12

      case 13:;
        cout << "Room 13\n";
        locRoom4++;
      break; //locRoom4 13

      case 14:;
        cout << "Room 14\n";
        locRoom4++;
      break; //locRoom4 14
    } //swtich locRoom4
  } //while locRoom4
}

void attack(Player player, Entity entity)
{
	while(player.getHealth() > 0 && entity.getHealth() > 0)
	{
		int healthEnemy = entity.getHealth();
		int yourHealth = player.getHealth();

		if (player.getSpeed() > entity.getSpeed())
		{
			cout << "You attack first!" << endl;
			entity.setHealth(healthEnemy -= player.getAttack() - entity.getArmor());
		}
		else
		{
			cout << "The enemy was quicker! It attacks you first!" << endl;
			player.setHealth(yourHealth -= entity.getAttack() - player.getArmor());
		}
	}
}
