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

#include "Entity.h"
#include "Player.h"
#include "Functions.h"
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

void instructions()
{
  cout << "To play the game all you have to do is enter the four numbers\n"
          "that relate to the door you want to go through:\n"
          "1 to go north, 2 to go south, 3 to go west, and 4 to go east\n"
          "Certain door will be locked, you can unlock these doors\n"
          "but only if you find the door keys\n"
          "There are treasure chests that are placed throughout the 4 maps\n"
          "There are also keys that are spread throughout the map\n"
          "You must collect all 4 items on the floor then kill the Boss\n"
          "on the floor and receive item of the floor\n"
          "To finish the game you must kill the final Boss and present\n"
          "all 20 items collected throughout the game.\n\n";
}

void description()
{
  cout << "Bayloria is a mythical land that possesses some very strange beings"
          "\nExplore Bayloria while you try to find your way through the maze\n"
          "and labrinths that form the four levels of Bayloria\n"
          "Fight your way through the dungeons and lands\n"
          "Battle crazy bosses and aquire the treasures that are\n"
          "hidden throughout the maps\nTip: pay attention to the directions"
          " you move, because they may help when you get lost\n\n";
}

void credits()
{
  cout << "Cole Crawford and Justin Ritter did a lot of typing"
          "and Nannan wants a haricut\n\n";
}

void whatToDo(int a)
{
	cout << "\nRoom " << a << endl;
  cout << "What would you like to do here?\n";
  cout << "[1] search the room\n"
          "[2] move on to the next room\n";
}

void searchRoom(string chestColor, bool key, bool &chest, bool &isOpen,
                Player &plyr, int whchItem)
{
	if(chest == true)
	{
		cout << "You search the room and find a " << chestColor << " chest!"
         << endl;
		cout << "Would you like to open the chest?\n[y] yes\n[n] no\n";
		openTheChest(key, plyr, isOpen, whchItem);

		if (isOpen == true)
		{
			plyr.addItemToInventory(whchItem, plyr);
			chest = false;
		}
	}
	else
	{
		cout << "You look around and don't find much..." << endl;
	}

}

void moveNextRoom(int &direct, bool dire[], bool &valDec)
{
	valDec = false;

	while(valDec == false)
	{
		cout << "Which direction would you like to move?\n"
				<< "[1] North\n[2] South\n[3] West\n[4] East\n";
		cin >> direct;
		cout << endl;

		if(direct == 1 || direct == 2 || direct == 3 || direct == 4)
		{
			if(dire[direct - 1] == false)
			{
				cout << "There is not a door this way, the only thing in front of "
						<<"you is a stone wall.\nTry a different direction.\n";
			}

			valDec = true;
		}
		else
		{
			invalidCommand();
		}
	}
}

void invalidCommand()
{
	cout << "Invalid command!" << endl;
}

void loc1(Player &plyr)
{
	bool redKey = true; // all keys true because no locks first floor
	bool greenKey = true; // all keys true because no locks first floor
	bool blueKey = true; // all keys true because no locks first floor
	bool yellowKey = true; // all keys true because no locks first floor

	bool redChestIsHere;
	bool greenChestIsHere;
	bool blueChestIsHere;
	bool yellowChestIsHere;

	int itemCountMasterkey = 4;
	bool redOpen = false;
	bool greenOpen = false;
	bool blueOpen = false;
	bool yellowOpen = false;

	bool direction[4];

	int itemCount = 0;
	bool open = false;
	bool foughtBoss = false;
	char pickUp = '\0';

  int locRoom1 = 1;
  int decision = 0;
  int direct = 0;
  int passCount[5];

	for(int i = 0; i < 5; i++)
	{
		passCount[i] = 0;
	}

  cout << "\nMap loc 1" << endl;
  while(locRoom1 < 6)
  {
		bool move = false;
		bool validDecision = false;
		bool yesNo = false;

    switch(locRoom1)
    {
      case 1:;
				if(passCount[0] == 0)
				{
					redChestIsHere = true; // unopened chest in this room
					passCount[0]++; // +1 pass into this room
					while(move == false && validDecision == false)
					{
						whatToDo(1);
						cin >> decision;
						cout << endl;

						if(decision == 1)
						{
							searchRoom("red", redKey, redChestIsHere, open, plyr, 1);
						} // if look around
						else if(decision == 2)
						{
							passCount[0]++;
							// next time you enter room, will display different message...
							validDecision = true;
							move = true;
						} // if move
						else
						{
							invalidCommand();
							validDecision = false;
						} // invalid input
					} // while not move and not good input

					direction[0] = false;
					direction[1] = false;
					direction[2] = false;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 4)
					{
						locRoom1++;
					}
				} // if not been to room before
				else
				{
					passCount[0]++;
					cout << "You have visited this room before...\n";

					while(move == false && validDecision == false)
					{
						whatToDo(1);
						cin >> decision;
						cout << endl;

						if (decision == 1)
						{
							searchRoom("red", redKey, redChestIsHere, open, plyr, 1);
						}
						else if (decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							validDecision = false;
						}
					} // while not move and not good input

					direction[0] = false;
					direction[1] = false;
					direction[2] = false;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 4)
					{
						locRoom1++;
					}
				} // else already been to room
      break; //locRoom1 1

      case 2:;
				if(passCount[1] == 0)
				{
					greenChestIsHere = true;
					passCount[1]++; // +1 pass into this room
					while(move == false && validDecision == false)
					{
						whatToDo(2);
						cin >> decision;
						cout << endl;

						if(decision == 1)
						{
							searchRoom("green", greenKey, greenChestIsHere, open, plyr, 2);
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							invalidCommand();
							validDecision = false;
						}
					}

					direction[0] = false;
					direction[1] = true;
					direction[2] = true;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 2)
					{
						locRoom1++;
					}
					else if(direct == 3)
					{
						locRoom1--;
					}
					else if(direct == 4)
					{
						locRoom1 += 2;
					}
				}
				else
				{
					passCount[1]++;
					cout << "You have visited this room before...\n";

					while(move == false && validDecision == false)
					{
						whatToDo(2);
						cin >> decision;
						cout << endl;

						if (decision == 1)
						{
							searchRoom("green", greenKey, greenChestIsHere, open, plyr, 2);
						}
						else if (decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							validDecision = false;
						}
					} // while not move and not good input

					direction[0] = false;
					direction[1] = true;
					direction[2] = true;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 2)
					{
						locRoom1++;
					}
					else if(direct == 3)
					{
						locRoom1--;
					}
					else if(direct == 4)
					{
						locRoom1 += 2;
					}
				} // else already been to room
      break; //locRoom1 2

      case 3:;
				if(passCount[2] == 0)
				{
					blueChestIsHere = true;
					passCount[2]++; // +1 pass into this room
					while(move == false && validDecision == false)
					{
						whatToDo(3);
						cin >> decision;
						cout << endl;

						if(decision == 1)
						{
							searchRoom("blue", blueKey, blueChestIsHere, open, plyr, 3);
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							invalidCommand();
							validDecision = false;
						}
					}

					direction[0] = true;
					direction[1] = false;
					direction[2] = false;
					direction[3] = false;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 1)
					{
						locRoom1--;
					}
				}
				else
				{
					passCount[2]++;
					cout << "You have visited this room before...\n";

					while(move == false && validDecision == false)
					{
						whatToDo(3);
						cin >> decision;
						cout << endl;

						if (decision == 1)
						{
							searchRoom("blue", blueKey, blueChestIsHere, open, plyr, 3);
						}
						else if (decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							validDecision = false;
						}
					} // while not move and not good input

					direction[0] = true;
					direction[1] = false;
					direction[2] = false;
					direction[3] = false;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 1)
					{
						locRoom1--;
					}
				} // else already been to room
      break; //locRoom1 3

      case 4:;
				if(passCount[3] == 0)
				{
					yellowChestIsHere = true;
					passCount[3]++; // +1 pass into this room
					while(move == false && validDecision == false)
					{
						whatToDo(4);
						cin >> decision;
						cout << endl;

						if(decision == 1)
						{
							searchRoom("yellow", yellowKey, yellowChestIsHere, open, plyr, 4);
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							invalidCommand();
							validDecision = false;
						}
					}

					direction[0] = false;
					direction[1] = false;
					direction[2] = true;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 3)
					{
						validDecision = true;
						direct = 0;
						locRoom1 -= 2;
					}
					else if(direct == 4)
					{
						validDecision = true;
						direct = 0;
						locRoom1++;
					}
				}
				else
				{
					passCount[3]++;
					cout << "You have visited this room before...\n";

					while(move == false && validDecision == false)
					{
						whatToDo(4);
						cin >> decision;
						cout << endl;

						if (decision == 1)
						{
							searchRoom("yellow", yellowKey, yellowChestIsHere, open, plyr, 4);
						}
						else if (decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							validDecision = false;
						}
					} // while not move and not good input

					direction[0] = false;
					direction[1] = false;
					direction[2] = true;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 3)
					{
						validDecision = true;
						direct = 0;
						locRoom1 -= 2;
					}
					else if(direct == 4)
					{
						validDecision = true;
						direct = 0;
						locRoom1++;
					}
				} // else already been to room
			break; //locRoom1 4

			case 5:;
				passCount[4]++;
				cout << "Boss Room\n";
				cout << "1: Fight the boss?\n"
								"2: Back to the Dungeon\n";
				cin >> direct;
				cout << endl;

				if(direct == 2)
				{
					direct = 0;
					locRoom1 --;
				}
				if(direct == 1 && foughtBoss == false)
				{
					cout << "You spot a giant rat...\nAnd he's coming right at you!\n";
					foughtBoss = true;
					Entity boss1;
					createPrimusRatticus(boss1); // create first boss

					boss1.displayEntityStats(boss1);
					plyr.displayPlayerStats(plyr);

					attack(plyr, boss1);

					if(boss1.getHealth() < 1)
					{
						cout << "You have defeated Raticus Primus!\n";
            cout << "For defeating such a boss, you shall recieve the"
                    "master key";
						plyr.addGold(plyr, 20);
						plyr.addItemToInventory(itemCountMasterkey, plyr);
						plyr.getInventory(plyr);
						//plyr.setHealth(plyr.getTotalHealth());
					}

					direct = 0;
					locRoom1 = 6;
				}
      break; //locRoom1 5
    } //swtich locRoom1
  } //while locRoom1
}

