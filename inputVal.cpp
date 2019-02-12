/************************************************************************************************
* * Created by Taekyoung Kim on 2019-02-10.
* * This was orginally the group project for CS162, but this is my own work.
* * While I was waiting for other group members' work done to do debugging or checking,
* * I tried to do this and thankfully, it works well.
* * inputVal.cpp file
*********************************************************************************************/

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
