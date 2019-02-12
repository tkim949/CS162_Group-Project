/************************************************************************************************
* * Created by Taekyoung Kim on 2019-02-10.
* * This was orginally the group project for CS162, but this is my own work.
* * While I was waiting for other group members' work done to do debugging or checking,
* * I tried to do this and thankfully, it works well.
* * GBoard.h file
*********************************************************************************************/


#ifndef GBOARD_H
#define GBOARD_H
#include "Critter.h"
#include "Ant.h"

class GBoard {


private:

    Critter*** board;

    const int SIZE =20;


protected:

public:

    GBoard();
    ~GBoard();

    Critter*** setBoard();

    void fillBoard(Critter*** b);
    void displayBoard(Critter*** b);
    void oneLotate(Critter*** b);
    void deleteBoard(Critter*** b);

};


#endif //NEW_GROUPP_GBOARD_H
