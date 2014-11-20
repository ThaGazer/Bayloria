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

#include <iostream>
#include <cstdlib>

#include "Functions.h"

using namespace std;

int main()
{
  int locMain = 1;
  int locRoom1 = 1;
  int locRoom2 = 1;
  int locRoom3 = 1;
  int locRoom4 = 1;
  int keys = 0;
  int direct = 0;
  int startChoice = 0;
  string playNam = "";
  bool gameReady = false;


  while(gameReady == false)
  {
    cout << "To start hit 1\n";
    cout << "For instruction hit 2\n";
    cout << "To exit game hit 3\n";
    cin >> startChoice;

    if(startChoice == 1)
    {
      cout << "plz enter da name: ";
      cin >> playNam;
      Player p1(10, 10, 5, 1.0, playNam);
      gameReady = true;
    }
    else if(startChoice == 2)
    {
      instructions();
      startChoice = 0;
    }
    else if(startChoice == 3)
    {
      exit(1);
    }
    else
    {
      startChoice == 0;
    }
  }

  while(keys < 4)
  {
    switch(locMain)
    {
      case 1:;
        loc1();
        keys++;
        locMain++;
      break; //locMain 1

      case 2:;
        loc2();
        keys++;
        locMain++;
      break; //case 2

      case 3:;
        loc3();
        keys++;
        locMain++;
      break; //case 3

      case 4:;
        loc4();
        keys++;
        locMain++;
      break; //case 4
    }
  }

  return 0;
}

