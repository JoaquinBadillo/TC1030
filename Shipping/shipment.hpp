#ifndef Shipment_h
#define Shipment_h
#include <string>

class Shipment
{
protected:
    bool express;

    double standardFee; // Additional Standard Fee
    double expressFee; // Additional Express Fee
    double totalFee; // The fee that will be charged to the user

    // Sender Data
    std::string senderName;
    std::string senderLocation;
    std::string senderCity;
    std::string senderState;
    std::string senderZipCode;

    // Addressee Data
    std::string addresseeName;
    std::string addresseeLocation;
    std::string addresseeCity;
    std::string addresseeState;
    std::string addresseeZipCode;

public:

    Shipment()
    {
        standardFee = 5.5;
        expressFee = 6.5;

        senderName = "NA";
        senderLocation = "NA";
        senderCity = "NA";
        senderState = "NA";
        senderZipCode = "NA";

        addresseeName = "NA";
        addresseeLocation = "NA";
        addresseeCity = "NA";
        addresseeState = "NA";
        addresseeZipCode = "NA";
    }

    
    Shipment(std::string sName, std::string sLocation, std::string sCity, std::string sState, std::string sZip, std::string aName, std::string aLocation, std::string aCity, std::string aState, std::string aZip, bool exp)
    {
        standardFee = 5.5;
        expressFee = 6.5;

        senderName = sName;
        senderLocation = sLocation;
        senderCity = sCity;
        senderState = sState;
        senderZipCode = sZip;

        addresseeName = aName;
        addresseeLocation = aLocation;
        addresseeCity = aCity;
        addresseeState = aState;
        addresseeZipCode = aZip;

        express = exp;
    }

    // Getters

    std::string getSenderLocation()
    {
        return senderLocation;
    }

    std::string getAddresseeLocation()
    {
        return addresseeLocation;
    }

    std::string getSenderCity()
    {
        return senderCity;
    }

    std::string getAddresseeCity()
    {
        return addresseeCity;
    }

    std::string getSenderState()
    {
        return senderState;
    }

    std::string getAddresseeState()
    {
        return addresseeState;
    }

    std::string getSenderZipCode()
    {
        return senderZipCode;
    }

    std::string getAddresseeZipCode()
    {
        return addresseeZipCode;
    }

    virtual double computePrice()
    {
        totalFee = standardFee;
        
        if(express)
        {
            totalFee = expressFee;
        }

        return totalFee;
    }
};

#endif