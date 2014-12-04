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

#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include "Entity.h"
#include "Player.h"

void instructions();
void whatToDo(int);
void searchRoom(string, bool, bool &, int &, bool &, Player &, int);
void move(int &, bool [], bool &);
void invalidCommand();
void loc1(Player);
void loc2(Player);
void loc3(Player);
void loc4(Player);

void attack(Player, Entity);
void store(Player &);

void createWizard(Entity &);
void createKnight(Entity &);
void createArcher(Entity &);

void createPrimusRatticus(Entity &);
void createSecondusSerpent(Entity &);
void createStagOfTertius(Entity &);
void createLordFarquaad(Entity &);

void openTheChest(bool, Player, int &, bool &, int);

#endif
