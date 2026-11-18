#include <iostream>
#include "tlereader.hpp"
using namespace std;
 
// This is a program for parsing Two Line Elements (TLEs) and printing the result.

int main() {
    TLEData tle = tleReader("data/TLE_COSMOS2022.txt");
    printTLE(tle);

    return 0;
}
