/****************************************************************************************************
* * Program name: CS162 Group Project
* * Group number: # 29
* * Group member: Taekyoung Kim, Zuhair Ahmed
* * Date: 02/10/2019
* * Description: This is Critter.cpp file for CS162 GroupProject
* * This project demonstrates a 2D simulation of Predator-Prey Game.
******************************************************************************************************/


#include "Critter.h"

//default constructor
Critter::Critter() =default;

//default destructor
Critter::~Critter()=default;

//Constructor
Critter::Critter(int x, int y, Type ty){
    this->locX =x;
    this->locY = y;
    this->type = ty;
}

//Accessor for Type
Type Critter::getType() {

    return this->type;
}

//Modifier for Type
void Critter::setType(Type tp){
    type = tp;
}

//Accessor for locX
int Critter::getX() const{

    return this->locX;

}
//Modifier for locX
void Critter::setX(int x) {
    locX = x;
}

//Accessor for locY
int Critter::getY() const {

    return this->locY;
}

//Modifier for locY
void Critter::setY(int y){

    locY = y;
}
