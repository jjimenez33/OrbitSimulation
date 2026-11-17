#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "tlereader.hpp"
using namespace std;
 
// This is a program for parsing Two Line Elements (TLEs) and printing the result.

int main() {
    string filename = "TLE_ISS.txt";
    tleReader(filename);
    

    return 0;
}
