/****************************************************************************************************
* * Program name: CS162 Group Project
* * Group number: # 29
* * Group member: Taekyoung Kim, Zuhair Ahmed
* * Date: 02/10/2019
* * Description: This is Ant.h file for CS162 GroupProject
* * This project demonstrates a 2D simulation of Predator-Prey Game.
* * The board is a 2D array and each cell points to a Critter.
******************************************************************************************************/



#ifndef ANT_H
#define ANT_H
#include "Critter.h"

class Ant : public Critter
{

private:

public:

    Ant();
    ~Ant() override;
    void move(Critter***) override;
    void breed(Critter***) override;
    bool starve() override  // Return false because it never starves.
    { return false; }
};


#endif //ANT_H
