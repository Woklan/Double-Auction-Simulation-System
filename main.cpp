/* I hereby certify that no part of this assignment has been copied from any other student’s work or
from any other source. No part of the code has been written/produced for me by another person
or copied from any other source.
I hold a copy of this assignment that I can produce if the original is lost or damaged
 */

#include <ctime>
#include "Simulator.h"

int Buyer::buyCount = -1;
int Seller::sellCount = -1;
int Bid::bidCount = -1;

int main() {
    const int MINPRICE = 50;
    const int MAXPRICE = 150;
    const int MINQUANTITY = 1;
    const int MAXQUANTITY = 50;
    const int NUMSELLER = 10;
    const int NUMBUYER = 10;

    srand(time(0));

    Simulator s(MINPRICE, MAXPRICE, MINQUANTITY, MAXQUANTITY, NUMSELLER, NUMBUYER);
    return 0;
}