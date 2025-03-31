#ifndef FrequentFlyerAccount_H
#define FrequentFlyerAccount_H

#include <iostream>
#include <string>
#include "PlaneFlight.h"

using namespace std;

class FrequentFlyerAccount {
private:
    string mName;
    double mBalance = 0;

public:
    FrequentFlyerAccount(string name);
    // Getters
    double getBalance() const;
    string getName() const;

    bool addFlightToAccount(PlaneFlight flight);  
    bool canEarnFreeFlight(double mileage);
    bool freeFlight(string from, string to, double mileage, PlaneFlight& flight);
};

#endif

