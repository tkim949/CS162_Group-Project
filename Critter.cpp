/************************************************************************************************
* * Created by Taekyoung Kim on 2019-02-10.
* * This was orginally the group project for CS162, but this is my own work.
* * While I was waiting for other group members' work done to do debugging or checking,
* * I tried to do this and thankfully, it works well.
* * Critter.cpp file
*********************************************************************************************/


#include "Critter.h"

Critter::Critter() =default;

Critter::~Critter()=default;

/**************************
int Critter::getAge() const{
    return this->age;
}
void Critter::setAge(int a){
    age = a;
}


Critter::Critter(Type ty){
    this->type = ty;
}

Critter::Critter( int x, int y){
    this->locX =x;
    this->locY = y;
}
********************************/

Critter::Critter(int x, int y, Type ty){
    this->locX =x;
    this->locY = y;
    this->type = ty;
}


/***********************
std::string Critter::getName(){
    return name;
}
void Critter::setName(std::string na){
    this->name=na;
}
****************************/

Type Critter::getType() {

    return this->type;
}

void Critter::setType(Type tp){
    type = tp;
}


int Critter::getX() const{

    return this->locX;

}

void Critter::setX(int x) {
    locX = x;
}
int Critter::getY() const {

    return this->locY;

}

void Critter::setY(int y){

    locY = y;
}
/********************
bool Critter::getGoMove() const{

    return this-> goMove;
}

void Critter::setGoMove(bool p) {

    goMove = p;
}
***************************/
/***********************************

void Critter::move(Critter*** c){

    //std::cout<<"Inside move() in Critter class."<<std::endl;

}

void Critter::breed(Critter*** c){

    // std::cout<<"Inside move() in Critter class."<<std::endl;

}****************************************************/