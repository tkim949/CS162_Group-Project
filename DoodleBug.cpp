/****************************************************************************************************
* * Program name: CS162 Group Project
* * Group number: # 29
* * Group member: Taekyoung Kim, Zuhair Ahmed
* * Date: 02/10/2019
* * Description: This is DoodleBug.cpp file for CS162 GroupProject
* * This project demonstrates a 2D simulation of Predator-Prey Game.
* * The board is a 2D array and each cell points to a Critter.
******************************************************************************************************/



#include "DoodleBug.h"
#include "GBoard.h"
#include <iostream>
#include <random>

//constructor
DoodleBug::DoodleBug()
          :Critter(-1, -1, DOODLEBUG)
{}

//destructor
DoodleBug::~DoodleBug() = default;

//Accessor for dayOfStarve
int DoodleBug::getDayOfStarve() {
    return this->dayOfStarve;
}

//Modifier for dayOfStarve
void DoodleBug::setDayOfStarve(int d){

    dayOfStarve = d;

}

/************************************************************************************************************
 * * This starve() function is bool, so it returns true or false. It checks if a doodleBug is starve or not.
 * * If the doodleBug hasn't eat more than 3 days, it returns true.
 ***********************************************************************************************************/
bool DoodleBug::starve()
{

    if (dayOfStarve > 3)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/***************************************************************************************************************
 * * This move() function of DoodleBug decides where or how a doodle bug goes.
 * * First, this function checks the edge of the board. Then, check emptiness of the cell and if there is an ant
 * * Next, it count the empty cell and assign a number. Then, it choose one cell randomly.
 * * It eats that ant and dayOfStarve becomes 0. However, if there is not any ant, the dayOfStarve increases by 1.
 * * Then, check board, if it is empty, count empty cell, and choose randomly again.
 * * Finally, that doodle bug moves to a new cell. If there is no empty cell, it stays for the next turn.
 * * @param board
 ***************************************************************************************************************/

void DoodleBug::move(Critter*** board) {

    int findAnt [4];
    int count = 0;

    if(getX() > 0 && board[getX()-1][getY()] != nullptr) {
        if(board[getX()-1][getY()]->getType() == ANT) {
            findAnt[count] = 1;
            count++;
        }
    }

    if(getX()< 19 && board[getX()+1][getY()] != nullptr) {
        if(board[getX()+1][getY()]->getType() == ANT) {
            findAnt[count] = 2;
            count++;
        }
    }

    if(getY() > 0 && board[getX()][getY()-1] != nullptr) {
        if(board[getX()][getY()-1]->getType() == ANT) {
            findAnt[count] = 3;
            count++;
        }
    }

    if(getY() < 19 && board[getX()][getY()+1] != nullptr) {
        if(board[getX()][getY()+1]->getType() == ANT) {
            findAnt[count] = 4;
            count++;
        }
    }

    int chooseSpace = 0;
    int output;
    std::random_device ran;
    std::mt19937 mt(ran());

    int c = count -1;

    if(count > 0) {
        std::uniform_int_distribution<int> dist5(0, c);
        output = dist5(mt);

        chooseSpace = findAnt[output];

        if (chooseSpace == 1) {
            delete board[getX() - 1][getY()];
            board[getX() - 1][getY()] = this;
            board[getX()][getY()] = nullptr;
            setX(getX() - 1);

        } else if (chooseSpace == 2) {
            delete board[getX() + 1][getY()];
            board[getX() + 1][getY()] = this;
            board[getX()][getY()] = nullptr;
            setX(getX() + 1);

        } else if (chooseSpace == 3) {
            delete board[getX()][getY() - 1];
            board[getX()][getY() - 1] = this;
            board[getX()][getY()] = nullptr;
            setY(getY() - 1);

        } else if (chooseSpace == 4) {
            delete board[getX()][getY() + 1];
            board[getX()][getY() + 1] = this;
            board[getX()][getY()] = nullptr;
            setY(getY() + 1);

        }
        setDayOfStarve(0);
    }

    else if(count==0) {

        setDayOfStarve(getDayOfStarve()+1);

        int findSpace [4];
        int count2 = 0;

        if(getX() > 0 && board[getX()-1][getY()] == nullptr) {
            findSpace[count2] = 1;
            count2 ++;
        }

        if(getX()<19 && board[getX()+1][getY()] == nullptr) {
            findSpace[count2] = 2;
            count2++;
        }

        if(getY() > 0 && board[getX()][getY()-1] == nullptr) {
            findSpace[count2] = 3;
            count2++;
        }

        if(getY() < 19 && board[getX()][getY()+1] == nullptr) {
            findSpace[count2] = 4;
            count2++;
        }

        if(count2 >0) {
            int dir;
            int output2;
            //std::random_device ran;
           // std::mt19937 mt(ran());
           int a = count2-1;
            std::uniform_int_distribution<int> dist5(0, a);
            output2 = dist5(mt);

            dir = findSpace[output2];

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

}

/************************************************************************************************************
 * * This breed() function of DoodleBug decides where or how a doodle bug breeds.
 * * First, this function checks a doddle bug lives 8 or more days. Then, check edge of the board
 * * and if a near cell is empty.
 * * Next, it count the empty cell and assign a number. Then, it choose one cell randomly.
 * * Finally, that doodle bug breeds a new doodle bug. If there is no empty cell, it waits for next turn.
 * * @param board
 ************************************************************************************************************/

void DoodleBug::breed(Critter*** board) {

    breedTime++;

    if(breedTime >= 8) {

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
            //If a doodle bug can breed, the breedTime becomes 0 and starts the count from the next turn.
            breedTime =0;
            int chooseSpace;
            int output;
            int d = count-1;
            std::random_device ran;
            std::mt19937 mt(ran());
            std::uniform_int_distribution<int> dist5(0, d);
            output = dist5(mt);

            chooseSpace = findSpace[output];

            switch (chooseSpace) {

                case 1:
                    board[getX() - 1][getY()] = new DoodleBug();
                    board[getX() - 1][getY()]->setType(DOODLEBUG);
                    board[getX() - 1][getY()]->setX(getX() - 1);
                    board[getX() - 1][getY()]->setY(getY());
                    break;

                case 2:
                    board[getX() + 1][getY()] = new DoodleBug();
                    board[getX() + 1][getY()]->setType(DOODLEBUG);
                    board[getX() + 1][getY()]->setX(getX()+1);
                    board[getX() + 1][getY()]->setY(getY());
                    break;

                case 3:
                    board[getX()][getY()-1] = new DoodleBug();
                    board[getX()][getY()-1]->setType(DOODLEBUG);
                    board[getX()][getY()-1]->setX(getX());
                    board[getX()][getY()-1]->setY(getY()-1);
                    break;

                case 4:
                    board[getX()][getY()+1] = new DoodleBug();
                    board[getX()][getY()+1]->setType(DOODLEBUG);
                    board[getX()][getY()+1]->setX(getX());
                    board[getX()][getY()+1]->setY(getY()+1);
                    break;

                default:
                    break;

            }
        }

    }

}

