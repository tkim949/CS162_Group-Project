/************************************************************************************************
* * Created by Taekyoung Kim on 2019-02-10.
* * This was orginally the group project for CS162, but this is my own work.
* * While I was waiting for other group members' work done to do debugging or checking,
* * I tried to do this and thankfully, it works well.
* * Ant.cpp file
*********************************************************************************************/


#include "Ant.h"
#include <iostream>
#include <random>


Ant::Ant()
    :Critter(-1, -1, ANT)
{}

Ant::~Ant() = default;

void Ant::move(Critter*** board) {
    //setAge(getAge() + 1);
    //setGoMove(true);

    int findSpace [4];
    int count = 0;

    if(getX() > 0 && board[getX()-1][getY()] == nullptr) {
        findSpace[count] = 1;
        count ++;
    }

    if(getX() < 19 && board[getX()+1][getY()] == nullptr) {
        findSpace[count] = 2;
        count++;
    }

    if(getY() > 0 && board[getX()][getY()-1] == nullptr) {
        findSpace[count] = 3;
        count++;
    }


    if(getY() < 19 && board[getX()][getY()+1] == nullptr) {
        findSpace[count] = 4;
        count++;
    }

    int dir;
    int output;

    if(count >0) {

        std::random_device ran;
        std::mt19937 mt(ran());
        std::uniform_int_distribution<int> dist5(0, count-1);
        output = dist5(mt);

        dir = findSpace[output];

        switch (dir) {
            case 1: //Up
                board[getX() - 1][getY()] = this;
                board[getX()][getY()] = nullptr;
                setX(getX() - 1);
                break;

            case 2: //Down
                board[getX() + 1][getY()] = this;
                board[getX()][getY()] = nullptr;
                setX(getX() + 1);
                break;

            case 3:  //left
                board[getX()][getY() - 1] = this;
                board[getX()][getY()] = nullptr;
                setY(getY() - 1);
                break;

            case 4: //right
                board[getX()][getY() + 1] = this;
                board[getX()][getY()] = nullptr;
                setY(getY() + 1);
                break;

            default:
                break;

        }
    }

}

void Ant::breed(Critter*** board) {
    breedTime++;

    if(breedTime >= 3) {

        int findSpace [4];
        int count =0;

        if(getX() > 0 && board[getX()-1][getY()] == nullptr) {
            findSpace[count] = 1;
            count ++;
        }

        if(getX() < 19 && board[getX()+1][getY()] == nullptr) {
            findSpace[count] = 2;
            count++;
        }

        if(getY() > 0 && board[getX()][getY()-1] == nullptr) {
            findSpace[count] = 3;
            count++;
        }

        if(getY() < 19 && board[getX()][getY()+1] == nullptr) {
            findSpace[count] = 4;
            count++;
        }

        if(count > 0) {
            breedTime =0;
            int chooseSpace;
            int output;
            std::random_device ran;
            std::mt19937 mt(ran());
            std::uniform_int_distribution<int> dist5(0, count-1);
            output = dist5(mt);

            chooseSpace = findSpace[output];

            //Critter* ant;

            switch (chooseSpace) {

                case 1:
                    //board[getX() - 1][getY()] = new Ant(getX() - 1, getY());
                    board[getX() - 1][getY()] = new Ant();
                    board[getX() - 1][getY()]->setType(ANT);
                    board[getX() - 1][getY()]->setX(getX()-1);
                    board[getX() - 1][getY()]->setY(getY());
                    //setAge(0);
                    break;

                case 2:
                    //board[getX() + 1][getY()] = new Ant(getX() + 1, getY());
                    board[getX() + 1][getY()] = new Ant();
                    board[getX() + 1][getY()]->setType(ANT);
                    board[getX() + 1][getY()]->setX(getX()+1);
                    board[getX() + 1][getY()]->setY(getY());
                    //setAge(0);
                    break;

                case 3:
                    //board[getX()][getY() - 1] = new Ant(getX(), getY() - 1);
                    board[getX()][getY()-1] = new Ant();
                    board[getX()][getY()-1]->setType(ANT);
                    board[getX()][getY()-1]->setX(getX());
                    board[getX()][getY()-1]->setY(getY()-1);
                    //setAge(0);
                    break;

                case 4:
                    //board[getX()][getY() + 1] = new Ant(getX(), getY() + 1);
                    board[getX()][getY()+1] = new Ant();
                    board[getX()][getY()+1]->setType(ANT);
                    board[getX()][getY()+1]->setX(getX());
                    board[getX()][getY()+1]->setY(getY()+1);
                    //setAge(0);
                    break;

                default:
                    break;

            }
        }

    }

}


