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

#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

class smallEnemies
{
  private:
    int attackDam;
    int health;
    int armor;
  public:
    smallEnemies();
    smallEnemies(int, int, int)
    int getHealth();
    int getAttack();
    int getArmor();
    void setHealth(int);
    void setAttack(int);
    void setArmor(int);
    int attack();
}


class Player
{
  private:
    int attackDam;
    int health;
    int armor;
  public:
    Player();
    Player(int, int, int);
    int getHealth();
    int getAttack();
    int getArmor();
    void setHealth(int);
    void setAttack(int);
    void setArmor(int);
    int attack();
    
}

#endif
