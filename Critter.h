/************************************************************************************************
* * Created by Taekyoung Kim on 2019-02-10.
* * This was orginally the group project for CS162, but this is my own work.
* * While I was waiting for other group members' work done to do debugging or checking,
* * I tried to do this and thankfully, it works well.
* * Critter.h file
*********************************************************************************************/


#ifndef CRITTER_H
#define CRITTER_H
#include <iostream>

enum Type {ANT, DOODLEBUG};

class Critter {

private:

protected:

    Type type;
    //std::string name;
    int locX;
    int locY;
    //int age = 0;
    //bool goMove = true;
    int breedTime =0;


public:

    Critter();
    virtual ~Critter();
    //explicit Critter(Type ty);
    //Critter(int x, int y);
    Critter(int x, int y, Type ty);
    Type getType();
    virtual void setType(Type ty);
    //virtual std::string getName();
    //virtual void setName(std::string na);
    virtual int getX() const;
    virtual int getY()const;
    virtual void setX(int x);
    virtual void setY(int y);

    virtual void move(Critter*** b)=0;
    virtual void breed(Critter*** b)=0;
    virtual bool starve() = 0;
    bool moved =false;

    //virtual void locate(int x, int y);
    //virtual int getIsSurvive();
    // virtual void setIsSurvive(int s);
    // virtual bool getGoMove() const;
    // virtual void setGoMove(bool);

    //virtual int getAge() const;
    //virtual void setAge(int a);
    //bool emptyNeighbor();

};


#endif //NEW_GROUPP_CRITTER_H
