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
#include "stdafx.h"
#include "Functions.h"
#include <string>
#include <iostream>
#include <time.h>

using namespace std;

void instructions()
{
  cout <<  "The point of the game is to defeat all four of the main "
              "bosses\n and progress through the 4 levels of Bayloria\n"
              "To play the game all you have to do is enter the four numbers\n"
							"that relate to the door you want to go through:\n"
              "1 to go north, 2 to go south, 3 to go west, and 4 to go east\n"
              "Certain door will be locked, you can unlock these doors\n"
              "but only if you find the door keys\n"
              "There are treasure chest that are placed throughout the 4 maps\n"
              "They also have keys that are spread throughout the map\n"
              "You must collect all 4 items on the floor then kill the Boss\n"
              "on the floor and receive item of the floor\n"
              "To finish the game you must kill the final Boss and present\n"
              "all 20 items collected throughout the game.\n\n";
}

void whatToDo(int a)
{
	cout << "\Room " << a << endl;
  cout << "What would you like to do here?\n";
  cout << "[1] search the room\n"
          "[2] move on to the next room\n";
}

void loc1(Player plyr)
{
	bool redKey = true; // all keys true because no locks first floor
	bool greenKey = true; // all keys true because no locks first floor
	bool blueKey = true; // all keys true because no locks first floor
	bool yellowKey = true; // all keys true because no locks first floor

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
					passCount[0]++; // +1 pass into this room
					while(move == false && validDecision == false)
					{
						whatToDo(1);
						cin >> decision;
						cout << endl;

						if(decision == 1)
						{				
							if (open == false)
							{
								cout << "You look around the room and find a *red* chest...\n"
								<< "It doesn't seem to be locked.\nWould you like to open the"
								<< " chest?\n[y] yes\n[n] no\n";

								openTheChest(redKey, yesNo, plyr, itemCount, open);
								if (open == true)
								{
									plyr.addItemToInventory(itemCount, plyr);
									cout << "This item will get you started on your journey and help you escape\n"
										<< "the Dungeon of Primus. You can now more easily defeat enemies with\n"
										<< "this heavensent blade.\n\n";
								}
							}
							else
							{
								cout << "There is not much else in this room...\n\n";
							}
						} // if look around
						else if(decision == 2)
						{
							passCount[0]++; // next time you enter room, will display different message...
							move = true;
							validDecision = true;
						} // if move
						else
						{
							cout << "Invalid command!\n";
							validDecision = false;
						} // invalid input
					} // while not move and not good input

					validDecision = false;
					while(validDecision == false)
					{
						cout << "Which direction would you like to move?\n"
							<< "[1] North\n[2] South\n[3] West\n[4] East\n";
						cin >> direct;
						cout << endl;

						if(direct == 1 || direct == 2 || direct == 3)
						{
							cout << "There is not a door this way, the only thing in front of "
								<<"you is a stone wall.\nTry a different direction.\n";
							validDecision = false;
						}
						else if(direct == 4)
						{
							validDecision = true;
							direct = 0;
							locRoom1++;
						}
						else
						{
							cout << "Invalid command!\n";
							validDecision = false;
						}
					}
				} // if not been to room before
				else
				{
					passCount[0]++;
					cout << "You have visited this room before...\nIn fact this is your "
						<< passCount[0] << " pass into this room...\n";
						
					while(move == false && validDecision == false)
					{
						whatToDo(1);
						cin >> decision;
						cout << endl;

						if (decision == 1)
						{
							if (open == true)
							{
								cout << "All that is here is an opened *red* chest.\n";
							}
							else
							{
								cout << "There is an UNOPENED *red* chest.\nWould you like to open the"
								<< " chest?\n[y] yes\n[n] no\n";
								openTheChest(redKey, yesNo, plyr, itemCount, open);

								if(open == true)
								{
									plyr.addItemToInventory(itemCount, plyr);
									cout << "This item will get you started on your journey and help you escape\n"
										<< "the Dungeon of Primus. You can now more easily defeat enemies with\n"
										<< "this heavensent blade.\n";
								}
							}
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

					validDecision = false;
					while(validDecision == false)
					{
						cout << "Which direction would you like to move?\n"
							<< "[1] North\n[2] South\n[3] West\n[4] East\n";
						cin >> direct;
						cout << endl;

						if(direct == 1 || direct == 2 || direct == 3)
						{
							cout << "There is not a door this way, the only thing in front of "
								<<"you is a stone wall.\nTry a different direction.\n";
							validDecision = false;
						}
						else if(direct == 4)
						{
							validDecision = true;
							direct = 0;
							locRoom1++;
						}
						else
						{
							cout << "Invalid command!\n";
							validDecision = false;
						}
					}
				} // else already been to room
      break; //locRoom1 1

      case 2:;
				open = false;
				if(passCount[1] == 0)
				{
					passCount[1]++; // +1 pass into this room
					while(move == false && validDecision == false)
					{
						whatToDo(2);
						cin >> decision;
						cout << endl;

						if(decision == 1)
						{
							if (open == false)
							{
								cout << "You look around the room and find a *green* chest...\n"
										<< "It doesn't seem to be locked.\nWould you like to open the"
										<< " chest?\n[y] yes\n[n] no\n";
								openTheChest(redKey, yesNo, plyr, itemCount, open);

								if(open == true)
								{
									plyr.addItemToInventory(itemCount, plyr);
									cout << "This item will partially protect you from enemy strikes!\n";
								}
							}
							else
							{
								cout << "There is not much else in this room...\n\n";
							}
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							cout << "Invalid command!\n";
							validDecision = false;
						}
					}

					validDecision = false;
					while(validDecision == false)
					{
						cout << "Which direction would you like to move?\n"
							<< "[1] North\n[2] South\n[3] West\n[4] East\n";
						cin >> direct;
						cout << endl;

						if(direct == 1)
						{
							cout << "There is no door this way, just a stone wall\n";
						}
						else if(direct == 2)
						{
							validDecision = true;
							direct = 0;
							locRoom1++;
						}
						else if(direct == 3)
						{
							validDecision = true;
							direct = 0;
							locRoom1--;
						}
						else if(direct == 4)
						{
							validDecision = true;
							direct = 0;
							locRoom1 += 2;
						}
						else
						{
							cout << "Invalid command!\n";
							validDecision = false;
						}
					}
				}
				else
				{
					passCount[1]++;
					cout << "You have visited this room before...\nIn fact this is your "
						<< passCount[1] << " pass into this room...\n";

					while(move == false && validDecision == false)
					{
						whatToDo(2);
						cin >> decision;
						cout << endl;

						if (decision == 1)
						{
							if (open == true)
							{
								cout << "All that is here is an opened *green* chest.\n";
							}
							else
							{
								cout << "There is an UNOPENED *green* chest.\nWould you like to open the"
									<< " chest?\n[y] yes\n[n] no\n";
								openTheChest(redKey, yesNo, plyr, itemCount, open);

								if(open == true)
								{
									plyr.addItemToInventory(itemCount, plyr);
									cout << "This item will partially protect you from enemy strikes!\n";
								}
							}
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

					validDecision = false;
					while(validDecision == false)
					{
						cout << "Which direction would you like to move?\n"
							<< "[1] North\n[2] South\n[3] West\n[4] East\n";
						cin >> direct;
						cout << endl;

						if(direct == 1)
						{
							cout << "There is no door this way, just a stone wall\n";
						}
						else if(direct == 2)
						{
							validDecision = true;
							direct = 0;
							locRoom1++;
						}
						else if(direct == 3)
						{
							validDecision = true;
							direct = 0;
							locRoom1--;
						}
						else if(direct == 4)
						{
							validDecision = true;
							direct = 0;
							locRoom1 += 2;
						}
						else
						{
							cout << "Invalid command!\n";
							validDecision = false;
						}
					}
				} // else already been to room
      break; //locRoom1 2

      case 3:;
				open = false;
				if(passCount[2] == 0)
				{
					passCount[2]++; // +1 pass into this room
					while(move == false && validDecision == false)
					{
						whatToDo(3);
						cin >> decision;
						cout << endl;

						if(decision == 1)
						{
							if (open == false)
							{
								cout << "You look around the room and find a *blue* chest\n"
										<< "It doesn't seem to be locked.\nWould you like to open the"
										<< " chest?\n[y] yes\n[n] no\n";
								openTheChest(redKey, yesNo, plyr, itemCount, open);

								if(open == true)
								{
									plyr.addItemToInventory(itemCount, plyr);
									cout << "This item gives life to its owner.\nIt is meant to be worn on the pinky finger.\n";
								}
							}
							else
							{
								cout << "There is not much else in this room...\n\n";
							}
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							cout << "Invalid command!\n";
							validDecision = false;
						}
					}

					validDecision = false;
					while(validDecision == false)
					{
						cout << "Which direction would you like to move?\n"
							<< "[1] North\n[2] South\n[3] West\n[4] East\n";
						cin >> direct;
						cout << endl;

						if(direct != 1)
						{
							cout << "Only a wall stands before you...\n";
						}
						else if(direct == 1)
						{
							validDecision = true;
							direct = 0;
							locRoom1--;
						}
						else
						{
							cout << "Invalid command!\n";
						}
					}
				}
				else
				{
					passCount[2]++;
					cout << "You have visited this room before...\nIn fact this is your "
						<< passCount[2] << " pass into this room...\n";

					while(move == false && validDecision == false)
					{
						whatToDo(3);
						cin >> decision;
						cout << endl;

						if (decision == 1)
						{
							if (open == true)
							{
								cout << "All that is here is an opened *blue* chest.\n";
							}
							else
							{
								cout << "There is an UNOPENED *blue* chest.\nWould you like to open the"
									<< " chest?\n[y] yes\n[n] no\n";

								openTheChest(redKey, yesNo, plyr, itemCount, open);

								if(open == true)
								{
									plyr.addItemToInventory(itemCount, plyr);
									cout << "This item gives life to its owner.\nIt is meant to be worn on the pinky finger.\n";
								}
							}
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

					validDecision = false;
					while(validDecision == false)
					{
						cout << "Which direction would you like to move?\n"
							<< "[1] North\n[2] South\n[3] West\n[4] East\n";
						cin >> direct;
						cout << endl;

						if(direct != 1)
						{
							cout << "Only a wall stands before you...\n";
						}
						else if(direct == 1)
						{
							validDecision = true;
							direct = 0;
							locRoom1--;
						}
						else
						{
							cout << "Invalid command!\n";
						}
					}
				} // else already been to room
      break; //locRoom1 3

      case 4:;
				open = false;
				if(passCount[3] == 0)
				{
					passCount[3]++; // +1 pass into this room
					while(move == false && validDecision == false)
					{
						whatToDo(4);
						cin >> decision;
						cout << endl;

						if(decision == 1)
						{
							if (open == false)
							{
								cout << "You look around the room and find a *yellow* chest\n"
									<< "It doesn't seem to be locked.\nWould you like to open the"
									<< " chest?\n[y] yes\n[n] no\n";

								openTheChest(redKey, yesNo, plyr, itemCount, open);

								if(open == true)
								{
									plyr.addItemToInventory(itemCount, plyr);
									cout << "This item also gives life to its owner.\n";
								}
							}
							else
							{
								cout << "There is not much else here besides this empty chest...\n\n";
							}
						}
						else if(decision == 2)
						{
							move = true;
							validDecision = true;
						}
						else
						{
							cout << "Invalid command!\n";
							validDecision = false;
						}
					}

					validDecision = false;
					while(validDecision == false)
					{
						cout << "Which direction would you like to move?\n"
							<< "[1] North\n[2] South\n[3] West\n[4] East\n";
						cin >> direct;
						cout << endl;

						if(direct == 1 || direct == 2)
						{
							cout << "There is no door this way, just a wall\n";
						}
						else if(direct == 3)
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
						else
						{
							cout << "Invalid command!\n";
						}
					}
				}
				else
				{
					passCount[3]++;
					cout << "You have visited this room before...\nIn fact this is your "
						<< passCount[3] << " pass into this room...\n";

					while(move == false && validDecision == false)
					{
						whatToDo(4);
						cin >> decision;
						cout << endl;

						if (decision == 1)
						{
							if (open == true)
							{
								cout << "All that is here is an opened *yellow* chest.\n";
							}
							else
							{
								cout << "There is an UNOPENED *yellow* chest...\Would you like to open the"
								<< " chest?\n[y] yes\n[n] no\n"
									<< "And on second glance, you notice a shiny object laying in the dust!\nDo you want to pick it up?";
								cin >> pickUp;
								cout << endl;

								openTheChest(redKey, yesNo, plyr, itemCount, open);

								if(open == true)
								{
									plyr.addItemToInventory(itemCount, plyr);
									cout << "\n";
								}
							}
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

					validDecision = false;
					while(validDecision == false)
					{
						cout << "Which direction would you like to move?\n"
							<< "[1] North\n[2] South\n[3] West\n[4] East\n";
						cin >> direct;
						cout << endl;

						if(direct == 1 || direct == 2)
						{
							cout << "There is no door this way, just a wall\n";
						}
						else if(direct == 3)
						{
							validDecision = true;
							direct = 0;
							locRoom1 -= 2;
						}
						else if(direct == 4)
						{
							if(plyr.getDoorKeys(1) == true)
							{
								validDecision = true;
								direct = 0;
								locRoom1++;
							}
							else
							{
								cout << "This door is locked! You must go find the key!\n\n";
							}
						}
						else
						{
							cout << "Invalid command!\n";
						}
					}
				} // else already been to room*/
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
						itemCount++;
						cout << "You have defeated Raticus Primus!\n";
						plyr.addGold(plyr, 20);
						plyr.addItemToInventory(itemCount, plyr);
						plyr.getInventory(plyr);
					}

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
        whatToDo(1);
        cin >> decision;
        if(decision == 1)
        {
          cout << "You look around the room and find nothing\n";
        }
        cout << "Which direction would you like to move?\n";
        cin >> direct;
        while(direct != 2)
        {
          cout << "That door is closed\n";
          cin >> decision;
        }
        if(direct == 2)
        {
          direct = 0;
          locRoom4 += 3;
        }
      break; //locRoom4 1

      case 2:;
        whatToDo(2);
        cin >> decision;
        if(decision == 1)
        {
          cout << "You look around the room and find a door key (1)\n";
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
          locRoom4 += 3;
        }
        if(direct == 4)
        {
          direct = 0;
          locRoom4++;
        }
      break; //locRoom4 2

      case 3:;
        whatToDo(3);
        cin >> decision;
        if(decision == 1)
        {
          cout << "You look around the room and find a chest key (2)\n"
                  "and a chest (4)";
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
          locRoom4 += 3;
        }
        if(direct == 3)
        {
          direct = 0;
          locRoom4--;
        }
      break; //locRoom4 3

      case 4:;
        whatToDo(4);
        cin >> decision;
        if(decision == 1)
        {
          cout << "You look around the room and find a chest key (1)\n";
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
          locRoom4 -= 3;
        }
        if(direct == 4)
        {
          direct = 0;
          locRoom4++;
        }
      break; //locRoom4 4

      case 5:;
        whatToDo(5);
        cin >> decision;
        if(decision == 1)
        {
          cout << "You look around the room and find a chest (3)\n";
        }
        cout << "Which direction would you like to move?\n";
        cin >> direct;
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
        if(direct == 4)
        {
          direct = 0;
          locRoom4++;
        }
      break; //locRoom4 5

      case 6:;
        whatToDo(6);
        cin >> decision;
        if(decision == 1)
        {
          cout << "You look around the room and find a door key (2)\n";
        }
        cout << "Which direction would you like to move?\n";
        cin >> direct;
        while(direct == 4)
        {
          cout << "That door is closed";
          cin >> direct;
        }
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
      break; //locRoom4 6

      case 7:;
        whatToDo(7);
        cin >> decision;
        if(decision == 1)
        {
          cout << "You look around the room and find a chest key (3)\n"
                  "and a chest (1)\n";
        }
        cout << "Which direction would you like to move?\n";
        cin >> direct;
        while(direct == 1 || direct == 3)
        {
          cout << "That door is closed";
          cin >> direct;
        }
        if(direct == 2)
        {
          direct = 0;
          locRoom4 += 3;
        }
        if(direct == 4)
        {
          direct = 0;
          locRoom4++;
        }
      break; //locRoom4 7

      case 8:;
        whatToDo(8);
        cin >> decision;
        if(decision == 1)
        {
          cout << "You look around the room and find nothing\n";
        }
        cout << "Which direction would you like to move?\n";
        cin >> direct;
        while(direct == 4)
        {
          cout << "That door is closed";
          cin >> direct;
        }
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
      break; //locRoom4 8

      case 9:;
        whatToDo(9);
        cin >> decision;
        if(decision == 1)
        {
          cout << "You look around the room and find nothing\n";
        }
        cout << "Which direction would you like to move?\n";
        cin >> direct;
        while(direct == 3 || direct == 4)
        {
          cout << "That door is closed";
          cin >> direct;
        }
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
      break; //locRoom4 9

      case 10:;
        whatToDo(10);
        cin >> decision;
        if(decision == 1)
        {
          cout << "You look around the room and find a door key (3)\n"
                  "and a chest (2)\n";
        }
        cout << "Which direction would you like to move?\n";
        cin >> direct;
        while(direct != 1)
        {
          cout << "That door is closed";
          cin >> direct;
        }
        if(direct == 1)
        {
          direct = 0;
          locRoom4 -= 3;
        }
      break; //locRoom4 10

      case 11:;
        whatToDo(11);
        cin >> decision;
        if(decision == 1)
        {
          cout << "You look around the room and find a chest key (4)\n";
        }
        cout << "Which direction would you like to move?\n";
        cin >> direct;
        while(direct != 1)
        {
          cout << "That door is closed";
          cin >> direct;
        }
        if(direct == 1)
        {
          direct = 0;
          locRoom4 -= 3;
        }
      break; //locRoom4 11

      case 12:;
        whatToDo(12);
        cin >> decision;
        if(decision == 1)
        {
          cout << "You look around the room and find a door key (4)\n";
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
          locRoom4 -= 3;
        }
        if(direct == 4)
        {
          direct = 0;
          locRoom4++;
        }
      break; //locRoom4 12

      case 13:;
       whatToDo(13);
        cin >> decision;
        if(decision == 1)
        {
          cout << "You look around the room and find nothing\n";
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
          locRoom4--;
        }
        if(direct == 4)
        {
          direct = 0;
          locRoom4++;
        }
      break; //locRoom4 13

      case 14:;
        cout << "\nYou are in room 14";
        cout << "4: Fight the boss?\n"
                "3: Back to the Dungeon\n";
        cin >> direct;
        if(direct == 3)
        {
          direct = 0;
          locRoom4--;
        }
        if(direct == 4)
        {
          direct = 0;
          locRoom4++;
        }
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
		entity.setHealth(healthEnemy -= plyr.getAttack() - entity.getArmor());
	}
	else
	{
		cout << "The enemy is quicker and attacks you first!" << endl;
		plyr.setHealth(yourHealth -= entity.getAttack() - plyr.getArmor());
	}

	while(plyr.getHealth() > 0 && entity.getHealth() > 0)
	{
		if (turn % 2 == 0)
		{
			cout << "It's your turn to attack!\nPress [n] to proceed to next turn...\n";
			cin >> cont;
			cout << endl;
			while (cont != 'n')
			{
				cout << "Invalid command!\n";
			}
			plyr.setHealth(yourHealth -= (entity.getAttack() - plyr.getArmor()));
		}
		else
		{
			cout << "It's the enemy's turn to attack!\nPress [n] to proceed to next turn...\n";
			cin >> cont;
			cout << endl;
			while (cont != 'n')
			{
				cout << "Invalid command!\n";
			}
			entity.setHealth(healthEnemy -= (plyr.getAttack() - entity.getArmor()));
		}

		plyr.displayPlayerStats(plyr);
		entity.displayEntityStats(entity);
		turn++;
	}
}

void store(Player &plyr)
{
	int choice = 0;
	int buy = 0;
	bool exit = false;
	cout << "Welcome to the Secret Store!\nWould you like to buy something?" << endl;
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
			cout << "Here are the items available:\n\n[1] Oblivion Staff\n+50 Attack\n"
				<< "100g\n\n[2] Boots of Speed\n+5 Speed\n40g\n\n[3] Dragon Scale Cape\n"
				<< "+50 Armor\n100g\n\n[4] Belt of Youth\n+100 HP\n60g\n\n"
				<< "[5] Blood Dagger\n+25 Attack\n40g\n\nSelect one of these items or"
				<< " press [6] to exit the shop.\n\n (You have" << plyr.getGold() << "g)"
				<< endl;
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
	wzrd.setArmor(0);
	wzrd.setSpeed(2);
}

void createKnight(Entity &knght)
{
	knght.setName("Knight");
	knght.setAttack(15);
	knght.setHealth(25);
	knght.setArmor(5);
	knght.setSpeed(1);
}

void createArcher(Entity &archr)
{
	archr.setName("Archer");
	archr.setAttack(15);
	archr.setHealth(20);
	archr.setArmor(2);
	archr.setSpeed(4);
}

void createPrimusRatticus(Entity &priRat)
{
	priRat.setName("Primus Ratticus");
	priRat.setAttack(25);
	priRat.setHealth(25);
	priRat.setArmor(5);
	priRat.setSpeed(3);
}

void createSecondusSerpent(Entity &secSerp)
{
	secSerp.setName("Secondus Serpent");
	secSerp.setAttack(30);
	secSerp.setHealth(20);
	secSerp.setArmor(15);
	secSerp.setSpeed(5);
}

void createStagOfTertius(Entity &stagTert)
{
	stagTert.setName("Stag of Tertius");
	stagTert.setAttack(20);
	stagTert.setHealth(120);
	stagTert.setArmor(20);
	stagTert.setSpeed(4);
}

void createLordFarquaad(Entity &lordF)
{
	lordF.setName("Lord Farquaad");
	lordF.setAttack(100);
	lordF.setHealth(100);
	lordF.setArmor(35);
	lordF.setSpeed(10);
}

void openTheChest(bool key, bool yN, Player plyr, int &itemCount, bool &open)
{
	open = false;
	char openChest;
	cin >> openChest;
	cout << endl;
	switch(openChest)
	{
		while(yN == false) // input validation
		{
			case 'y':
				if(key == true)
				{
					cout << "You have aquired the " << plyr.getInventoryString(itemCount) << "!\n";
					itemCount++;
					open = true;
				}
				else
				{
					cout << "You need a key that you do not have to open this chest!\n";
				}
				yN = true;
			break;

			case 'n':
				cout << "You decide not to open the chest.\n";
				yN = true;
			break;

			default:
				cout << "Invalid choice! Would you like to open the chest?\n"
					<< "[y] yes\n[n] no\n";
		}
	}
}

