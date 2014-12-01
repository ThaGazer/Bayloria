#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

Player::Player()
{
  setName("Bob The Slayer");
  setAttack(0);
  setHealth(0);
	setTotalHealth(0);
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

Player::Player(int att, int heal, int totHeal, int arm, int spe, string nam, int gld, bool inv[], string invStr[], int invStats[], string invType[], int invNum[])
{
  setName(nam);
  setAttack(att);
  setHealth(heal);
	setTotalHealth(totHeal);
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

void Player::addGold(Player &plyr, int gld)
{
	plyr.setGold(plyr.getGold() + gld);
}

void Player::subtGold(Player &plyr, int gld)
{
	plyr.setGold(plyr.getGold() - gld);
}

void Player::getInventory(Player &plyr)
{
	cout << "_______________________________________________\n";
	for (int i = 0; i < INVENTORY_MAX; i++)
	{
		if (inventory[i] == true)
		{
			if (inventoryString[i] == "Bow and Arrows")
			{
				cout << inventoryNum[i] << ". " << inventoryString[i]
						<< "\t+" << inventoryStats[i] << " " << inventoryType[i] 
						<< " +" << inventoryStats[i + 1] << " " << inventoryType[i + 1]
						<< endl;
			}
			else if(inventoryNum[i] < 6)
			{
				cout << inventoryNum[i] << ". " << inventoryString[i]
						<< "\t+" << inventoryStats[i] << " " << inventoryType[i] << endl; 
			}
			else
			{
				cout << inventoryNum[i + 1] << ". " << inventoryString[i + 1]
						<< "\t+" << inventoryStats[i + 1] << " " << inventoryType[i + 1] << endl; 
			}
		}
	}
	cout << "\n" << plyr.getGold() << "g\n";
	cout << "_______________________________________________\n\n";
}

void Player::setInventory(bool inv[], string invStr[], int invStats[], string invType[], int invNum[])
{
	for (int i = 0; i < INVENTORY_MAX; i++)
	{
		inventory[i] = inv[i];
		inventoryString[i] = invStr[i];
	}
}

void Player::addItemToInventory(int itemNumber, Player &plyr)
{
	inventory[itemNumber - 1] = true;
	
	if (inventoryString[itemNumber - 1] == "Bow and Arrows")
	{
		plyr.setAttack(plyr.getAttack() + inventoryStats[itemNumber - 1]);
		plyr.setSpeed(plyr.getSpeed() + inventoryStats[itemNumber]);
	}
	else if (inventoryType[itemNumber] == "attack" && inventoryNum[itemNumber - 1] > 6)
	{
		plyr.setAttack(plyr.getAttack() + inventoryStats[itemNumber]);
	}
	else if (inventoryType[itemNumber - 1] == "attack" && inventoryNum[itemNumber - 1] < 6)
	{
		plyr.setAttack(plyr.getAttack() + inventoryStats[itemNumber - 1]);
	}
	else if(inventoryType[itemNumber] == "armor" && inventoryNum[itemNumber - 1] > 6)
	{
		plyr.setArmor(plyr.getArmor() + inventoryStats[itemNumber]);
	}
	else if(inventoryType[itemNumber - 1] == "armor" && inventoryNum[itemNumber - 1] < 6)
	{
		plyr.setArmor(plyr.getArmor() + inventoryStats[itemNumber - 1]);
	}
	else if(inventoryType[itemNumber] == "health" && inventoryNum[itemNumber - 1] > 6)
	{
		plyr.setHealth(plyr.getHealth() + inventoryStats[itemNumber]);
		plyr.setTotalHealth(plyr.getHealth());
	}
	else if(inventoryType[itemNumber] == "health" && inventoryNum[itemNumber - 1] < 6)
	{
		plyr.setHealth(plyr.getHealth() + inventoryStats[itemNumber - 1]);
		plyr.setTotalHealth(plyr.getHealth());
	}
	else if(inventoryType[itemNumber] == "speed" && inventoryNum[itemNumber - 1] > 6)
	{
		plyr.setSpeed(plyr.getSpeed() + inventoryStats[itemNumber]);
	}
	else if(inventoryType[itemNumber] == "speed" && inventoryNum[itemNumber - 1] < 6)
	{
		plyr.setSpeed(plyr.getSpeed() + inventoryStats[itemNumber - 1]);
	}
}

string Player::getInventoryString(int num)
{
	return inventoryString[num];
}

int Player::sumInventory()
{
	int sum = 0;
	for (int i = 0; i < INVENTORY_MAX; i++)
	{
		sum += inventory[i];
	}

	return sum;
}

void Player::displayPlayerStats(Player plyr)
{
	cout << "___________________\n";
	cout << "\nName: " << plyr.getName() << "\nAttack: " << plyr.getAttack()
			<< "\nHealth: " << plyr.getHealth() << "/" << plyr.getTotalHealth() 
			<< "\nArmor: " << plyr.getArmor() << "\nSpeed: " << plyr.getSpeed() 
			<< endl;
	cout << "___________________\n";
}