void loc2(Player &plyr)
{
	bool redKey = true; // all keys true because no locks first floor
	bool greenKey = true; // all keys true because no locks first floor
	bool blueKey = true; // all keys true because no locks first floor
	bool yellowKey = true; // all keys true because no locks first floor

	bool redChestIsHere = false;
	bool greenChestIsHere = false;
	bool blueChestIsHere = false;
	bool yellowChestIsHere = false;
	bool redChestIsHereTemp = false;
	bool greenChestIsHereTemp = false;
	bool blueChestIsHereTemp = false;
	bool yellowChestIsHereTemp = false;

	int itemCountMasterkey = 4;
	bool redOpen = false;
	bool greenOpen = false;
	bool blueOpen = false;
	bool yellowOpen = false;

	bool direction[4];

	int itemCount = 0;
	bool open = false;
	bool foughtBoss = false;
	char pickUp = '\0';

	int locRoom2 = 1;
  int decision = 0;
  int direct = 0;
  int passCount[11];

  Entity archr1;
  Entity archr2;
  Entity night1;
  createArcher(archr1);
  createArcher(archr2);
  createKnight(night1);

	for(int i = 0; i < 11; i++)
	{
		passCount[i] = 0;
	}

  cout << "\nMap loc 2";
  while(locRoom2 < 9)
  {
		bool move = false;
		bool validDecision = false;
		bool yesNo = false;

		redChestIsHere = false;
		greenChestIsHere = false;
		blueChestIsHere = false;
		yellowChestIsHere = false;

    switch(locRoom2)
    {
      case 1:;
				if(passCount[0] == 0)
				{
					passCount[0]++;
					while(move == false && validDecision == false)
					{
						whatToDo(1);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("yellow", yellowKey, yellowChestIsHere, open, plyr, 11);
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							invalidCommand();
							validDecision = false;
						}
					}

					direction[0] = false;
					direction[1] = false;
					direction[2] = false;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 4)
					{
						locRoom2++;
					}
				}
				else
				{
					passCount[0]++;
					cout << "You have visited this room before...\n";

					while(move == false && validDecision == false)
					{
						whatToDo(1);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("yellow", yellowKey, yellowChestIsHere, open, plyr, 11);
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							invalidCommand();
							validDecision = false;
						}
					}

					direction[0] = false;
					direction[1] = false;
					direction[2] = false;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 4)
					{
						locRoom2++;
					}
				}
      break; //locRoom2 1

      case 2:;
				blueChestIsHere = true;
				blueChestIsHereTemp = blueChestIsHere;
				if(passCount[1] == 0)
				{
					passCount[1]++;

					cout << "You stubbled into an Archer!!!\nPrepare for battle\n\n";

          archr1.displayEntityStats(archr1);
          plyr.displayPlayerStats(plyr);
          attack(plyr, archr1);
          if(plyr.getHealth() > 0)
          {
            plyr.addGold(plyr, 5);
          }
					while(move == false && validDecision == false)
					{
						whatToDo(2);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("blue", blueKey, blueChestIsHere, open, plyr, 11);
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							invalidCommand();
							validDecision = false;
						}
					}

					direction[0] = false;
					direction[1] = true;
					direction[2] = true;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 2)
					{
						locRoom2 += 4;
					}
					if(direct == 3)
					{
						locRoom2--;
					}
					if(direct == 4)
					{
						locRoom2++;
					}
				}
				else
				{
					passCount[1]++;
					cout << "You have visited this room before...\n";

					while(move == false && validDecision == false)
					{
						whatToDo(2);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("blue", blueKey, blueChestIsHereTemp, open, plyr, 11);
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							invalidCommand();
							validDecision = false;
						}
					}

					direction[0] = false;
					direction[1] = true;
					direction[2] = true;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 2)
					{
						locRoom2 += 4;
					}
					if(direct == 3)
					{
						locRoom2--;
					}
					if(direct == 4)
					{
						locRoom2++;
					}
				}
      break; //locRoom2 2

      case 3:;
				greenChestIsHere = true;
				greenChestIsHereTemp = greenChestIsHere;
				if(passCount[2] == 0)
				{
					passCount[2]++;
					while(move == false && validDecision == false)
					{
						whatToDo(3);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("blue", blueKey, greenChestIsHere, open, plyr, 11);
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							invalidCommand();
							validDecision = false;
						}
					}

					direction[0] = false;
					direction[1] = true;
					direction[2] = true;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 2)
					{
						locRoom2 += 4;
					}
					if(direct == 3)
					{
						locRoom2--;
					}
					if(direct == 4)
					{
						locRoom2++;
					}
				}
				else
				{
					passCount[2]++;
					cout << "You have visited this room before...\n";

					while(move == false && validDecision == false)
					{
						whatToDo(3);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("blue", blueKey, greenChestIsHereTemp, open, plyr, 11);
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							invalidCommand();
							validDecision = false;
						}
					}

					direction[0] = false;
					direction[1] = true;
					direction[2] = true;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 2)
					{
						locRoom2 += 4;
					}
					if(direct == 3)
					{
						locRoom2--;
					}
					if(direct == 4)
					{
						locRoom2++;
					}
				}
      break; //locRoom2 3

      case 4:;
				yellowChestIsHere = true;
				yellowChestIsHereTemp = yellowChestIsHere;
				if(passCount[3] == 0)
				{
					passCount[3]++;
					while(move == false && validDecision == false)
					{
						whatToDo(4);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("blue", blueKey, greenChestIsHere, open, plyr, 11);
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							invalidCommand();
							validDecision = false;
						}
					}

					direction[0] = false;
					direction[1] = false;
					direction[2] = true;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 3)
					{
						locRoom2--;
					}
					if(direct == 4)
					{
						locRoom2++;
					}
				}
				else
				{
					passCount[3]++;
					cout << "You have visited this room before...\n";

					while(move == false && validDecision == false)
					{
						whatToDo(4);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("blue", blueKey, greenChestIsHereTemp, open, plyr, 11);
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							invalidCommand();
							validDecision = false;
						}
					}

					direction[0] = false;
					direction[1] = false;
					direction[2] = true;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 3)
					{
						locRoom2--;
					}
					if(direct == 4)
					{
						locRoom2++;
					}
				}
      break; //locRoom2 4

      case 5:;
				redChestIsHere = true;
				redChestIsHereTemp = redChestIsHere;
				if(passCount[4] == 0)
				{
					passCount[4]++;

          cout << "You walked into a Archer!!!\nPrepare for battle\n\n";

          archr2.displayEntityStats(archr2);
          plyr.displayPlayerStats(plyr);
          attack(plyr, archr2);
          if(plyr.getHealth() > 0)
          {
            plyr.addGold(plyr, 10);
          }

					while(move == false && validDecision == false)
					{
						whatToDo(5);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("blue", blueKey, redChestIsHere, open, plyr, 11);
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							invalidCommand();
							validDecision = false;
						}
					}

					direction[0] = false;
					direction[1] = false;
					direction[2] = true;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

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
				}
				else
				{
					passCount[4]++;
					cout << "You have visited this room before...\n";

					while(move == false && validDecision == false)
					{
						whatToDo(5);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("blue", blueKey, redChestIsHereTemp, open, plyr, 11);
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							invalidCommand();
							validDecision = false;
						}
					}

					direction[0] = false;
					direction[1] = false;
					direction[2] = true;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

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
				}
      break; //locRoom2 5

      case 6:;
				if(passCount[5] == 0)
				{
					passCount[5]++;
					while(move == false && validDecision == false)
					{
						whatToDo(6);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("blue", blueKey, redChestIsHere, open, plyr, 11);
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							invalidCommand();
							validDecision = false;
						}
					}

					direction[0] = true;
					direction[1] = false;
					direction[2] = true;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 1)
					{
						locRoom2 -= 4;
					}
					if(direct == 3)
					{
						locRoom2--;
					}
					if(direct == 4)
					{
						locRoom2++;
					}
				}
				else
				{
					passCount[5]++;
					cout << "You have visited this room before...\n";

					while(move == false && validDecision == false)
					{
						whatToDo(6);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("blue", blueKey, redChestIsHere, open, plyr, 11);
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							invalidCommand();
							validDecision = false;
						}
					}

					direction[0] = true;
					direction[1] = false;
					direction[2] = true;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 1)
					{
						locRoom2 -= 4;
					}
					if(direct == 3)
					{
						locRoom2--;
					}
					if(direct == 4)
					{
						locRoom2++;
					}
				}
      break; //locRoom2 6

      case 7:;
				if(passCount[6] == 0)
				{
					passCount[6]++;

          cout << "A Knight appeared from behind a door!!!\nPrepare for battle\n\n";

          night1.displayEntityStats(night1);
          plyr.displayPlayerStats(plyr);
          attack(plyr, night1);
          if(plyr.getHealth() > 0)
          {
            plyr.addGold(plyr, 10);
          }

					while(move == false && validDecision == false)
					{
						whatToDo(7);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("blue", blueKey, redChestIsHere, open, plyr, 11);
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							invalidCommand();
							validDecision = false;
						}
					}

					direction[0] = true;
					direction[1] = false;
					direction[2] = true;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 1)
					{
						locRoom2 -= 4;
					}
					else if(direct == 3)
					{
						locRoom2--;
					}
					else if(direct == 4)
					{
						locRoom2++;
					}
				}
				else
				{
					passCount[6]++;
					cout << "You have visited this room before...\n";

					while(move == false && validDecision == false)
					{
						whatToDo(7);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("blue", blueKey, redChestIsHere, open, plyr, 11);
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							invalidCommand();
							validDecision = false;
						}
					}

					direction[0] = true;
					direction[1] = false;
					direction[2] = true;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 1)
					{
						locRoom2 -= 4;
					}
					else if(direct == 3)
					{
						locRoom2--;
					}
					else if(direct == 4)
					{
						locRoom2++;
					}
				}
      break; //locRoom2 7

      case 8:;
				do
				{
					cout << "\nYou are in room 8";
					cout << "1: Fight the boss?\n"
									"2: Back to the Dungeon\n";
					cin >> direct;
					if(direct == 2)
					{
						direct = 0;
						locRoom2--;
					}
					else if(direct == 1 && foughtBoss == false)
						{
							cout << "You here a slithering noise...\n";
							cout << "All of a sudden, a huge viper pops up in front of you!!!\n";
							foughtBoss = true;
							Entity boss2;
							createSecondusSerpent(boss2); // create second boss

							boss2.displayEntityStats(boss2);
							plyr.displayPlayerStats(plyr);

							attack(plyr, boss2);

							if(boss2.getHealth() < 1)
							{
								cout << "You have defeated the Secondus Serpent!\n";
								plyr.addGold(plyr, 20);
								plyr.addItemToInventory(15, plyr);
								plyr.getInventory(plyr);
								locRoom2++;
							}

							direct = 0;
							locRoom2 = 8;
						}
					else
					{
						invalidCommand();
					}
				}while(direct != 1 && direct != 2);
      break; //locRoom2 8
    } //swtich locRoom2
  } //while locRoom2
}

