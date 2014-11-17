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

class smallEnemies
{
  private:
    int attackDam;
    int health;
    int armor;
  public:
    smallEnemies()
    {
      attackDam = 0;
      health = 0;
      armor = 0;
    }
    
    smallEnemies(int att, int heal, int arm)
    {
      attackDam = att;
      health = heal;
      armor = arm;
    }
    
    int getHealth()
    {
      return health;
    }
    
    int getAttack()
    {
      return attackDam;
    }
    
    int getArmor()
    {
      return armor;
    }
    
    void setHealth(int heal)
    {
      health = heal;
    }
    
    void setAttack(int att)
    {
      attackDam = att;
    }
    
    void setArmor(int arm)
    {
      armor = arm;
    }
  
}
