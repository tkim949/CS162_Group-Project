/****************************************************************************************************
* * Program name: CS162 Group Project
* * Group number: # 29
* * Group member: Taekyoung Kim, Zuhair Ahmed
* * Date: 02/10/2019
* * Description: This is GBoard.h file for CS162 GroupProject
* * This project demonstrates a 2D simulation of Predator-Prey Game.
* * The board is a 2D array and each cell points to a Critter.
******************************************************************************************************/


#ifndef GBOARD_H
#define GBOARD_H
#include "Critter.h"
#include "Ant.h"

class GBoard {


private:

    Critter*** board;
    const int SIZE = 20;


protected:

public:

    GBoard();
    ~GBoard();

    Critter*** setBoard();

    void fillBoard(Critter*** b);
    void displayBoard(Critter*** b);
    void oneRotate(Critter*** b);
    void deleteBoard(Critter*** b);

};


#endif //GBOARD_H