void loc3(Player &plyr)
{
	bool redKey = true; // all keys true because no locks first floor
	bool greenKey = true; // all keys true because no locks first floor
	bool blueKey = true; // all keys true because no locks first floor
	bool yellowKey = true; // all keys true because no locks first floor

	bool redChestIsHere = false;
	bool greenChestIsHere = false;
	bool blueChestIsHere = false;
	bool yellowChestIsHere = false;

	int itemCountMasterkey = 4;
	bool redOpen = false;
	bool greenOpen = false;
	bool blueOpen = false;
	bool yellowOpen = false;

	bool direction[4];

	int itemCount = 0;
	bool open = false;
	bool foughtBoss = false;
	char pickUp = '\0';

	int locRoom3 = 1;
  int decision = 0;
  int direct = 0;
  int passCount[11];

  Entity archr1;
  Entity archr2;
  Entity night1;
  Entity night2;
  Entity wiz1;
  createArcher(archr1);
  createArcher(archr2);
  createKnight(night1);
  createKnight(night2);
  createWizard(wiz1);

	for(int i = 0; i < 11; i++)
	{
		passCount[i] = 0;
	}

  cout << "\n\nMap loc 3\n";
  while(locRoom3 < 12)
  {
		bool move = false;
		bool validDecision = false;
		bool yesNo = false;

		redChestIsHere = false;
		greenChestIsHere = false;
		blueChestIsHere = false;
		yellowChestIsHere = false;

    switch(locRoom3)
    {
      case 1:;
				if(passCount[0] == 0)
				{
					passCount[0]++;
          while(move == false && validDecision == false)
					{
						whatToDo(1);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("yellow", yellowKey, yellowChestIsHere, open, plyr, 11);
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							invalidCommand();
							validDecision = false;
						}
					}

					direction[0] = false;
					direction[1] = false;
					direction[2] = false;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 4)
					{
						locRoom3++;
					}
				}
				else
				{
					passCount[0]++;
					cout << "You have visited this room before...\n";

					while(move == false && validDecision == false)
					{
						whatToDo(1);
						cin >> decision;
						cout << endl;

						if (decision == 1)
						{
							searchRoom("yellow", yellowKey, yellowChestIsHere, open, plyr, 11);
						}
						else if (decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							validDecision = false;
						}
					} // while not move and not good input

					direction[0] = false;
					direction[1] = false;
					direction[2] = false;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 4)
					{
						locRoom3++;
					}
				}
      break; //locRoom3 1

      case 2:;
				if(passCount[1] == 0)
				{
					passCount[1]++;
					while(move == false && validDecision == false)
					{
						whatToDo(2);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("yellow", yellowKey, yellowChestIsHere, open, plyr, 12);
						}
						else if (decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							validDecision = false;
						}
					}

					direction[0] = false;
					direction[1] = true;
					direction[2] = true;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 2)
					{
						locRoom3 += 3;
					}
					if(direct == 3)
					{
						locRoom3--;
					}
					if(direct == 4)
					{
						locRoom3 ++;
					}
				}
				else
				{
					passCount[1]++;
					cout << "You have visited this room before...\n";

					while(move == false && validDecision == false)
					{
						whatToDo(2);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("yellow", yellowKey, yellowChestIsHere, open, plyr, 12);
						}
						else if (decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							validDecision = false;
						}
					}

					direction[0] = false;
					direction[1] = true;
					direction[2] = true;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 2)
					{
						locRoom3 += 3;
					}
					if(direct == 3)
					{
						locRoom3--;
					}
					if(direct == 4)
					{
						locRoom3 ++;
					}
				}
      break; //locRoom3 2

      case 3:;
				blueChestIsHere = true;
				if(passCount[2] == 0)
				{
					passCount[2]++;

					cout << "You found an Archer!!!\nPrepare for battle\n\n";

          archr1.displayEntityStats(archr1);
          plyr.displayPlayerStats(plyr);
          attack(plyr, archr1);
          if(plyr.getHealth() > 0)
          {
            plyr.addGold(plyr, 5);
          }

					while(move == false && validDecision == false)
					{
						whatToDo(3);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("blue", blueKey, blueChestIsHere, open, plyr, 13);
						}
						else if (decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							validDecision = false;
						}
					}

					direction[0] = false;
					direction[1] = true;
					direction[2] = true;
					direction[3] = false;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 2)
					{
						locRoom3 += 3;
					}
					if(direct == 3)
					{
						locRoom3--;
					}
				}
				else
				{
					cout << "You have visited this room before...\n";
					passCount[2]++;

					while(move == false && validDecision == false)
					{
						whatToDo(3);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("blue", blueKey, blueChestIsHere, open, plyr, 13);
						}
						else if (decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							validDecision = false;
						}
					}

					direction[0] = false;
					direction[1] = true;
					direction[2] = true;
					direction[3] = false;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 2)
					{
						locRoom3 += 3;
					}
					if(direct == 3)
					{
						locRoom3--;
					}
				}
      break; //locRoom3 3

      case 4:;
				if(passCount[3] == 0)
				{
					passCount[3]++;

					cout << "You stubbled into an Archer!!!\nPrepare for battle\n\n";

          archr2.displayEntityStats(archr2);
          plyr.displayPlayerStats(plyr);
          attack(plyr, archr2);
          if(plyr.getHealth() > 0)
          {
            plyr.addGold(plyr, 5);
          }

					while(move == false && validDecision == false)
					{
						whatToDo(4);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("blue", blueKey, blueChestIsHere, open, plyr, 14);
						}
						else if (decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							validDecision = false;
						}
					}

						direction[0] = false;
						direction[1] = true;
						direction[2] = false;
						direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 2)
					{
						locRoom3 += 3;
					}
					if(direct == 4)
					{
						locRoom3++;
					}
				}
				else
				{
					cout << "You have visited this room before...\n";
					passCount[3]++;

					while(move == false && validDecision == false)
					{
						whatToDo(4);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("blue", blueKey, blueChestIsHere, open, plyr, 14);
						}
						else if (decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							validDecision = false;
						}
					}

					direction[0] = false;
					direction[1] = true;
					direction[2] = false;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 2)
					{
						locRoom3 += 3;
					}
					if(direct == 4)
					{
						locRoom3++;
					}
				}
      break; //locRoom3 4

      case 5:;
				greenChestIsHere = true;
				if(passCount[4] == 0)
				{
					passCount[4]++;
					while(move == false && validDecision == false)
					{
						whatToDo(5);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("green", greenKey, greenChestIsHere, open, plyr, 12);
						}
						else if (decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							validDecision = false;
						}
					}

					direction[0] = true;
					direction[1] = true;
					direction[2] = true;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 1)
					{
						locRoom3 -= 3;
					}
					if(direct == 2)
					{
						locRoom3 += 3;
					}
					if(direct == 3)
					{
						locRoom3--;
					}
					if(direct == 4)
					{
						locRoom3++;
					}
				}
				else
				{
					cout << "You have visited this room before...\n";
					passCount[4]++;

					while(move == false && validDecision == false)
					{
						whatToDo(5);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("green", greenKey, greenChestIsHere, open, plyr, 12);
						}
						else if (decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							validDecision = false;
						}
					}

					direction[0] = true;
					direction[1] = true;
					direction[2] = true;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 1)
					{
						locRoom3 -= 3;
					}
					if(direct == 2)
					{
						locRoom3 += 3;
					}
					if(direct == 3)
					{
						locRoom3--;
					}
					if(direct == 4)
					{
						locRoom3++;
					}
				}
      break; //locRoom3 5

      case 6:;
				if(passCount[5] == 0)
				{
					passCount[5]++;

					cout << "You walked into an Knight!!!\nPrepare for battle\n\n";

          night1.displayEntityStats(night1);
          plyr.displayPlayerStats(plyr);
          attack(plyr, night1);
          if(plyr.getHealth() > 0)
          {
            plyr.addGold(plyr, 10);
          }

					while(move == false && validDecision == false)
					{
						whatToDo(6);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("green", greenKey, greenChestIsHere, open, plyr, 15);
						}
						else if (decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							validDecision = false;
						}
					}

					direction[0] = true;
					direction[1] = false;
					direction[2] = true;
					direction[3] = false;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 1)
					{
						locRoom3 -= 3;
					}
					if(direct == 3)
					{
						locRoom3--;
					}
				}
				else
				{
					cout << "You have visited this room before...\n";
					passCount[5]++;

					while(move == false && validDecision == false)
					{
						whatToDo(6);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("green", greenKey, greenChestIsHere, open, plyr, 15);
						}
						else if (decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							validDecision = false;
						}
					}

					direction[0] = true;
					direction[1] = false;
					direction[2] = true;
					direction[3] = false;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 1)
					{
						locRoom3 -= 3;
					}
					if(direct == 3)
					{
						locRoom3--;
					}
				}
      break; //locRoom3 6

      case 7:;
				if(passCount[6] == 0)
				{
					passCount[6]++;
					while(move == false && validDecision == false)
					{
						whatToDo(7);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("green", greenKey, greenChestIsHere, open, plyr, 15);
						}
						else if (decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							validDecision = false;
						}
					}

					direction[0] = true;
					direction[1] = false;
					direction[2] = false;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 1)
					{
						locRoom3 -= 3;
					}
					if(direct == 4)
					{
						locRoom3++;
					}
				}
				else
				{
					cout << "You have visited this room before...\n";
					passCount[6]++;

					while(move == false && validDecision == false)
					{
						whatToDo(7);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("green", greenKey, greenChestIsHere, open, plyr, 15);
						}
						else if (decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							validDecision = false;
						}
					}

					direction[0] = true;
					direction[1] = false;
					direction[2] = false;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 1)
					{
						locRoom3 -= 3;
					}
					if(direct == 4)
					{
						locRoom3++;
					}
				}
      break; //locRoom3 7

      case 8:;
				redChestIsHere = true;
				if(passCount[7] == 0)
				{
					passCount[7]++;

					cout << "A Wizard appeared before you!!!\n Prepare for battle\n\n";

          wiz1.displayEntityStats(wiz1);
          plyr.displayPlayerStats(plyr);
          attack(plyr, wiz1);
          if(plyr.getHealth() > 0)
          {
            plyr.addGold(plyr, 15);
          }

					while(move == false && validDecision == false)
					{
						whatToDo(8);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("red", redKey, redChestIsHere, open, plyr, 11);
						}
						else if (decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							validDecision = false;
						}
					}

					direction[0] = true;
					direction[1] = true;
					direction[2] = true;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 1)
					{
						locRoom3 -= 3;
					}
					if(direct == 2)
					{
						locRoom3 += 2;
					}
					if(direct == 3)
					{
						locRoom3--;
					}
					if(direct == 4)
					{
						locRoom3++;
					}
				}
				else
				{
					cout << "You have visited this room before...\n";
					passCount[7]++;

					while(move == false && validDecision == false)
					{
						whatToDo(8);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("red", redKey, redChestIsHere, open, plyr, 11);
						}
						else if (decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							validDecision = false;
						}
					}

					direction[0] = true;
					direction[1] = true;
					direction[2] = true;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 1)
					{
						locRoom3 -= 3;
					}
					if(direct == 2)
					{
						locRoom3 += 2;
					}
					if(direct == 3)
					{
						locRoom3--;
					}
					if(direct == 4)
					{
						locRoom3++;
					}
				}
      break; //locRoom3 8

      case 9:;
				yellowChestIsHere = true;
				if(passCount[8] == 0)
				{
					passCount[8]++;

					cout << "You found a Knight!!!\nPrepare for battle\n\n";

          night2.displayEntityStats(night2);
          plyr.displayPlayerStats(plyr);
          attack(plyr, night2);
          if(plyr.getHealth() > 0)
          {
            plyr.addGold(plyr, 10);
          }

					while(move == false && validDecision == false)
					{
						whatToDo(9);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("yellow", yellowKey, yellowChestIsHere, open, plyr, 14);
						}
						else if (decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							validDecision = false;
						}
					}

					direction[0] = false;
					direction[1] = false;
					direction[2] = true;
					direction[3] = false;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 3)
					{
						locRoom3--;
					}
				}
				else
				{
					cout << "You have visited this room before...\n";
					passCount[8]++;

					while(move == false && validDecision == false)
					{
						whatToDo(9);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("yellow", yellowKey, yellowChestIsHere, open, plyr, 14);
						}
						else if (decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							validDecision = false;
						}
					}

					direction[0] = false;
					direction[1] = false;
					direction[2] = true;
					direction[3] = false;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 3)
					{
						locRoom3--;
					}
				}
      break; //locRoom3 9

      case 10:;
				if(passCount[9] == 0)
				{
					passCount[9]++;
					while(move == false && validDecision == false)
					{
						whatToDo(10);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("yellow", yellowKey, yellowChestIsHere, open, plyr, 14);
						}
						else if (decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							validDecision = false;
						}
					}

					direction[0] = true;
					direction[1] = false;
					direction[2] = false;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 1)
					{
						locRoom3 -= 2;
					}
					if(direct == 4)
					{
						locRoom3++;
					}
				}
				else
				{
					cout << "You have visited this room before...\n";
					passCount[9]++;

					while(move == false && validDecision == false)
					{
						whatToDo(10);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("yellow", yellowKey, yellowChestIsHere, open, plyr, 14);
						}
						else if (decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							validDecision = false;
						}
					}

					direction[0] = true;
					direction[1] = false;
					direction[2] = false;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 1)
					{
						locRoom3 -= 2;
					}
					if(direct == 4)
					{
						locRoom3++;
					}
				}
      break; //locRoom3 10

      case 11:;
				do
					{
					cout << "\nYou are in room 11";
					cout << "\n1: Fight the boss?\n"
									"2: Back to the Dungeon\n";
					cin >> direct;

					if(direct == 1 && foughtBoss == false)
					{
						cout << "A massive serpent is weaving slowly toward you...\n";
						foughtBoss = true;
						Entity boss2;
						createSecondusSerpent(boss2); // create first boss

						boss2.displayEntityStats(boss2);
						plyr.displayPlayerStats(plyr);

						attack(plyr, boss2);

						if(boss2.getHealth() < 1)
						{
							cout << "You have defeated Secondus Serpent!\n";
							plyr.addGold(plyr, 20);
							plyr.addItemToInventory(itemCountMasterkey, plyr);
							plyr.getInventory(plyr);
							locRoom3++;
						}

						direct = 0;
						locRoom3 = 12;
					}
					else if(direct == 2)
					{
						direct = 0;
						locRoom3--;
					}
					else
					{
						invalidCommand();
					}
				}while(direct != 1);
      break; //locRoom3 11
    } //swtich locRoom3
  } //while locRoom3
}

