#pragma once
#include <string>
#include <vector>

struct TLEData {
    // Line 0
    std::string name;

    // Line 1
    int    catalogNumber = 0;
    char   classification = 'U';
    int    launchYear = 0;
    int    launchNumber = 0;
    std::string launchPiece;
    int    epochYear = 0;
    double epochDay = 0.0;
    double ballisticCoeff = 0.0;
    double secondDerivMeanMotion = 0.0;
    double bStar = 0.0;
    int    ephemerisType = 0;
    int    elementSetNumber = 0;
    int    checksum1 = 0;

    // Line 2
    double inclination = 0.0;
    double raan = 0.0;
    double eccentricity = 0.0;
    double argPerigee = 0.0;
    double meanAnomaly = 0.0;
    double meanMotion = 0.0;
    int    revolutionNumber = 0;
    int    checksum2 = 0;
};

// Reads a 3-line TLE
TLEData tleReader(const std::string& filename);

// Prints the parsed data
void printTLE(const TLEData& tle);
    



