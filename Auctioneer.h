#ifndef ASSIGNMENT_2_AUCTIONEER_H
#define ASSIGNMENT_2_AUCTIONEER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Bid.h"

class Auctioneer{
    bool matchCheck = false;    // Checks if at least one match was made last round
    double clearingPrice = 0;   // Used to hold clearing price
    int maxRow;                 // Used to figure out what is the max possible row
    int quantityTraded = 0;     // Holds how many stocks are being traded
    ofstream outfile;
public:
    void Setup(vector<Bid> &Buy, vector<Bid> &Sell, int NUMBUYER, int NUMSELLER);   // Prints initial Bids
    void Match(vector<Bid> &Buy, vector<Bid> &Sell);                                // Matches and Prints Bids
    void UnmatchedPrint(vector<Bid> &Buy, vector<Bid> &Sell);                       // Prints Unmatched Bids
    void MatchPrint(vector<Bid> &Buy, vector<Bid> &Sell, int i);

};

#endif //ASSIGNMENT_2_AUCTIONEER_H
