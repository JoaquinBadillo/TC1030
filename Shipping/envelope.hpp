#ifndef Envelope_h
#define Envelope_h

#include<string>

#include "shipment.hpp"

class Envelope: public Shipment
{
private:
    float height;
    float width;
    float extraCharge;

public:
    double computePrice()
    {
        totalFee = standardFee;
        
        if(express)
        {
            totalFee = expressFee;
        }

        if((height > 25 && width > 30) || (height > 30 && width > 25))
        {
            totalFee += extraCharge;
        }

        return totalFee;
    }

    Envelope()
    {
        height = 0;
        width = 0;

        extraCharge = 10;
    }

    Envelope(std::string sName, std::string sLocation, std::string sCity, std::string sState, std::string sZip, std::string aName, std::string aLocation, std::string aCity, std::string aState, std::string aZip, bool exp, float x, float y):Shipment(sName, sLocation, sCity, sState, sZip, aName, aLocation, aCity, aState, aZip, exp)
    {
        height = x;
        width = y;

        extraCharge = 10;
    }
};

#endif