#ifndef Package_h
#define Package_h

#include <iostream>
#include <string>

#include "shipment.hpp"

class Package: public Shipment
{
private:
    float width;
    float length;
    float depth;
    float mass;
    float price; // Cost per unit mass

public:

    void setMass(float mass_)
    {
        if(mass_ > 0)
        {
            mass = mass_;
        }
        else
        {
            std::cout << "Error: Mass is strictly positive" << std::endl;
        }
    }

    void setPrice(float cost)
    {
        if(cost > 0)
        {
            price = cost;
        }
        else
        {
            std::cout << "Error: Price must be positive" << std::endl;
        }
    }

    double computePrice()
    {
        totalFee = mass*price;
        
        if(express)
        {
            totalFee += expressFee;
        }
        else
        {
            totalFee += standardFee;
        }

        return totalFee;
    }

    Package()
    {
        width = 0;
        length = 0;
        depth = 0; 

        setMass(1);
        setPrice(1);  
    }

    Package(std::string sName, std::string sLocation, std::string sCity, std::string sState, std::string sZip, std::string aName, std::string aLocation, std::string aCity, std::string aState, std::string aZip, bool exp, float x, float y, float z, float mass_, float cost):Shipment(sName, sLocation, sCity, sState, sZip, aName, aLocation, aCity, aState, aZip, exp)
    {
        width = x;
        length = y;
        depth = z; 

        setMass(mass_);
        setPrice(cost);
    }
};

#endif