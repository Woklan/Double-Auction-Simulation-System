#ifndef ASSIGNMENT_2_BUYER_H
#define ASSIGNMENT_2_BUYER_H

#include <sstream>
#include "Trader.h"

class Buyer : public Trader{
    static int buyCount;        // Holds Count of Buyer Objects
public:
    Buyer(){
        buyCount = buyCount + 1;

        count << buyCount;

        traderName = "Buyer" + count.str();
        traderType = 'B';
    }
};

#endif //ASSIGNMENT_2_BUYER_H