void loc4(Player &plyr)
{
	bool redKey = true; // all keys true because no locks first floor
	bool greenKey = true; // all keys true because no locks first floor
	bool blueKey = true; // all keys true because no locks first floor
	bool yellowKey = true; // all keys true because no locks first floor

	bool redChestIsHere = false;
	bool greenChestIsHere = false;
	bool blueChestIsHere = false;
	bool yellowChestIsHere = false;
	bool redChestIsHereTemp = false;
	bool greenChestIsHereTemp = false;
	bool blueChestIsHereTemp = false;
	bool yellowChestIsHereTemp = false;

	int itemCountMasterkey = 4;
	bool redOpen = false;
	bool greenOpen = false;
	bool blueOpen = false;
	bool yellowOpen = false;

	bool direction[4];

	int itemCount = 0;
	bool open = false;
	bool foughtBoss = false;
	char pickUp = '\0';

	int locRoom4 = 1;
  int decision = 0;
  int direct = 0;
  int passCount[14];

  Entity archr1;
  Entity archr2;
  Entity night1;
  Entity night2;
  Entity night3;
  Entity wiz1;
  Entity wiz2;
  createArcher(archr1);
  createArcher(archr2);
  createKnight(night1);
  createKnight(night2);
  createKnight(night3);
  createWizard(wiz1);
  createWizard(wiz2);

	for(int i = 0; i < 14; i++)
	{
		passCount[i] = 0;
	}

  cout << "Map loc 4\n";
  while(locRoom4 < 15)
  {
		bool move = false;
		bool validDecision = false;
		bool yesNo = false;

		redChestIsHere = false;
		greenChestIsHere = false;
		blueChestIsHere = false;
		yellowChestIsHere = false;

    switch(locRoom4)
    {
      case 1:;
				if(passCount[0] == 0)
				{
					passCount[0]++;
					while(move == false && validDecision == false)
					{
						whatToDo(1);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("yellow", yellowKey, yellowChestIsHere, open, plyr, 11);
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							invalidCommand();
							validDecision = false;
						}
					}

					direction[0] = false;
					direction[1] = true;
					direction[2] = false;
					direction[3] = false;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 2)
					{
						locRoom4 += 3;
					}
				}
				else
				{
					passCount[0]++;
					cout << "You have visited this room before...\n";

					while(move == false && validDecision == false)
					{
						whatToDo(1);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("yellow", yellowKey, yellowChestIsHere, open, plyr, 11);
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							invalidCommand();
							validDecision = false;
						}
					}

					direction[0] = false;
					direction[1] = true;
					direction[2] = false;
					direction[3] = false;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 2)
					{
						locRoom4 += 3;
					}
				}
      break; //locRoom4 1

      case 2:;
				if(passCount[1] == 0)
				{
					passCount[1]++;
					while(move == false && validDecision == false)
					{
						whatToDo(2);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("yellow", yellowKey, yellowChestIsHere, open, plyr, 11);
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							invalidCommand();
							validDecision = false;
						}
					}

					direction[0] = false;
					direction[1] = true;
					direction[2] = false;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 2)
					{
						locRoom4 += 3;
					}
					if(direct == 4)
					{
						locRoom4++;
					}
				}
				else
				{
					passCount[1]++;
					cout << "You have visited this room before...\n";

					while(move == false && validDecision == false)
					{
						whatToDo(2);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("yellow", yellowKey, yellowChestIsHere, open, plyr, 11);
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							invalidCommand();
							validDecision = false;
						}
					}

					direction[0] = false;
					direction[1] = true;
					direction[2] = false;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 2)
					{
						locRoom4 += 3;
					}
					if(direct == 4)
					{
						locRoom4++;
					}
				}
      break; //locRoom4 2

      case 3:;
				yellowChestIsHere = true;
				yellowChestIsHereTemp = yellowChestIsHere;
				if(passCount[2] == 0)
				{
					passCount[2]++;

					cout << "You stubbled into an Knight!!!\nPrepare for battle\n\n";

          night1.displayEntityStats(night1);
          plyr.displayPlayerStats(plyr);
          attack(plyr, night1);
          if(plyr.getHealth() > 0)
          {
            plyr.addGold(plyr, 10);
          }

					while(move == false && validDecision == false)
					{
						whatToDo(3);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("yellow", yellowKey, yellowChestIsHere, open, plyr, 19);
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							invalidCommand();
							validDecision = false;
						}
					}

					direction[0] = false;
					direction[1] = true;
					direction[2] = true;
					direction[3] = false;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 2)
					{
						locRoom4 += 3;
					}
					if(direct == 3)
					{
						locRoom4--;
					}
				}
				else
				{
					passCount[2]++;
					cout << "You have visited this room before...\n";

					while(move == false && validDecision == false)
					{
						whatToDo(3);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("yellow", yellowKey, yellowChestIsHereTemp, open, plyr, 19);
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							invalidCommand();
							validDecision = false;
						}
					}

					direction[0] = false;
					direction[1] = true;
					direction[2] = true;
					direction[3] = false;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 2)
					{
						locRoom4 += 3;
					}
					if(direct == 3)
					{
						locRoom4--;
					}
				}
      break; //locRoom4 3

      case 4:;
				if(passCount[3] == 0)
				{
					passCount[3]++;
					while(move == false && validDecision == false)
					{
						whatToDo(4);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("yellow", yellowKey, yellowChestIsHere, open, plyr, 19);
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							invalidCommand();
							validDecision = false;
						}
					}

					direction[0] = true;
					direction[1] = false;
					direction[2] = false;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 1)
					{
						locRoom4 -= 3;
					}
					if(direct == 4)
					{
						locRoom4++;
					}
				}
				else
				{
					passCount[3]++;
					cout << "You have visited this room before...\n";

					while(move == false && validDecision == false)
					{
						whatToDo(4);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("yellow", yellowKey, yellowChestIsHere, open, plyr, 19);
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							invalidCommand();
							validDecision = false;
						}
					}

					direction[0] = true;
					direction[1] = false;
					direction[2] = false;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 1)
					{
						locRoom4 -= 3;
					}
					if(direct == 4)
					{
						locRoom4++;
					}
				}
      break; //locRoom4 4

      case 5:;
				blueChestIsHere = true;
				blueChestIsHereTemp = blueChestIsHere;
				if(passCount[4] == 0)
				{
					passCount[4]++;

					cout << "You found an Archer!!!\nPrepare for battle\n\n";

          archr1.displayEntityStats(archr1);
          plyr.displayPlayerStats(plyr);
          attack(plyr, archr1);
          if(plyr.getHealth() > 0)
          {
            plyr.addGold(plyr, 5);
          }

					while(move == false && validDecision == false)
					{
						whatToDo(5);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("blue", blueKey, blueChestIsHere, open, plyr, 18);
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							invalidCommand();
							validDecision = false;
						}
					}

					direction[0] = true;
					direction[1] = true;
					direction[2] = true;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 1)
					{
						locRoom4 -= 3;
					}
					if(direct == 2)
					{
						locRoom4 += 3;
					}
					if(direct == 3)
					{
						locRoom4--;
					}
					if(direct == 4)
					{
						locRoom4++;
					}
				}
				else
				{
					passCount[3]++;
					cout << "You have visited this room before...\n";

					while(move == false && validDecision == false)
					{
						whatToDo(5);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("blue", blueKey, blueChestIsHereTemp, open, plyr, 18);
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							invalidCommand();
							validDecision = false;
						}
					}

					direction[0] = true;
					direction[1] = true;
					direction[2] = true;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 1)
					{
						locRoom4 -= 3;
					}
					if(direct == 2)
					{
						locRoom4 += 3;
					}
					if(direct == 3)
					{
						locRoom4--;
					}
					if(direct == 4)
					{
						locRoom4++;
					}
				}
      break; //locRoom4 5

      case 6:;
				if(passCount[5] == 0)
				{
					passCount[5]++;
					while(move == false && validDecision == false)
					{
						whatToDo(6);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("blue", blueKey, blueChestIsHere, open, plyr, 18);
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							invalidCommand();
							validDecision = false;
						}
					}

					direction[0] = true;
					direction[1] = true;
					direction[2] = true;
					direction[3] = false;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 1)
					{
						direct = 0;
						locRoom4 -= 3;
					}
					if(direct == 2)
					{
						direct = 0;
						locRoom4 += 3;
					}
					if(direct == 3)
					{
						direct = 0;
						locRoom4--;
					}
				}
				else
				{
					passCount[5]++;
					cout << "You have visited this room before...\n";

					while(move == false && validDecision == false)
					{
						whatToDo(6);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("blue", blueKey, blueChestIsHere, open, plyr, 18);
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							invalidCommand();
							validDecision = false;
						}
					}

					direction[0] = true;
					direction[1] = true;
					direction[2] = true;
					direction[3] = false;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 1)
					{
						locRoom4 -= 3;
					}
					if(direct == 2)
					{
						locRoom4 += 3;
					}
					if(direct == 3)
					{
						locRoom4--;
					}
				}
      break; //locRoom4 6

      case 7:;
				redChestIsHere = true;
				redChestIsHereTemp = redChestIsHere;
				if(passCount[6] == 0)
				{
					passCount[6]++;

					cout << "You walked into an Archer!!!\nPrepare for battle\n\n";

          archr2.displayEntityStats(archr2);
          plyr.displayPlayerStats(plyr);
          attack(plyr, archr2);
          if(plyr.getHealth() > 0)
          {
            plyr.addGold(plyr, 5);
          }

					while(move == false && validDecision == false)
					{
						whatToDo(7);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("red", redKey, redChestIsHere, open, plyr, 16);
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							invalidCommand();
							validDecision = false;
						}
					}

					direction[0] = false;
					direction[1] = true;
					direction[2] = false;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 2)
					{
						locRoom4 += 3;
					}
					if(direct == 4)
					{
						locRoom4++;
					}
				}
				else
				{
					passCount[6]++;
					cout << "You have visited this room before...\n";

					while(move == false && validDecision == false)
					{
						whatToDo(7);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("red", redKey, redChestIsHereTemp, open, plyr, 16);
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							invalidCommand();
							validDecision = false;
						}
					}

					direction[0] = false;
					direction[1] = true;
					direction[2] = false;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 2)
					{
						locRoom4 += 3;
					}
					if(direct == 4)
					{
						locRoom4++;
					}
				}
      break; //locRoom4 7

      case 8:;
				if(passCount[7] == 0)
				{
					passCount[7]++;
					while(move == false && validDecision == false)
					{
						whatToDo(8);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("red", redKey, redChestIsHere, open, plyr, 16);
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							invalidCommand();
							validDecision = false;
						}
					}

					direction[0] = true;
					direction[1] = true;
					direction[2] = true;
					direction[3] = false;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 1)
					{
						locRoom4 -= 3;
					}
					if(direct == 2)
					{
						locRoom4 += 3;
					}
					if(direct == 3)
					{
						locRoom4--;
					}
				}
				else
				{
					passCount[7]++;
					cout << "You have visited this room before...\n";

					while(move == false && validDecision == false)
					{
						whatToDo(8);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("red", redKey, redChestIsHere, open, plyr, 16);
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							invalidCommand();
							validDecision = false;
						}
					}

					direction[0] = true;
					direction[1] = true;
					direction[2] = true;
					direction[3] = false;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 1)
					{
						locRoom4 -= 3;
					}
					if(direct == 2)
					{
						locRoom4 += 3;
					}
					if(direct == 3)
					{
						locRoom4--;
					}
				}
      break; //locRoom4 8

      case 9:;
				if(passCount[8] == 0)
				{
					passCount[8]++;

					cout << "You found a Knight!!!\nPrepare for battle\n\n";

          night2.displayEntityStats(night2);
          plyr.displayPlayerStats(plyr);
          attack(plyr, night2);
          if(plyr.getHealth() > 0)
          {
            plyr.addGold(plyr, 10);
          }

					while(move == false && validDecision == false)
					{
						whatToDo(9);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("red", redKey, redChestIsHere, open, plyr, 16);
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							invalidCommand();
							validDecision = false;
						}
					}

					direction[0] = true;
					direction[1] = true;
					direction[2] = false;
					direction[3] = false;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 1)
					{
						locRoom4 -= 3;
					}
					if(direct == 2)
					{
						locRoom4 += 3;
					}
				}
				else
				{
					passCount[8]++;
					cout << "You have visited this room before...\n";

					while(move == false && validDecision == false)
					{
						whatToDo(9);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("red", redKey, redChestIsHere, open, plyr, 16);
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							invalidCommand();
							validDecision = false;
						}
					}

					direction[0] = true;
					direction[1] = true;
					direction[2] = false;
					direction[3] = false;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 1)
					{
						locRoom4 -= 3;
					}
					if(direct == 2)
					{
						locRoom4 += 3;
					}
				}
      break; //locRoom4 9

      case 10:;
				greenChestIsHere = true;
				greenChestIsHereTemp = greenChestIsHere;
				if(passCount[9] == 0)
				{
					passCount[9]++;
					while(move == false && validDecision == false)
					{
						whatToDo(10);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("green", greenKey, greenChestIsHere, open, plyr, 17);
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							invalidCommand();
							validDecision = false;
						}
					}

					direction[0] = true;
					direction[1] = false;
					direction[2] = false;
					direction[3] = false;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 1)
					{
						locRoom4 -= 3;
					}
				}
				else
				{
					passCount[9]++;
					cout << "You have visited this room before...\n";

					while(move == false && validDecision == false)
					{
						whatToDo(10);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("green", greenKey, greenChestIsHereTemp, open, plyr, 17);
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							invalidCommand();
							validDecision = false;
						}
					}

					direction[0] = true;
					direction[1] = false;
					direction[2] = false;
					direction[3] = false;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 1)
					{
						locRoom4 -= 3;
					}
				}
      break; //locRoom4 10

      case 11:;
				if(passCount[10] == 0)
				{
					passCount[10]++;

          cout << "You stubbled into an Knight!!!\nPrepare for battle\n\n";

          night3.displayEntityStats(night3);
          plyr.displayPlayerStats(plyr);
          attack(plyr, night3);
          if(plyr.getHealth() > 0)
          {
            plyr.addGold(plyr, 10);
          }

					while(move == false && validDecision == false)
					{
						whatToDo(11);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("red", redKey, redChestIsHere, open, plyr, 16);
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							invalidCommand();
							validDecision = false;
						}
					}

					direction[0] = true;
					direction[1] = false;
					direction[2] = false;
					direction[3] = false;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 1)
					{
						locRoom4 -= 3;
					}
				}
				else
				{
					passCount[10]++;
					cout << "You have visited this room before...\n";

					while(move == false && validDecision == false)
					{
						whatToDo(11);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("red", redKey, redChestIsHere, open, plyr, 16);
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							invalidCommand();
							validDecision = false;
						}
					}

					direction[0] = true;
					direction[1] = false;
					direction[2] = false;
					direction[3] = false;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 1)
					{
						locRoom4 -= 3;
					}
				}
      break; //locRoom4 11

      case 12:;
				if(passCount[11] == 0)
				{
					passCount[11]++;

					cout << "A Wizard appeared before you!!!\n Prepare for battle\n\n";

          wiz1.displayEntityStats(wiz1);
          plyr.displayPlayerStats(plyr);
          attack(plyr, wiz1);
          if(plyr.getHealth() > 0)
          {
            plyr.addGold(plyr, 15);
          }

					while(move == false && validDecision == false)
					{
						whatToDo(12);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("red", redKey, redChestIsHere, open, plyr, 16);
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							invalidCommand();
							validDecision = false;
						}
					}

					direction[0] = true;
					direction[1] = false;
					direction[2] = false;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 1)
					{
						direct = 0;
						locRoom4 -= 3;
					}
					if(direct == 4)
					{
						direct = 0;
						locRoom4++;
					}
				}
				else
				{
					passCount[11]++;
					cout << "You have visited this room before...\n";

					while(move == false && validDecision == false)
					{
						whatToDo(12);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("red", redKey, redChestIsHere, open, plyr, 16);
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							invalidCommand();
							validDecision = false;
						}
					}

					direction[0] = true;
					direction[1] = false;
					direction[2] = false;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 1)
					{
						direct = 0;
						locRoom4 -= 3;
					}
					if(direct == 4)
					{
						direct = 0;
						locRoom4++;
					}
				}
      break; //locRoom4 12

      case 13:;
				if(passCount[12] == 0)
				{
					passCount[12]++;

          cout << "You walked into a Wizard!!!\n Prepare for battle\n\n";

          wiz2.displayEntityStats(wiz2);
          plyr.displayPlayerStats(plyr);
          attack(plyr, wiz2);
          if(plyr.getHealth() > 0)
          {
            plyr.addGold(plyr, 15);
          }

					while(move == false && validDecision == false)
					{
					 whatToDo(13);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("red", redKey, redChestIsHere, open, plyr, 16);
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							invalidCommand();
							validDecision = false;
						}
					}

					direction[0] = false;
					direction[1] = false;
					direction[2] = true;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 3)
					{
						locRoom4--;
					}
					if(direct == 4)
					{
						locRoom4++;
					}
				}
				else
				{
					passCount[12]++;
					cout << "You have visited this room before...\n";

					while(move == false && validDecision == false)
					{
					 whatToDo(13);
						cin >> decision;
						if(decision == 1)
						{
							searchRoom("red", redKey, redChestIsHere, open, plyr, 16);
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							invalidCommand();
							validDecision = false;
						}
					}

					direction[0] = false;
					direction[1] = false;
					direction[2] = true;
					direction[3] = true;

					moveNextRoom(direct, direction, validDecision);

					if(direct == 3)
					{
						locRoom4--;
					}
					if(direct == 4)
					{
						locRoom4++;
					}
				}
      break; //locRoom4 13

      case 14:;
				do
					{
					cout << "\nYou are in room 14";
					cout << "\n1: Fight the boss?\n"
									"2: Back to the Dungeon\n";
					cin >> direct;

					if(direct == 1 && foughtBoss == false)
					{
						cout << "You have reached the throne room...\n";
						cout << "Lord Farquaad is sitting, looking very angry...\n";
						cout << "He gets up and asks how in the world you mannaged to finally find him!\n";
						cout << "Suddenly he draws his sword and charges at you with lightning speed!!!\n";
						foughtBoss = true;
						Entity boss4;
						createLordFarquaad(boss4); // create first boss

						boss4.displayEntityStats(boss4);
						plyr.displayPlayerStats(plyr);

						attack(plyr, boss4);

						if(boss4.getHealth() < 1)
						{
							cout << "You have defeated Lord Farquaad!\n";
							plyr.addGold(plyr, 20);
							plyr.addItemToInventory(20, plyr);
							plyr.getInventory(plyr);
							locRoom4++;
						}
					}
					else if(direct == 2)
					{
						direct = 0;
						locRoom4--;
					}
					else
					{
						invalidCommand();
					}
				}while(direct != 1 && direct != 2);
      break; //locRoom4 14
    } //swtich locRoom4
  } //while locRoom4
}

