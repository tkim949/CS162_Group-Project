/****************************************************************************************************
* * Program name: CS162 Group Project
* * Group number: # 29
* * Group member: Taekyoung Kim, Zuhair Ahmed
* * Date: 02/10/2019
* * Description: This is Ant.cpp file for CS162 GroupProject
* * This project demonstrates a 2D simulation of Predator-Prey Game.
* * The board is a 2D array and each cell points to a Critter.
******************************************************************************************************/


#include "Ant.h"
#include <iostream>
#include <random>

//constructor
Ant::Ant()
    :Critter(-1, -1, ANT)
{}

//destructor
Ant::~Ant() = default;

/**********************************************************************************************************
 * * This move() function decides where an ant goes to. To do this, it first check edge of the board then
 * * if there is empty cell near that ant. Next, count the number of empty cell assigning a number.
 * * After that, it picks one number using a random number generator. Then, that ant moves to the new cell.
 * * @param board
 ************************************************************************************************************/

void Ant::move(Critter*** board) {

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

/*************************************************************************************************************
 * * This breed() function decides how and when an ant breeds. First, it check if an ant lives 3 or more than
 * * 3 days(turns). Next, it also checks the edge of the board then if there is an empty cell near the ant.
 * * If so, it breeds. If not, it waits for the next turn.
 * * @param board
 **************************************************************************************************************/

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
            //make breedTime = 0, so count starts again from the next turn.
            breedTime = 0;
            int chooseSpace;
            int output;
            std::random_device ran;
            std::mt19937 mt(ran());
            std::uniform_int_distribution<int> dist5(0, count-1);
            output = dist5(mt);

            chooseSpace = findSpace[output];

            switch (chooseSpace) {

                case 1: //up
                    board[getX() - 1][getY()] = new Ant();
                    board[getX() - 1][getY()]->setType(ANT);
                    board[getX() - 1][getY()]->setX(getX()-1);
                    board[getX() - 1][getY()]->setY(getY());
                    break;

                case 2: //down
                    board[getX() + 1][getY()] = new Ant();
                    board[getX() + 1][getY()]->setType(ANT);
                    board[getX() + 1][getY()]->setX(getX()+1);
                    board[getX() + 1][getY()]->setY(getY());
                    break;

                case 3: //left
                    board[getX()][getY()-1] = new Ant();
                    board[getX()][getY()-1]->setType(ANT);
                    board[getX()][getY()-1]->setX(getX());
                    board[getX()][getY()-1]->setY(getY()-1);
                    break;

                case 4: //right
                    board[getX()][getY()+1] = new Ant();
                    board[getX()][getY()+1]->setType(ANT);
                    board[getX()][getY()+1]->setX(getX());
                    board[getX()][getY()+1]->setY(getY()+1);
                    break;

                default:
                    break;

            }
        }

    }

}


