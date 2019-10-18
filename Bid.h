#ifndef ASSIGNMENT_2_BID_H
#define ASSIGNMENT_2_BID_H

#include <iostream>
#include <algorithm>
using namespace std;

class Bid{
    string traderName;      // Holds Trader's Name
    static int bidCount;    // Holds Amount of bidObjects
    int bidID;              // Holds Bid's Unique ID
    char bidType;           // Holds Bid's Type
    double price;           // Holds Bid's value
    int quantity;           // Holds Bid's amount of stocks

public:
    Bid(string Name, int ID, char type, double cost, int amount){
        traderName = Name;
        bidCount = bidCount + 1;
        bidID = bidCount;
        bidType = type;
        price = cost;
        quantity = amount;
    }

    double getBidPrice(){
        return price;
    }

    string getTraderName(){
        return traderName;
    }

    int getBidID(){
        return bidID;
    }

    char getBidType(){
        return bidType;
    }

    int getBidQuantity(){
        return quantity;
    }

    void setBidQuantity(int amount){
        quantity = amount;
    }

    bool operator<(const Bid& other) const{
        return price < other.price;
    }

    bool operator>(const Bid& other) const{
        return price > other.price;
    }
};

#endif //ASSIGNMENT_2_BID_H