void attack(Player plyr, Entity entity)
{
	int turn = 2;
	char cont = '\0';
	int healthEnemy = entity.getHealth();
	int yourHealth = plyr.getHealth();

	if (plyr.getSpeed() > entity.getSpeed())
	{
		turn++;
		cout << "You attack first!" << endl;
		entity.setHealth(healthEnemy -= (plyr.getAttack() - entity.getArmor()));
		cout << "Press [e] to proceed to next turn...\n";
			cin >> cont;
			cout << endl;
			while (cont != 'e')
			{
				cout << "Invalid command!\n";
			}
	}
	else
	{
		cout << "The enemy is quicker and attacks you first!" << endl;
		plyr.setHealth(yourHealth -= (entity.getAttack() - plyr.getArmor()));
		cout << "Press [e] to proceed to next turn...\n";
			cin >> cont;
			cout << endl;
			while (cont != 'e')
			{
				cout << "Invalid command!\n";
			}
	}

  entity.displayEntityStats(entity);
  plyr.displayPlayerStats(plyr);

	while(plyr.getHealth() > 0 && entity.getHealth() > 0)
	{
		if (turn % 2 == 0)
		{
			cout << "It's your turn to attack!\nPress [e] to proceed to"
              "next turn...\n";
			cin >> cont;
			cout << endl;
			while (cont != 'e')
			{
				cout << "Invalid command!\n";
			}
			entity.setHealth(healthEnemy -= (plyr.getAttack() - entity.getArmor()));
		}
		else
		{
			cout << "It's the enemy's turn to attack!\nPress [e] to proceed to"
              "next turn...\n";
			cin >> cont;
			cout << endl;
			while (cont != 'e')
			{
				cout << "Invalid command!\n";
			}
			plyr.setHealth(yourHealth -= (entity.getAttack() - plyr.getArmor()));
		}

		entity.displayEntityStats(entity);
		plyr.displayPlayerStats(plyr);

		turn++;
	}
	
	if(plyr.getHealth() <= 0)
	{
		cout << "\n\nYou have just been slain\n";
		cout << "You had aquired " << plyr.getGold() << " gold coins";
		exit(1);
	}
}

