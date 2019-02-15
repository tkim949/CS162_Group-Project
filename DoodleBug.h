/****************************************************************************************************
* * Program name: CS162 Group Project
* * Group number: # 29
* * Group member: Taekyoung Kim, Zuhair Ahmed
* * Date: 02/10/2019
* * Description: This is DoodleBug.h file for CS162 GroupProject
* * This project demonstrates a 2D simulation of Predator-Prey Game.
* * The board is a 2D array and each cell points to a Critter.
******************************************************************************************************/



#ifndef DOODLEBUG_H
#define DOODLEBUG_H
#include "Critter.h"

class DoodleBug :
        public Critter
{

private:

    int dayOfStarve = 0;

public:

    DoodleBug();
    ~DoodleBug() override;

    int getDayOfStarve();
    void setDayOfStarve(int d);
    bool starve() override;	// Check if a doodlebug starves to death
    void move(Critter*** b) override;
    void breed(Critter*** b) override;

};


#endif //DOODLEBUG_H
