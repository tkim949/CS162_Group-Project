/************************************************************************************************
* * Created by Taekyoung Kim on 2019-02-10.
* * This was orginally the group project for CS162, but this is my own work.
* * While I was waiting for other group members' work done to do debugging or checking,
* * I tried to do this and thankfully, it works well.
* * Ant.h file
*********************************************************************************************/


#ifndef ANT_H
#define ANT_H
#include "Critter.h"

class Ant : public Critter
{

private:

public:

    Ant();
    ~Ant() override;
    //;
    //Ant(int x, int y);
    void move(Critter***) override;
    void breed(Critter***) override;

    bool starve() override  // Return false because it never starves.
    { return false; }
};


#endif //ANT_H
