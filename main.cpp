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
  int locRoom = 1;
  int keys = 0;
  
  while(keys < 5)
  {
    switch(locMain)
    {
      case 1:;
        cout << "Map loc 1";
        while(locRoom < 6)
        {
          switch(locRoom)
          {
            case 1:;
              cout << "Room 1";
              locRoom++;
            break; //locRoom 1
            
            case 2:;
              cout << "Room 2";
              locRoom++;
            break; //locRoom 2
            
            case 3:;
              cout << "Room 3";
              locRoom++;
            break; //locRoom 3
            
            case 4:;
              cout << "Room 4";
              locRoom++;
            break; //locRoom 4
            
            case 5:;
              cout << "Room 5";
              locRoom++;
            break; //locRoom 5
          } //swtich locRoom
        } //while locRoom
        locMain++;
      break; //locMain 1
      
      case 2:;
        cout << "Map loc 2";
        locMain++;
      
      break; //case 2
      
      case 3:;
        cout << "Map loc 3";
        locMain++;
      break; //case 3
      
      case 4:;
        cout << "Map loc 4";
        locMain++;
      break; //case 4
      
    }
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}
