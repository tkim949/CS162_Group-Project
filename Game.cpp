/****************************************************************************************************
* * Program name: CS162 Group Project
* * Group number: # 29
* * Group member: Taekyoung Kim, Zuhair Ahmed
* * Date: 02/10/2019
* * Description: This is Game.cpp file for CS162 GroupProject
* * This project demonstrates a 2D simulation of Predator-Prey Game.
* * The board is a 2D array and each cell points to a Critter.
******************************************************************************************************/

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

    GBoard gB;
    Critter*** board = gB.setBoard();

    double oNum;
    int numb;
    int cont;
    int pAgain;
    
    std::cout<<"Welcome to the ants and doodle bugs' Predator-Prey simulation world"<<std::endl;
	std::cout<<"If you input the number of days that you want to go, you can see it"<<std::endl;
	std::cout<<"You can continue after the simulation ends, ";
	std::cout<<"and also you can exit at that time. Now, let's begin."<<std::endl;

    do {

        gB.fillBoard(board);

        do {
            std::cout << "How many days you want to go? please input your number: ";
            std::cin >> oNum;
            numb = inputVal(oNum);

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
