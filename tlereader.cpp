#include "tlereader.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

double parseImpliedExponent(const string& s) {
    double sign = (s[0] == '-') ? -1.0 : 1.0;
    double mantissa = stod("0." + s.substr(1, 5));
    int exponent = stoi(s.substr(6, 2));
    return sign * mantissa * pow(10.0, exponent);
}


TLEData tleReader(const string& filename) {
        
    // Open the file
    ifstream file(filename);
    
    // Check that it opened succesfully
    if (!file.is_open()) {
        cerr << "Error: Could not open the file." << std::endl;
    }

    // Read and print the file
    vector<string> lines;
    string line;
    while (getline(file, line)){
        lines.push_back(line);
    }
    file.close();

    // Extract and Print Important Data
    const string& line0 = lines[0];
    const string& line1 = lines[1];
    const string& line2 = lines[2];

    TLEData tle;

    // ---- LINE 0 ----
    tle.name = line0;

    // ---- LINE 1 ----
    tle.catalogNumber = stoi(line1.substr(2, 5));
    tle.classification = line1[7];
    tle.launchYear = stoi(line1.substr(9, 2));
    tle.launchNumber = stoi(line1.substr(11, 3));
    tle.launchPiece = line1.substr(14, 3);
    tle.epochYear   = stoi(line1.substr(18, 2));
    tle.epochDay = stod(line1.substr(20, 12));
    tle.ballisticCoeff = stod(line1.substr(33, 10));
    tle.secondDerivMeanMotion = parseImpliedExponent(line1.substr(44, 8));
    tle.bStar = parseImpliedExponent(line1.substr(53, 8));
    tle.ephemerisType = stoi(line1.substr(62, 1));
    tle.elementSetNumber = stoi(line1.substr(64, 4));
    tle.checksum1 = stoi(line1.substr(68, 1)); 

    // ---- LINE 2 ----
    tle.inclination = stod(line2.substr(8, 9));
    tle.raan = stod(line2.substr(17, 8));
    tle.eccentricity = stod("0." + line2.substr(26, 7));
    tle.argPerigee = stod(line2.substr(34, 8));
    tle.meanAnomaly = stod(line2.substr(43, 8));
    tle.meanMotion = stod(line2.substr(52, 11));
    tle.revolutionNumber = stoi(line2.substr(63, 5));
    tle.checksum2 = stoi(line2.substr(68, 1));

    return tle;
}

void printTLE(const TLEData& tle) {
    cout << "*---Important TLE Contents---*\n";

    cout << "*-LINE 1-*\n";
    cout << "Spacecraft: " << tle.name << '\n';
    cout << "Satellite Catalog Number: " << tle.catalogNumber << '\n';

    string cls = "Unknown";
    if (tle.classification == 'U') cls = "Unclassified";
    else if (tle.classification == 'C') cls = "Classified";
    else if (tle.classification == 'S') cls = "Secret";
    cout << "Classification: " << cls << '\n';

    cout << "Last two digits of launch year: " << tle.launchYear << '\n';
    cout << "Launch number of the year: " << tle.launchNumber << '\n';
    cout << "Piece of the launch: " << tle.launchPiece << '\n';
    cout << "Epoch year: " << tle.epochYear << '\n';
    cout << "Epoch day of year: " << tle.epochDay << '\n';
    cout << "First derivative of mean motion (ballistic coefficient): "
         << tle.ballisticCoeff << " (rev/day^2)\n";
    cout << "Second derivative of mean motion: "
         << tle.secondDerivMeanMotion << " (rev/day^3)\n";
    cout << "B*, the drag term: " << tle.bStar << " (1/Earth radii)\n";
    cout << "Ephemeris type: " << tle.ephemerisType << '\n';
    cout << "Element set number: " << tle.elementSetNumber << '\n';
    cout << "Checksum (modulo 10): " << tle.checksum1 << '\n';

    cout << "*-LINE 2 (Classical Orbital Elements)-*\n";
    cout << "Inclination: " << tle.inclination << " (deg)\n";
    cout << "Right ascension of the ascending node: " << tle.raan << " (deg)\n";
    cout << "Eccentricity: " << tle.eccentricity << '\n';
    cout << "Argument of Perigee: " << tle.argPerigee << " (deg)\n";
    cout << "Mean anomaly: " << tle.meanAnomaly << " (deg)\n";
    cout << "Mean motion: " << tle.meanMotion << " (revolutions per day)\n";
    cout << "Revolution number at Epoch: " << tle.revolutionNumber << " (revolutions)\n";
    cout << "Checksum (modulo 10): " << tle.checksum2 << '\n';
}

