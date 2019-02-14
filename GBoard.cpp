/****************************************************************************************************
* * Program name: CS162 Group Project
* * Group number: # 29
* * Group member: Taekyoung Kim, Zuhair Ahmed
* * Date: 02/10/2019
* * Description: This is GBoard.cpp file for CS162 GroupProject
* * This project demonstrates a 2D simulation of Predator-Prey Game.
* * The board is a 2D array and each cell points to a Critter.
******************************************************************************************************/

#include "GBoard.h"
#include "Critter.h"
#include "Ant.h"
#include "DoodleBug.h"
#include <iostream>
#include <random>

//Constructor
GBoard::GBoard() =default;

//Destructor
GBoard::~GBoard() =default;

/*********************************************
{
    for(int i = 0; i < SIZE ; i++ ) {
        for(int j = 0; j < SIZE ; j++) {

            delete board[i][j];
        }
        delete[] board[i];
    }
    delete[] board;
    board = nullptr;
 }
**********************************************/

/******************************************************************
 * * This setBoard() function create a board of Critters
 * * with 2D array of pointers.
 * * @return
 ******************************************************************/
Critter*** GBoard::setBoard() {

    Critter*** board;
    board = new Critter**[SIZE];

    for (int i=0; i < SIZE ; i++) {
        board[i] = new Critter *[SIZE];
    }

    for (int j=0; j < SIZE; j++){
        for (int k=0; k< SIZE; k++){
            board[j][k] = nullptr;
        }
    }

    return board;
}

/*************************************************************************
 * * This fillBoard() function fills the board with ants and doodle bugs.
 * * The number of ants are 100 and doodle bugs are 5.
 * * @param board
 *************************************************************************/

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

            board[locaX][locaY] = new DoodleBug ();
            board[locaX][locaY]->setType(DOODLEBUG);
            board[locaX][locaY]->setX(locaX);
            board[locaX][locaY]->setY(locaY);
            dooBugCount++;
        }
    }

}

/********************************************************************************
 * * This displayBoard() function shows the board.
 * * It marks [ ] for the empty cell, [0] for the ant, and [X] for doodle bugs
 * * using ASCII number.
 * * @param board
 ********************************************************************************/

void GBoard::displayBoard(Critter*** board){

    for (int i = 0; i < SIZE ; i++) {
        for (int j = 0; j < SIZE ; j++) {

            if (board[i][j] == nullptr) {
                std::cout << "[ ]";
            }

            else if (board[i][j]->getType() == ANT){
                std::cout <<"["<< char(79)<<"]";

            }

            else if (board[i][j]->getType() == DOODLEBUG) {
                std::cout <<"[" <<char(88)<<"]";

            }

        }
        std::cout << std::endl;
    }
}

/***********************************************************************************
 * * This oneLotate() function describes one day(turn).
 * * First, it checks if a cell is empty or not. If not, a critter is checked
 * * moved = false through the whole board. Next, it checks if there is
 * * a doodle bug in a cell through the whole board. if so. it calls move().
 * * After that, it checks if there is an ant in a cell through the whole board.
 * * If so, it calls move() again. When critter moves, it check if move=false,
 * * then change it true when they move.
 * * Next, it checks if there is a doodle bug that hasn't eaten more than 3 days.
 * * If so, it deletes the doodlebug and make the cell empty.
 * * Lastly, it checks if there is critter in a cell and if it already moved.
 * * And, call the breed() function.
 * * @param board
 ************************************************************************************/

void GBoard::oneLotate(Critter*** board)
{
    int i,j;

    //First check if cell is not empty, which means critters there and set all critter's moved = false.
    for (i=0; i<SIZE; i++)
        for (j=0; j<SIZE; j++)
        {
            if (board[i][j]!= nullptr) board[i][j]->moved = false;
        }


   //Second, DoodleBug move. Check through cells in order and move if it's a Doodlebug.
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

    //Then, Ant move. Check through cells in order and move if it's an Ant
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

    //Remove any doodlebugs that haven't eaten for more than 3 days.
    for (i=0; i<SIZE; i++)
        for (j=0; j<SIZE; j++)
        {

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

    //Next, breed. Check through cells in order and check if critters should breed.
    for (i=0; i<SIZE; i++)
        for (j=0; j<SIZE; j++)
        {
            // Critter has baby after they have moved. move is the first one.
            if ((board[i][j]!= nullptr) && (board[i][j]->moved))
            {
                board[i][j]->breed(board);
            }
        }

}

/*****************************************************************************************
 * * This deleteBoard() function delete the 2D array of pointers after the process ends.
 * * It was first placed inside the destructor, but it causes some issues.
 * * So, this new function was made and placed here.
 * * @param board
 *****************************************************************************************/

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
