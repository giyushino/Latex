#ifndef Die_H 
#define Die_H

#include <iostream>
#include <string>
using namespace std; 

class Die {
private: 
    int mSides, mValue; 

public: 
    Die(int sides = 6);
    void roll();
    int getValue();
};


#endif
