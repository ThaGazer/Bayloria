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

#include "Functions.h"
#include "Entity.h"
#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
  int starter;
  bool game = true;

  while(game == true)
  {
    cout << "[1] Start game\n";
    cout << "[2] instructions\n";
    cout << "[3] Description\n";
    cout << "[4] Credits\n";
    cout << "[5] Exit\n";
    cin >> starter;
    if(starter == 1)
    {
      for(int i = 0; i < 50; i++)
      {
        cout << "\n\n";
      }
      Player player1;
      player1.setName("Cole Crawford");
      player1.setAttack(10);
      player1.setTotalHealth(50);
      player1.setHealth(50);
      player1.setArmor(0);
      player1.setSpeed(1);
      player1.setGold(0);
      loc1(player1);
      loc3(player1);


      for(int i = 0; i < 50; i++)
      {
        cout << "\n\n";
      }
    }
    if(starter == 2)
    {
      for(int i = 0; i < 50; i++)
      {
        cout << "\n\n";
      }
      instructions();
    }
    if(starter == 3)
    {
      for(int i = 0; i < 50; i++)
      {
        cout << "\n\n";
      }
      description();
    }
    if(starter == 4)
    {
      for(int i = 0; i < 50; i++)
      {
        cout << "\n\n";
      }
      credits();
    }
    if(starter == 5)
    {
      game = false;
    }
	}

	return 0;
}
