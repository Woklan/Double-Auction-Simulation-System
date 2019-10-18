#include "Bid.h"
#include "Trader.h"

Bid Trader::generateBid(string name, char type, int MINPRICE, int MAXPRICE, int MINQUANTITY, int MAXQUANTITY){

    double price = 0.00;
    int quantity = 0;

    // Generates a price between MINPRICE & MAXPRICE
    do {
        price = rand() % MAXPRICE+1 + rand() % 100 * 0.01;
    }while(price < MINPRICE);

    // Generates a quantity between MINQUANTITY & MAXQUANTITY
    do {
        quantity = rand() % MAXQUANTITY+1;
    }while(quantity < MINQUANTITY);

    return Bid(name, 0, type, price, quantity);
}

string Trader::getTraderName(){
    return traderName;
}
char Trader::getTraderType(){
    return traderType;
}