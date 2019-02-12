/************************************************************************************************
* * Created by Taekyoung Kim on 2019-02-10.
* * This was orginally the group project for CS162, but this is my own work.
* * While I was waiting for other group members' work done to do debugging or checking,
* * I tried to do this and thankfully, it works well.
* * GBoard.cpp file
*********************************************************************************************/

#include "GBoard.h"
#include "Critter.h"
#include "Ant.h"
#include "DoodleBug.h"
#include <iostream>
#include <random>


GBoard::GBoard() =default;
GBoard::~GBoard() {

/**************************

    for(int i = 0; i < SIZE ; i++ ) {
        for(int j = 0; j < SIZE ; j++) {

            delete board[i][j];
        }
        delete[] board[i];
    }
    delete[] board;
    board = nullptr;
  **************************/
}

Critter*** GBoard::setBoard() {

    Critter*** board;
    board = new Critter**[SIZE];

    for (int i=0; i < SIZE ; i++) {
        board[i] = new Critter *[SIZE];
    }

    for (int j=0; j < 20; j++){
        for (int k=0; k< 20; k++){
            board[j][k] = nullptr;
        }
    }

    return board;
}


void GBoard::fillBoard(Critter*** board){
    int antCount = 0;

    std::random_device ran;
    std::mt19937 mt(ran());

    while(antCount < 100) {

        int locaX;
        int locaY;

        std::uniform_int_distribution<int> dist(0, 19);
        std::uniform_int_distribution<int> dist2(0, 19);
        locaX = dist(mt);
        locaY = dist2(mt);

        if(board[locaX][locaY] == nullptr) {
            //board[locaX][locaY] = new Ant (locaX, locaY);
            board[locaX][locaY] = new Ant ();
            board[locaX][locaY]->setType(ANT);
            board[locaX][locaY]->setX(locaX);
            board[locaX][locaY]->setY(locaY);
            antCount++;
        }
    }

    int dooBugCount = 0;


    while(dooBugCount < 5) {

        int locaX;
        int locaY;
        std::uniform_int_distribution<int> dist1(0, 19);
        std::uniform_int_distribution<int> dist3(0, 19);
        locaX = dist1(mt);
        locaY = dist3(mt);

        if(board[locaX][locaY] == nullptr) {
            //board[locaX][locaY] = new DoodleBug (locaX, locaY);
            board[locaX][locaY] = new DoodleBug ();
            board[locaX][locaY]->setType(DOODLEBUG);
            board[locaX][locaY]->setX(locaX);
            board[locaX][locaY]->setY(locaY);
            dooBugCount++;
        }
    }

}

void GBoard::displayBoard(Critter*** board){

    for (int i = 0; i < SIZE ; i++) {
        for (int j = 0; j < SIZE ; j++) {

            if (board[i][j] == nullptr) {
                std::cout << "[ ]";
            }
                //else if (board[i][j]->getName() == "Ant") {
            else if (board[i][j]->getType() == ANT){
                std::cout <<"["<< char(79)<<"]";

            }
                //else if (board[i][j]->getName() == "Doodle") {
            else if (board[i][j]->getType() == DOODLEBUG) {
                std::cout <<"[" <<char(88)<<"]";

            }

        }
        std::cout << std::endl;
    }
}



void GBoard::oneLotate(Critter*** board)
{
    int i,j;
    // set all critter's moved = false.
    for (i=0; i<SIZE; i++)
        for (j=0; j<SIZE; j++)
        {
            if (board[i][j]!= nullptr) board[i][j]->moved = false;
        }
    // Loop through cells in order and move if it's a Doodlebug


    for (i=0; i<SIZE; i++)
        for (j=0; j<SIZE; j++)
        {
            if ((board[i][j]!= nullptr) && (board[i][j]->getType()==DOODLEBUG))
            {
                if (!board[i][j]->moved)
                {
                    board[i][j]->moved = true; // Mark as moved
                    board[i][j]->move(board);
                }
            }
        }

    // Loop through cells in order and move if it's an Ant
    for (i=0; i<SIZE; i++)
        for (j=0; j<SIZE; j++)
        {
            if ((board[i][j]!= nullptr) && (board[i][j]->getType()==ANT))
            {
                if (!board[i][j]->moved)
                {
                    board[i][j]->moved = true; // Mark as moved
                    board[i][j]->move(board);
                }
            }
        }
    // Loop through cells in order and check if we should breed
    for (i=0; i<SIZE; i++)
        for (j=0; j<SIZE; j++)
        {
            // remove any doodlebugs that haven't eaten recently
            if ((board[i][j]!= nullptr) &&
                (board[i][j]->getType()==DOODLEBUG))
            {
                if (board[i][j]->starve())
                {
                    delete (board[i][j]);
                    board[i][j] = nullptr;
                }
            }
        }
    // Loop through cells in order and check if critter should breed
    for (i=0; i<SIZE; i++)
        for (j=0; j<SIZE; j++)
        {
            // Critter has baby after they have moved.
            if ((board[i][j]!= nullptr) && (board[i][j]->moved))
            {
                board[i][j]->breed(board);
            }
        }

}
void GBoard::deleteBoard(Critter*** board) {

    for(int i = 0; i < SIZE ; i++ ) {
        for(int j = 0; j < SIZE ; j++) {
           if(board[i][j] != nullptr) {
               delete board[i][j];
           }
        }
        if(board[i] != nullptr) {
            delete[] board[i];
        }
    }
    delete[] board;
    board = nullptr;

}

/*******************************
void GBoard::deleteBoard(Critter*** board){

    for(int i = 0; i < 20; i++ ) {
        for(int j = 0; j < 20; j++) {
            delete board[i][j];
        }
        delete[] board[i];
    }
    delete[] board;
    board = nullptr;
}
********************************/
