#include <iomanip>
#include "Auctioneer.h"

void Auctioneer::Setup(vector<Bid> &Buy, vector<Bid> &Sell, int NUMBUYER, int NUMSELLER) {
    // Opens and verifies if output.txt exists
    outfile.open("output.txt");

    if (!outfile) {
        cout << "No file found!" << endl;
    }

    outfile << "Generated Bids: " << endl;

    outfile << "(traderName," << setw(2) << " bidID," << setw(2) << " bidType," << setw(2)
            << " price," << setw(2) << " quantity)" << endl;


    // Prints out all of the Buyers
    for (int i = 0; i < NUMBUYER; i++) {
        outfile << "(" << Buy[i].getTraderName() << ", " << setw(6) << Buy[i].getBidID() << ", "
                << setw(7) << Buy[i].getBidType() << ", " << setw(9) << Buy[i].getBidPrice() << ", "
                << setw(6) << Buy[i].getBidQuantity() << ")" << endl;
    }

    // Prints out all of the Sellers
    for (int i = 0; i < NUMSELLER; i++) {
        outfile << "(" << Sell[i].getTraderName() << ", " << setw(6) << Sell[i].getBidID() << ", "
                << setw(6) << Sell[i].getBidType() << ", " << setw(9) << Sell[i].getBidPrice() << ", "
                << setw(6) << Sell[i].getBidQuantity() << ")" << endl;
    }

    outfile << "\n Matched Bids: " << endl;

    if (NUMBUYER >= NUMSELLER) {
        maxRow = NUMBUYER;
    } else {
        maxRow = NUMSELLER;
    }
}
void Auctioneer::Match(vector<Bid> &Buy, vector<Bid> &Sell) {
    // Sorts both Buy & Sell Vectors
    sort(Buy.begin(), Buy.end(), greater<Bid>());
    sort(Sell.begin(), Sell.end());
    
    do {
        matchCheck = false;

        for (int i = 0; i < maxRow; i++) {
            if (Buy[i].getBidPrice() > Sell[i].getBidPrice()){

                clearingPrice = (Buy[i].getBidPrice() + Sell[i].getBidPrice()) / 2;
                quantityTraded = 0;

                if(Buy[i].getBidQuantity() > Sell[i].getBidQuantity()){
                    quantityTraded = Sell[i].getBidQuantity();
                    MatchPrint(Buy, Sell, i);
                    Buy[i].setBidQuantity(Buy[i].getBidQuantity() - Sell[i].getBidQuantity());
                    Sell.erase(Sell.begin() + i);
                }

                else if(Buy[i].getBidQuantity() < Sell[i].getBidQuantity()){
                    quantityTraded = Buy[i].getBidQuantity();
                    MatchPrint(Buy, Sell, i);
                    Sell[i].setBidQuantity(Sell[i].getBidQuantity() - Buy[i].getBidQuantity());
                    Buy.erase(Buy.begin() + i);
                }

                else if(Buy[i].getBidQuantity() == Sell[i].getBidQuantity()){
                    quantityTraded = Buy[i].getBidQuantity();
                    MatchPrint(Buy, Sell, i);
                    Buy[i].setBidQuantity(Buy[i].getBidQuantity() - Sell[i].getBidQuantity());
                    Buy.erase(Buy.begin() + i);
                    Sell.erase(Sell.begin() + i);
                }

                matchCheck = true;
            }
        }
    } while (matchCheck == true);
}

void Auctioneer::UnmatchedPrint(vector<Bid> &Buy, vector<Bid> &Sell){
    // Prints all of the matched & unmatched bids
    outfile << "\n Unmatched Buy Bids: " << endl;

    for (int i = 0; i < Buy.size(); i++) {
        outfile << "(" << Buy[i].getTraderName() << ", " << setw(6) << Buy[i].getBidID() << ", "
                << setw(7) << Buy[i].getBidType() << ", " << setw(9) << Buy[i].getBidPrice() << ", "
                << setw(6) << Buy[i].getBidQuantity() << ")" << endl;
    }

    outfile << "\n Unmatched Sell Bids: " << endl;

    for (int i = 0; i < Sell.size(); i++) {
        outfile << "(" << Sell[i].getTraderName() << ", " << setw(6) << Sell[i].getBidID() << ", "
                << setw(6) << Sell[i].getBidType() << ", " << setw(9) << Sell[i].getBidPrice() << ", "
                << setw(6) << Sell[i].getBidQuantity() << ")" << endl;
    }
}

void Auctioneer::MatchPrint(vector<Bid> &Buy, vector<Bid> &Sell, int i){
    outfile << "(" << Buy[i].getTraderName() << ", " << setw(6) << Buy[i].getBidID() << ", "
            << setw(7) << Buy[i].getBidType() << ", " << setw(9) << Buy[i].getBidPrice() << ", "
            << setw(6) << quantityTraded << ")" << " <=> " << "(" << Sell[i].getTraderName() << ", "
            << setw(6) << Sell[i].getBidID() << ", " << setw(6) << Sell[i].getBidType() << ", "
            << setw(9) << Sell[i].getBidPrice() << ", " << setw(6) << quantityTraded << ")"
            << " with Clearing Price: " << clearingPrice << endl;
}
