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

#include "Functions.h"
#include <string>
#include <iostream>
#include <time.h>

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
	setGold(0);

	// initializes the arrays to false for the bool and empty space for the strings
	for (int i = 0; i < INVENTORY_MAX; i++)
	{
		inventory[i] = false;
	}

	for (int i = 0; i < INVENTORY_MAX; i++)
	{
		inventoryNum[i] = i + 1;
	}

	inventoryString[0] = "Basic Sword";
	inventoryStats[0] = 10; // atk
	inventoryType[0] = "attack";
	inventoryString[1] = "Leather Chest Plate";
	inventoryStats[1] = 2; // armor
	inventoryType[1] = "armor";
	inventoryString[2] = "Right Pinky Ring";
	inventoryStats[2] = 5; // health
	inventoryType[2] = "health";
	inventoryString[3] = "Right Ringfinger Ring";
	inventoryStats[3] = 5; // health
	inventoryType[3] = "health";
	inventoryString[4] = "Master Key";
	inventoryStats[4] = 5; // health
	inventoryType[4] = "health";
	inventoryString[5] = "Bow and Arrows";
	inventoryStats[5] = 5; // atk
	inventoryType[5] = "attack";
	inventoryStats[6] = 1; // speed
	inventoryType[6] = "speed";
	inventoryString[6] = "Water Boots";
	inventoryStats[7] = 2; // armor
	inventoryType[7] = "armor";
	inventoryString[7] = "Amulet of Saphire";
	inventoryStats[8] = 10; // health
	inventoryType[8] = "health";
	inventoryString[8] = "Right Index Ring"; 
	inventoryStats[9] = 5; // health
	inventoryType[9] = "health";
	inventoryString[9] = "Steed of Death";
	inventoryStats[10] = 3; // speed
	inventoryType[10] = "speed";
	inventoryString[10] = "Battle Axe";
	inventoryStats[11] = 15; // atk
	inventoryType[11] = "attack";
	inventoryString[11] = "Leather Pants";
	inventoryStats[12] = 4; // armor
	inventoryType[12] = "armor";
	inventoryString[12] = "Right Thumb Ring";
	inventoryStats[13] = 5; // health
	inventoryType[13] = "health";
	inventoryString[13] = "Aumlet of Emerald";
	inventoryStats[14] = 10; // health
	inventoryType[14] = "health";
	inventoryString[14] = "Some Big Ass Acorn";
	inventoryStats[15] = 5; // armor
	inventoryType[15] = "armor";
	inventoryString[15] = "Some Big Ass Hammer";
	inventoryStats[16] = 30; // atk
	inventoryType[16] = "attack";
	inventoryString[16] = "Shield";
	inventoryStats[17] = 7; // armor
	inventoryType[17] = "armor";
	inventoryString[17] = "Amulet of Ruby";
	inventoryStats[18] = 10; // health
	inventoryType[18] = "health";
	inventoryString[18] = "Right Middle Ring";
	inventoryStats[19] = 5; // health
	inventoryType[19] = "health";
	inventoryString[19] = "The Crown";
	inventoryStats[20] = 0;
	inventoryType[20] = "none";
	inventoryString[20] = "Oblivion Staff";
	inventoryStats[21] = 50;
	inventoryType[21] = "attack";
	inventoryString[21] = "Boots of Speed";
	inventoryStats[22] = 5;
	inventoryType[22] = "speed";
	inventoryString[22] = "Dragon Scale Cape";
	inventoryStats[23] = 50;
	inventoryType[23] = "armor";
	inventoryString[23] = "Belt of Youth";
	inventoryStats[24] = 100;
	inventoryType[24] = "health";
	inventoryString[24] = "Blood Dagger";
	inventoryStats[25] = 25;
	inventoryType[25] = "attack";



}

Player::Player(int att, int heal, int arm, double spe, string nam, int gld, bool inv[], string invStr[], int invStats[], string invType[], int invNum[])
{
  setName(nam);
  setAttack(att);
  setHealth(heal);
  setArmor(arm);
  setSpeed(spe);
	setInventory(inv, invStr, invStats, invType, invNum);
	setGold(gld);
}

