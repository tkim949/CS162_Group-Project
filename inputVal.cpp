/****************************************************************************************************
* * Program name: CS162 Group Project
* * Group number: # 29
* * Group member: Taekyoung Kim, Zuhair Ahmed
* * Date: 02/10/2019
* * Description: This is inputVal.cpp file for CS162 GroupProject
* * This project demonstrates a 2D simulation of Predator-Prey Game.
* * The board is a 2D array and each cell points to a Critter.
******************************************************************************************************/


#include "inputVal.h"
#include <iostream>
#include <climits>

int inputVal(double in) {

    // Check type validation first using std::cin.fail()
    if( std::cin.good() && in > 0 && (in - (int)in == 0)) {
        return (int)in;
    }

    else{

        do {
            //std::cout << "Input" << input << std::endl;
            std::cout << "Wrong input! You need to input proper value!" << std::endl;

            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');

            std::cout << "Please try again. Input here: ";
            std::cin >> in;
            //decimalCheck(input);

        } while(!(std::cin.good() && in > 0 && (in - (int)in == 0) ));

    }

    return (int)in;
}
