#ifndef ASSIGNMENT_2_SELLER_H
#define ASSIGNMENT_2_SELLER_H

#include <sstream>
#include "Trader.h"

class Seller : public Trader{
    static int sellCount;       // Holds Count of Seller Objects
public:
    Seller(){
        sellCount = sellCount + 1;


        count << sellCount;

        traderName = "Seller" + count.str();
        traderType = 'A';
    }
};

#endif //ASSIGNMENT_2_SELLER_H
