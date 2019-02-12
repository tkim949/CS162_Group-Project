/************************************************************************************************
* * Created by Taekyoung Kim on 2019-02-10.
* * This was orginally the group project for CS162, but this is my own work.
* * While I was waiting for other group members' work done to do debugging or checking,
* * I tried to do this and thankfully, it works well.
* * Game.cpp file
*********************************************************************************************/

#include "Game.h"
#include "GBoard.h"
#include "Critter.h"
#include "Ant.h"
#include "DoodleBug.h"
#include "inputVal.h"
#include <climits>
#include <iostream>

Game::Game() = default;
Game::~Game() = default;

void Game::play(){


    //Critter*** board = setBoard();
    GBoard gB;
    Critter*** board = gB.setBoard();
    //Critter*** board = gB.setBoard();

    double oNum;
    int numb;
    int cont;
    int pAgain;

    do {

        gB.fillBoard(board);

        //gB.displayBoard(board);

        do {
            std::cout << "How many days you want to go? please input your number: ";
            std::cin >> oNum;
            numb = inputVal(oNum);

            //gB.oneLotate(board);
            //std::cout<<std::endl;
            //gB.displayBoard(board);

            for (int i = 0 ; i < numb ; i++) {

                std::cout<<"Round: "<<i+1<<std::endl;

                gB.displayBoard(board);
                gB.oneLotate(board);
                std::cout << std::endl;
            }

            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "If you want to continue, input 1. Otherwise, click any keys! ";
            std::cin >> cont;
            std::cout << "----------------------------------------------------" << std::endl;


        } while (cont == 1);

        std::cout << "So you want to stop. Let's stop!" << std::endl;
        std::cout<<std::endl;

        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout<<"If you want to play from the beginning. Please input 1. Otherwise, click any keys! ";
        std::cin>>pAgain;

    }while(pAgain ==1);

    std::cout<<"You want to exit. Okay Good bye!" << std::endl;

    gB.deleteBoard(board);
}