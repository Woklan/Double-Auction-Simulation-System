#ifndef ASSIGNMENT_2_SIMULATOR_H
#define ASSIGNMENT_2_SIMULATOR_H

#include <fstream>
#include "Auctioneer.h"
#include "Seller.h"
#include "Buyer.h"

class Simulator{
    vector<Bid> Buy;
    vector<Bid> Sell;
    Auctioneer auctioneer;

public:
    Simulator(int MINPRICE, int MAXPRICE, int MINQUANTITY, int MAXQUANTITY, int NUMSELLER, int NUMBUYER){

        // Creates Buy Bids and Places in Buy Vector
        for(int i = 0; i < NUMBUYER; i++){
            Buyer buyer;
            Buy.push_back(buyer.generateBid(buyer.getTraderName(), buyer.getTraderType(), MINPRICE, MAXPRICE, MINQUANTITY, MAXQUANTITY));
        }

        // Creates Sell Bids and Places in Sell Vector
        for(int i = 0; i < NUMSELLER; i++){
            Seller seller;
            Sell.push_back(seller.generateBid(seller.getTraderName(), seller.getTraderType(), MINPRICE, MAXPRICE, MINQUANTITY, MAXQUANTITY));
        }

        auctioneer.Setup(Buy, Sell, NUMBUYER, NUMSELLER);
        auctioneer.Match(Buy, Sell);
        auctioneer.UnmatchedPrint(Buy, Sell);
    }
};

#endif //ASSIGNMENT_2_SIMULATOR_H
