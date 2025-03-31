#ifndef PlaneFlight_H
#define PlaneFlight_H

#include <iostream>
#include <string>
using namespace std; 

class PlaneFlight {
// Create the private objects
private: 
    double mCost, mMileage; 
    string mFromCity, mToCity, mName; 

// Create the public accessors and mutators 
public:
    PlaneFlight(string passengerName, string fromCity, string toCity, double cost, double mileage);
    // Getters
    double getCost() const;
    double getMileage() const;
    string getName() const;
    string getFromCity() const;
    string getToCity() const;

    // Setters
    void setCost(double cost);
    void setMileage(double mileage);
    void setName(string name); 
    void setFromCity(string from); 
    void setToCity(string to); 
};


#endif 
