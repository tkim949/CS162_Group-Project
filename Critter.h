/****************************************************************************************************
* * Program name: CS162 Group Project
* * Group number: # 29
* * Group member: Taekyoung Kim, Zuhair Ahmed
* * Date: 02/10/2019
* * Description: This is Critter.h file for CS162 GroupProject
* * This project demonstrates a 2D simulation of Predator-Prey Game.
* * The board is a 2D array and each cell points to a Critter.
* * The board is a 2D array and each cell points to a Critter.
******************************************************************************************************/

#ifndef CRITTER_H
#define CRITTER_H
#include <iostream>

enum Type {ANT, DOODLEBUG};

class Critter {

private:

protected:

    Type type;
    int locX;
    int locY;
    int breedTime =0;


public:

    Critter();
    virtual ~Critter();
    Critter(int x, int y, Type ty);
    Type getType();
    virtual void setType(Type ty);
    virtual int getX() const;
    virtual int getY()const;
    virtual void setX(int x);
    virtual void setY(int y);

    virtual void move(Critter*** b)=0;
    virtual void breed(Critter*** b)=0;
    virtual bool starve() = 0;
    bool moved =false;


};


#endif //CRITTER_H
