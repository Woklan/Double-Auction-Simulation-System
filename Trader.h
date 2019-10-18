#ifndef ASSIGNMENT_2_TRADER_H
#define ASSIGNMENT_2_TRADER_H

#include <iostream>
#include <sstream>
#include "Bid.h"
using namespace std;

class Trader{
protected:
    string traderName;
    char traderType;
    stringstream count;

public:
    Bid generateBid(string, char, int, int, int, int);
    string getTraderName();
    char getTraderType();

};

#endif //ASSIGNMENT_2_TRADER_H