int Player::getGold()
{
	return gold;
}

void Player::setGold(int gld)
{
	gold = gld;
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

void Player::setInventory(bool inv[], string invStr[], int invStats[], string invType[], int invNum[])
{
	for (int i = 0; i < INVENTORY_MAX; i++)
	{
		inventory[i] = inv[i];
		inventoryString[i] = invStr[i];
	}
}

void Player::addItemToInventory(int itemNumber)
{
	inventory[itemNumber - 1] = true;
	
	if (inventoryString[itemNumber - 1] == "Bow and Arrows")
	{
		Player.setAttack(Player.getAttack() + inventoryStats[itemNumber - 1]);
		Player.setSpeed(Player.getSpeed() + inventoryStats[itemNumber]);
	}
	else if (inventoryType[itemNumber] == "attack" && inventoryNum[itemNumber - 1] > 6)
	{
		Player.setAttack(Player.getAttack() + inventoryStats[itemNumber]);
	}
	else if (inventoryType[itemNumber - 1] == "attack" && inventoryNum[itemNumber - 1] < 6)
	{
		Player.setAttack(Player.getAttack() + inventoryStats[itemNumber - 1]);
	}
	else if(inventoryType[itemNumber] == "armor" && inventoryNum[itemNumber - 1] > 6)
	{
		Player.setArmor(Player.getArmor() + inventoryStats[itemNumber]);
	}
	else if(inventoryType[itemNumber - 1] == "armor" && inventoryNum[itemNumber - 1] < 6)
	{
		Player.setArmor(Player.getArmor() + inventoryStats[itemNumber - 1]);
	}
	else if(inventoryType[itemNumber] == "health" && inventoryNum[itemNumber - 1] > 6)
	{
		Player.setHealth(Player.getHealth() + inventoryStats[itemNumber]);
	}
	else if(inventoryType[itemNumber] == "health" && inventoryNum[itemNumber - 1] < 6)
	{
		Player.setHealth(Player.getHealth() + inventoryStats[itemNumber - 1]);
	}
	else if(inventoryType[itemNumber] == "speed" && inventoryNum[itemNumber - 1] > 6)
	{
		Player.setSpeed(Player.getSpeed() + inventoryStats[itemNumber]);
	}
	else if(inventoryType[itemNumber] == "speed" && inventoryNum[itemNumber - 1] < 6)
	{
		Player.setSpeed(Player.getSpeed() + inventoryStats[itemNumber - 1]);
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
              "all 20 items collected throughout the game.\n\n";
}
void whatToDo(int a)
{
  cout << "\nYou are in room " << a << endl;
  cout << "What would you like to do in this room?\n";
  cout << "[1] search the room\n"
          "[2] move on to the next room\n";
}

void loc1()
{
  int locRoom1 = 1;
  int decision = 0;
  int direct = 0;
  int passCount1 = 0;
  int passCount2 = 0;
  int passCount3 = 0;
  int passCount4 = 0;

  cout << "\nMap loc 1";
  while(locRoom1 < 6)
  {
    switch(locRoom1)
    {
      case 1:;
        whatToDo(1);
        cin >> decision;
        if(decision == 1)
        {
          cout << "You look around the room and find a chest (1) and"
                  " a chest key (3)\n";
          passCount1++;
        }
        cout << "Which direction would you like to move?\n";
        cin >> direct;
        while(direct != 4)
        {
          cout << "That door is closed\n";
          cin >> direct;
        }
        if(direct == 4)
        {
          direct = 0;
          locRoom1++;
        }
      break; //locRoom1 1

      case 2:;
        whatToDo(2);
        cin >> decision;
        if(decision == 1)
        {
          cout << "You look around the room and find a chest (2) and"
                  " a chest key (1)\n";
        }
        cout << "Which direction would you like to move?\n";
        cin >> direct;
        while(direct == 1)
        {
          cout << "That door is closed\n";
          cin >> direct;
        }
        if(direct == 2)
        {
          direct = 0;
          locRoom1++;
        }
        if(direct == 3)
        {
          direct = 0;
          locRoom1--;
        }
        if(direct == 4)
        {
          direct = 0;
          locRoom1 += 2;
        }
      break; //locRoom1 2

      case 3:;
        whatToDo(3);
        cin >> decision;
        if(decision == 1)
        {
          cout << "You look around the room and find a chest (3) and"
                  " a chest key (4)\n";
        }
        cout << "Which direction would you like to move?\n";
        cin >> direct;
        while(direct != 1)
        {
          cout << "That door is closed\n";
          cin >> direct;
        }
        if(direct == 1)
        {
          direct = 0;
          locRoom1--;
        }
      break; //locRoom1 3

      case 4:;
        whatToDo(4);
        cin >> decision;
        if(decision == 1)
        {
          cout << "You look around the room and find a chest (4) and"
                  " a chest key (2)\n";
        }
        cout << "Which direction would you like to move?\n";
        cin >> direct;
        while(direct == 1 || direct == 2)
        {
          cout << "That door is closed\n";
          cin >> direct;
        }
        if(direct == 3)
        {
          direct = 0;
          locRoom1 -= 2;
        }
        if(direct == 4)
        {
          direct = 0;
          locRoom1++;
        }
      break; //locRoom1 4

      case 5:;
        cout << "Room 5\n";
        cout << "4: Fight the boss?\n"
                "3: Back to the Dungeon\n";
        cin >> direct;
        if(direct == 3)
        {
          direct = 0;
          locRoom1 --;
        }
        if(direct == 4)
        {
          direct = 0;
          locRoom1 = 6;
        }
      break; //locRoom1 5
    } //swtich locRoom1
  } //while locRoom1
}

void loc2()
{
  int locRoom2 = 1;
  int decision = 0;
  int direct = 0;

  cout << "\nMap loc 2";
  while(locRoom2 < 9)
  {
    switch(locRoom2)
    {
      case 1:;
        whatToDo(1);
        cin >> decision;
        if(decision == 1)
        {
          cout << "You look around the room and find a door key (1) and"
                  " a chest key (1)\n";
        }
        cout << "Which direction would you like to move?\n";
        cin >> direct;
        while(direct != 4)
        {
          cout << "That door is closed\n";
          cin >> direct;
        }
        if(direct == 4)
        {
          direct = 0;
          locRoom2++;
        }
      break; //locRoom2 1

      case 2:;
        whatToDo(2);
        cin >> decision;
        if(decision == 1)
        {
          cout << "You look around the room and find a door key (2),"
                  " a chest key (2)\nand a chest (3)\n";
        }
        cout << "Which direction would you like to move?\n";
        cin >> direct;
        while(direct == 1)
        {
          cout << "That door is closed";
          cin >> direct;
        }
        if(direct == 2)
        {
          direct = 0;
          locRoom2 += 4;
        }
        if(direct == 3)
        {
          direct = 0;
          locRoom2--;
        }
        if(direct == 4)
        {
          direct = 0;
          locRoom2++;
        }

      break; //locRoom2 2

      case 3:;
        whatToDo(3);
        cin >> decision;
        if(decision == 1)
        {
          cout << "You look around the room and find a chest key (4)"
                  "\nand a chest (2)\n";
        }
        cout << "Which direction would you like to move?\n";
        cin >> direct;
        while(direct == 1)
        {
          cout << "That door is closed";
          cin >> direct;
        }
        if(direct == 2)
        {
          direct = 0;
          locRoom2 += 4;
        }
        if(direct == 3)
        {
          direct = 0;
          locRoom2--;
        }
        if(direct == 4)
        {
          direct = 0;
          locRoom2++;
        }

      break; //locRoom2 3

      case 4:;
        whatToDo(4);
        cin >> decision;
        if(decision == 1)
        {
          cout << "You look around the room and find a door key (4)"
                  "\nand a chest (4)\n";
        }
        cout << "Which direction would you like to move?\n";
        cin >> direct;
        while(direct == 1 || direct == 2)
        {
          cout << "That door is closed";
          cin >> direct;
        }
        if(direct == 3)
        {
          direct = 0;
          locRoom2--;
        }
        if(direct == 4)
        {
          direct = 0;
          locRoom2++;
        }
      break; //locRoom2 4

      case 5:;
        whatToDo(5);
        cin >> decision;
        if(decision == 1)
        {
          cout << "You look around the room and find a chest key (3)"
                  "\nand a chest (1)\n";
        }
        cout << "Which direction would you like to move?\n";
        cin >> direct;
        while(direct == 1 || direct == 2)
        {
          cout << "That door is closed";
          cin >> direct;
        }
        if(direct == 3)
        {
          direct = 0;
          locRoom2--;
        }
        if(direct == 4)
        {
          direct = 0;
          locRoom2++;
        }
      break; //locRoom2 5

      case 6:;
        whatToDo(6);
        cin >> decision;
         if(decision == 1)
        {
          cout << "You look around the room and find a door key (3)\n";
        }
        cout << "Which direction would you like to move?\n";
        cin >> direct;
        while(direct == 2)
        {
          cout << "That door is closed\n";
          cin >> direct;
        }
        if(direct == 1)
        {
          direct = 0;
          locRoom2 -= 4;
        }
        if(direct == 3)
        {
          direct = 0;
          locRoom2--;
        }
        if(direct == 4)
        {
          direct = 0;
          locRoom2++;
        }
      break; //locRoom2 6

      case 7:;
        whatToDo(7);
        cin >> decision;
        if(decision == 1)
        {
          cout << "You look around the room and find nothing\n";
        }
        cout << "Which direction would you like to move?\n";
        cin >> direct;
        while(direct == 2)
        {
          cout << "That door is closed\n";
          cin >> direct;
        }
        locRoom2++;
      break; //locRoom2 7

      case 8:;
        cout << "\nYou are in room 8";
        cout << "4: Fight the boss?\n"
                "3: Back to the Dungeon\n";
        cin >> direct;
        if(direct == 3)
        {
          direct = 0;
          locRoom2--;
        }
        if(direct == 4)
        {
          direct = 0;
          locRoom2++;
        }
      break; //locRoom2 8
    } //swtich locRoom2
  } //while locRoom2
}

void loc3()
{
  int locRoom3 = 1;
  int decision = 0;
  int direct = 0;

  cout << "Map loc 3\n";
  while(locRoom3 < 12)
  {
    switch(locRoom3)
    {
      case 1:;
        whatToDo(1);
        cin >> decision;
        if(decision == 1)
        {
          cout << "You look around the room and find a chest key (1)\n";
        }
        cout << "Which direction would you like to move?\n";
        cin >> direct;
        while(direct != 4)
        {
          cout << "That door is closed\n";
          cin >> direct;
        }
        if(direct == 4)
        {
          direct = 0;
          locRoom3++;
        }
      break; //locRoom3 1

      case 2:;
        whatToDo(2);
        cin >> decision;
        if(decision == 1)
        {
          cout << "You look around the room and find a door key (1)\n";
        }
        cout << "Which direction would you like to move?\n";
        cin >> direct;
        while(direct == 1)
        {
          cout << "That door is closed\n";
          cin >> direct;
        }
        if(direct == 2)
        {
          direct = 0;
          locRoom3 += 3;
        }
        if(direct == 3)
        {
          direct = 0;
          locRoom3--;
        }
        if(direct == 4)
        {
          direct = 0;
          locRoom3 ++;
        }
      break; //locRoom3 2

      case 3:;
        whatToDo(3);
        cin >> decision;
        if(decision == 1)
        {
          cout << "You look around the room and find a chest key (2)"
                  "\nand a chest (3)\n";
        }
        cout << "Which direction would you like to move?\n";
        cin >> direct;
        while(direct == 1 || direct == 4)
        {
          cout << "That door is closed\n";
          cin >> decision;
        }
        if(direct == 2)
        {
          direct = 0;
          locRoom3 += 3;
        }
        if(direct == 3)
        {
          direct = 0;
          locRoom3--;
        }
      break; //locRoom3 3

      case 4:;
        whatToDo(4);
        cin >> decision;
        if(decision == 1)
        {
          cout << "You look around the room and find a chest key (3)\n";
        }
        cout << "Which direction would you like to move?\n";
        cin >> direct;
        while(direct == 1 || direct == 3)
        {
          cout << "That door is closed\n";
          cin >> decision;
        }
        if(direct == 2)
        {
          direct = 0;
          locRoom3 += 3;
        }
        if(direct == 4)
        {
          direct = 0;
          locRoom3++;
        }
        locRoom3++;
      break; //locRoom3 4

      case 5:;
        whatToDo(5);
        cin >> decision;
        if(decision == 1)
        {
          cout << "You look around the room and find a door key (2)"
                  "\na chest key (4) and a chest (2)\n";
        }
        cout << "Which direction would you like to move?\n";
        cin >> direct;
        if(direct == 1)
        {
          direct = 0;
          locRoom3 -= 3;
        }
        if(direct == 2)
        {
          direct = 0;
          locRoom3 += 3;
        }
        if(direct == 3)
        {
          direct = 0;
          locRoom3--;
        }
        if(direct == 4)
        {
          locRoom3++;
        }
      break; //locRoom3 5

      case 6:;
        whatToDo(6);
        cin >> decision;
        if(decision == 1)
        {
          cout << "You look around the room and find nothing\n";
        }
        cout << "Which direction would you like to move?\n";
        cin >> direct;
        while(direct == 2 || direct == 4)
        {
          cout << "That door is closed\n";
          cin >> decision;
        }
        if(direct == 1)
        {
          direct = 0;
          locRoom3 -= 3;
        }
        if(direct == 3)
        {
          direct = 0;
          locRoom3--;
        }
      break; //locRoom3 6

      case 7:;
        whatToDo(7);
        cin >> decision;
        if(decision == 1)
        {
          cout << "You look around the room and find chest key (3)\n";
        }
        cout << "Which direction would you like to move?\n";
        cin >> direct;
        while(direct == 2 || direct == 3)
        {
          cout << "That door is closed\n";
          cin >> decision;
        }
        if(direct == 1)
        {
          direct = 0;
          locRoom3 -= 3;
        }
        if(direct == 4)
        {
          direct = 0;
          locRoom3++;
        }
      break; //locRoom3 7

      case 8:;
        whatToDo(8);
        cin >> decision;
        if(decision == 1)
        {
          cout << "You look around the room and find a chest (1)\n";
        }
        cout << "Which direction would you like to move?\n";
        cin >> direct;
        if(direct == 1)
        {
          direct = 0;
          locRoom3 -= 3;
        }
        if(direct == 2)
        {
          direct = 0;
          locRoom3 += 2;
        }
        if(direct == 3)
        {
          direct = 0;
          locRoom3--;
        }
        if(direct == 4)
        {
          direct = 0;
          locRoom3++;
        }
      break; //locRoom3 8

      case 9:;
        whatToDo(9);
        cin >> decision;
        if(decision == 1)
        {
          cout << "You look around the room and find a door key (4)\n"
                  "and a chest (4)\n";
        }
        cout << "Which direction would you like to move?\n";
        cin >> direct;
        while(direct != 3)
        {
          cout << "That door is closed\n";
          cin >> direct;
        }
        if(direct == 3)
        {
          direct = 0;
          locRoom3--;
        }
      break; //locRoom3 9

      case 10:;
        whatToDo(10);
        cin >> decision;
        if(decision == 1)
        {
          cout << "You look around the room and find nothing\n";
        }
        cout << "Which direction would you like to move?\n";
        cin >> direct;
        while(direct == 2 || direct == 3)
        {
          cout << "That door is closed";
          cin >> direct;
        }
        if(direct == 1)
        {
          direct = 0;
          locRoom3 -= 2;
        }
        if(direct == 4)
        {
          locRoom3++;
        }
      break; //locRoom3 10

      case 11:;
        cout << "\nYou are in room 11";
        cout << "4: Fight the boss?\n"
                "3: Back to the Dungeon\n";
        cin >> direct;
        if(direct == 3)
        {
          direct = 0;
          locRoom3--;
        }
        if(direct == 4)
        {
          direct = 0;
          locRoom3++;
        }
      break; //locRoom3 11
    } //swtich locRoom3
  } //while locRoom3
}

void loc4()
{
  int locRoom4 = 1;
  int decision = 0;
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

void store(Player plyr)
{
	int choice = 0;
	int buy = 0;
	bool exit = false;
	cout << "Welcome to the Secret Store!\nWould you like to buy something?" << endl;
	cout << "1. No\n2. Not sure yet, what do you have to offer?" << endl;

	switch(choice)
	{
	case 1:
		cout << "Okay, have a nice day." << endl;
		break;
	case 2:
		while(exit = false)
		{
			cout << "Here are the items available:\n\n1. Oblivion Staff\n+50 Attack\n"
				<< "100g\n\n2. Boots of Speed\n+5 Speed\n40g\n\n3. Dragon Scale Cape\n"
				<< "+50 Armor\n100g\n\n4. Belt of Youth\n+100 HP\n60g\n\n"
				<< "5. Blood Dagger\n+25 Attack\n40g\n\nSelect one of these items or"
				<< " press 6. to exit the shop.\n\n (You have" << plyr.getGold() << "g)"
				<< endl;
			switch(buy)
			{
				case 1:
					if(plyr.getGold() >= 100)
					{
						cout << "You have bought the Oblivion Staff!\n";
						plyr.addItemToInventory(21);
						plyr.setGold(plyr.getGold() - 100);
					}
					else
					{
						cout << "You don't have enough money for this item!\n";
					}

				break;

				case 2:
					if(plyr.getGold() >= 40)
					{
						cout << "You have bought the Boots of Speed!\n";
						plyr.addItemToInventory(22);
						plyr.setGold(plyr.getGold() - 40);
					}
					else
					{
						cout << "You don't have enough money for this item!\n";
					}

				break;

				case 3:
					if(plyr.getGold() >= 100)
					{
						cout << "You have bought the Dragon Scale Cape!\n";
						plyr.addItemToInventory(23);
						plyr.setGold(plyr.getGold() - 100);
					}
					else
					{
						cout << "You don't have enough money for this item!\n";
					}

				break;

				case 4:
					if(plyr.getGold() >= 60)
					{
						cout << "You have bought the Belt of Youth!\n";
						plyr.addItemToInventory(24);
						plyr.setGold(plyr.getGold() - 60);
					}
					else
					{
						cout << "You don't have enough money for this item!\n";
					}

				break;

				case 5:
					if(plyr.getGold() >= 40)
					{
						cout << "You have bought the Blood Dagger!\n";
						plyr.addItemToInventory(25);
						plyr.setGold(plyr.getGold() - 40);
					}
					else
					{
						cout << "You don't have enough money for this item!\n";
					}

				break;

				case 6:
					cout << "Thanks for your business!" << endl;
					exit = true;

				break;
			}

		break;
		}

	}
}

void createWizard(Entity wzrd)
{
	wzrd.setName("Wizard");
	wzrd.setAttack(20);
	wzrd.setHealth(25);
	wzrd.setArmor(0);
	wzrd.setSpeed(2);
}

void createKnight(Entity knght)
{
	knght.setName("Knight");
	knght.setAttack(15);
	knght.setHealth(25);
	knght.setArmor(5);
	knght.setSpeed(1);
}

void createArcher(Entity archr)
{
	archr.setName("Archer");
	archr.setAttack(15);
	archr.setHealth(20);
	archr.setArmor(2);
	archr.setSpeed(4);
}

void createPrimusRatticus(Entity priRat)
{
	priRat.setName("Primus Ratticus");
	priRat.setAttack(25);
	priRat.setHealth(25);
	priRat.setArmor(8);
	priRat.setSpeed(3);
}

void createSecondusSerpent(Entity secSerp)
{
	secSerp.setName("Secondus Serpent");
	secSerp.setAttack(30);
	secSerp.setHealth(20);
	secSerp.setArmor(15);
	secSerp.setSpeed(5);
}

void createStagOfTertius(Entity stagTert)
{
	stagTert.setName("Stag of Tertius");
	stagTert.setAttack(20);
	stagTert.setHealth(120);
	stagTert.setArmor(20);
	stagTert.setSpeed(4);
}

void createLordFarquaad(Entity lordF)
{
	lordF.setName("Lord Farquaad");
	lordF.setAttack(100);
	lordF.setHealth(100);
	lordF.setArmor(35);
	lordF.setSpeed(10);
}
