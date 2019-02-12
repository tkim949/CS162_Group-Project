/************************************************************************************************
* * Created by Taekyoung Kim on 2019-02-10.
* * This was orginally the group project for CS162, but this is my own work.
* * While I was waiting for other group members' work done to do debugging or checking,
* * I tried to do this and thankfully, it works well.
* * DoodleBug.h file
*********************************************************************************************/


#ifndef DOODLEBUG_H
#define DOODLEBUG_H
#include "Critter.h"

class DoodleBug :
        public Critter
{

private:

    int dayOfStarve = 0;

public:

    DoodleBug();
    ~DoodleBug() override;

    int getDayOfStarve();
    void setDayOfStarve(int d);
    bool starve() override;	// Check if a doodlebug starves to death
    void move(Critter*** b) override;
    void breed(Critter*** b) override;

};


#endif //DOODLEBUG_H