void store(Player &plyr)
{
	int choice = 0;
	int buy = 0;
	bool exit = false;
	cout << "Welcome to the Secret Store!\nWould you like to buy something?"
       << endl;
	cout << "[1] No\n[2] Not sure yet, what do you have to offer?" << endl;
	cin >> choice;

	switch(choice)
	{
	case 1:
		cout << "Okay, have a nice day." << endl;
		break;
	case 2:
		while(exit = false)
		{
			cout << "Here are the items available:\n\n[1] Oblivion Staff\n+50 "
              "Attack\n100g\n\n[2] Boots of Speed\n+5 Speed\n40g\n\n[3]"
              " Dragon Scale Cape\n+50 Armor\n100g\n\n[4] Belt of Youth\n"
              "+100 HP\n60g\n\n[5] Blood Dagger\n+25 Attack\n40g\n\n"
              "Select one of these items or press [6] to exit the shop.\n\n"
              " (You have" << plyr.getGold() << "g)" << endl;
			cin >> buy;

			switch(buy)
			{
				case 1:
					if(plyr.getGold() >= 100)
					{
						cout << "You have bought the Oblivion Staff!\n";
						plyr.addItemToInventory(21, plyr);
						plyr.subtGold(plyr, 100);
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
						plyr.addItemToInventory(22, plyr);
						plyr.subtGold(plyr, 40);
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
						plyr.addItemToInventory(23, plyr);
						plyr.subtGold(plyr, 100);
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
						plyr.addItemToInventory(24, plyr);
						plyr.subtGold(plyr, 60);
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
						plyr.addItemToInventory(25, plyr);
						plyr.subtGold(plyr, 40);
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

void createWizard(Entity &wzrd)
{
	wzrd.setName("Wizard");
	wzrd.setAttack(20);
	wzrd.setHealth(25);
	wzrd.setTotalHealth(25);
	wzrd.setArmor(0);
	wzrd.setSpeed(2);
}

void createKnight(Entity &knght)
{
	knght.setName("Knight");
	knght.setAttack(15);
	knght.setHealth(25);
	knght.setTotalHealth(25);
	knght.setArmor(5);
	knght.setSpeed(1);
}

void createArcher(Entity &archr)
{
	archr.setName("Archer");
	archr.setAttack(15);
	archr.setHealth(20);
	archr.setTotalHealth(20);
	archr.setArmor(2);
	archr.setSpeed(4);
}

void createPrimusRatticus(Entity &priRat)
{
	priRat.setName("Primus Ratticus");
	priRat.setAttack(25);
	priRat.setHealth(25);
	priRat.setTotalHealth(25);
	priRat.setArmor(5);
	priRat.setSpeed(3);
}

void createSecondusSerpent(Entity &secSerp)
{
	secSerp.setName("Secondus Serpent");
	secSerp.setAttack(30);
	secSerp.setHealth(20);
	secSerp.setTotalHealth(20);
	secSerp.setArmor(15);
	secSerp.setSpeed(5);
}

void createStagOfTertius(Entity &stagTert)
{
	stagTert.setName("Stag of Tertius");
	stagTert.setAttack(20);
	stagTert.setHealth(120);
	stagTert.setTotalHealth(120);
	stagTert.setArmor(20);
	stagTert.setSpeed(4);
}

void createLordFarquaad(Entity &lordF)
{
	lordF.setName("Lord Farquaad");
	lordF.setAttack(100);
	lordF.setHealth(100);
	lordF.setTotalHealth(100);
	lordF.setArmor(35);
	lordF.setSpeed(10);
}

void openTheChest(bool key, Player plyr, bool &open, int item)
{
	char openChest;
	open = false;

	do
	{
		cin >> openChest;
		cout << endl;
		switch(openChest)
		{
				case 'y':
					if(key == true)
					{
						cout << "You have aquired the "
                 << plyr.getInventoryString(item - 1) << "!\n";
						open = true;
					}
					else
					{
						cout << "You need a key that you do not have to"
                    "open this chest...\n";
						cout << "Go find the key!" << endl;
					}
				break;

				case 'n':
					cout << "You decide not to open the chest.\n";
				break;

				default:
					cout << "Invalid choice! Would you like to open the chest?\n"
						<< "[y] yes\n[n] no\n";
		}
	}while(openChest != 'y' && openChest != 'n');
}
