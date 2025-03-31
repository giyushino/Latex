#include "FrequentFlyerAccount.h"
#include "PlaneFlight.h"

FrequentFlyerAccount::FrequentFlyerAccount(string name) {
    mName = name;
    mBalance = 0;
}

double FrequentFlyerAccount::getBalance() const {
    return mBalance;
}

string FrequentFlyerAccount::getName() const {
    return mName;
}

bool FrequentFlyerAccount::addFlightToAccount(PlaneFlight flight) {
    if (flight.getName() == mName) {
        mBalance += flight.getMileage();
        return true;
    } else {
        return false;
    }
}

bool FrequentFlyerAccount::canEarnFreeFlight(double mileage) {
    if (mBalance >= mileage) {
        return true; 
    } 
    else {return false;}
}

bool FrequentFlyerAccount::freeFlight(string from, string to, double mileage, PlaneFlight& flight) {
    if (canEarnFreeFlight(mileage) == true) {
        flight = PlaneFlight(mName, from, to, 0, mileage);
        mBalance -= mileage; 
        return true;
    }
    return false; 
}


