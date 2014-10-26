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
#include <string>
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

  while(keys < 5)
  {
    switch(locMain)
    {
      case 1:;
        cout << "Map loc 1\n";
        while(locRoom1 < 6)
        {
          switch(locRoom1)
          {
            case 1:;
              cout << "Room 1\n";
              locRoom1++;
            break; //locRoom1 1

            case 2:;
              cout << "Room 2\n";
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
        locMain++;
      break; //locMain 1

      case 2:;
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
        locMain++;

      break; //case 2

      case 3:;
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
        locMain++;
      break; //case 3

      case 4:;
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
        locMain++;
      break; //case 4

    }
  }














  return 0;
}
