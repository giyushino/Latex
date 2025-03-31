#include "PlaneFlight.h"

PlaneFlight::PlaneFlight(string passengerName, string fromCity, string toCity, double cost, double mileage) {
    setName(passengerName);
    setFromCity(fromCity);
    setToCity(toCity);
    setCost(cost);
    setMileage(mileage);
}

double PlaneFlight::getCost() const {
    return mCost;
}

double PlaneFlight::getMileage() const {
    return mMileage;
}

string PlaneFlight::getName() const {
    return mName;
}

string PlaneFlight::getFromCity() const {
    return mFromCity;
}

string PlaneFlight::getToCity() const {
    return mToCity;
}

void PlaneFlight::setCost(double cost) {
    if (cost >= 0) {
        mCost = cost;
    } else {
        mCost = -1;
    }
}

void PlaneFlight::setMileage(double mileage) {
    if (mileage > 0) {
        mMileage = mileage;
    } else {
        mMileage = -1;
    }
}

void PlaneFlight::setName(string name) {
    if (!name.empty()) {
        mName = name;
    }
}

void PlaneFlight::setFromCity(string from) {
    if (!from.empty() && from != mToCity) {
        mFromCity = from;
    }
}

void PlaneFlight::setToCity(string to) {
    if (!to.empty() && to != mFromCity) {
        mToCity = to;
    }
}
