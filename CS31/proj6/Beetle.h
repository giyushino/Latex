#ifndef Beetle_H 
#define Beetle_H

#include <iostream>
#include <string>
using namespace std; 

class Beetle {
private: 
    bool mBody, mTail, mLeg1, mLeg2, mLeg3, mLeg4;
    bool mHead, mEye1, mEye2, mAntenna1, mAntenna2;
public: 
    Beetle();
    void isComplete();
    void buildBody();
    void hasBody();
    void buildHead();
    void hasHead();
    void buildTail();
    void hasTail();
    void buildAntenna();
    void hasAntenna1();
    void hasAntenna();
    void buildLeg();
    void hasLeg1();
    void hasLeg2();
    void hasLeg3();
    void hasLeg4();
};



#endif
