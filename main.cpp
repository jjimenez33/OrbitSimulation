#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
 
// This is a program for parsing Two Line Elements (TLEs) and printing the result.

int main() {
    // Open the file
    ifstream file("TLE_ISS.txt");
    
    // Check that it opened succesfully
    if (!file.is_open()) {
        cerr << "Error: Could not open the file." << std::endl;
        return 1;
    }

    // Read and print the file
    vector<string> lines;
    string line;
    while (getline(file, line)){
        lines.push_back(line);
        std::cout << line << '\n';
    }
    file.close();

    // Extract and Print Important Data
    string line0, line1, line2;
    line0 = lines[0];
    line1 = lines[1];
    line2 = lines[2];

    cout << "*---Important TLE Contents---*" << '\n'; 
    
    // LINE 1
    cout << "*-LINE1 1-*" << '\n';
    
    // Spacecraft name 
    cout << "Spacecraft: " << line0 << '\n';

    // Satellite Catalog Number
    string catalogNumber = line1.substr(2, 5); // index 2 for a length of 5 characters
    cout << "Satellite Catalog Number: " << catalogNumber << '\n';
    
    // Classification
    string classification = line1.substr(7, 1);
    if (classification == "U"){
        classification = "Unclassified";
    } else if (classification == "C") {
        classification = "Classified";
    } else if (classification == "S") {
        classification = "Secret";
    }
    cout << "Classification: " << classification << '\n';

    // International Designator (last two digits of launch year, can be blank)
    string launchYear = line1.substr(9, 2);
    cout << "Last two digits of launch year: " << launchYear << '\n';

    // International Designator (launch number of the year, can be blank)
    string launchNumber = line1.substr(11, 3);
    cout << "Launch number of the year: " << launchNumber << '\n';

    // International Designator (piece of the launch, can be blank)
    string launchPiece = line1.substr(14, 3);
    cout << "Piece of the launch: " << launchPiece << '\n';

    // Epoch year (last two digits)
    string epochYear = line1.substr(18, 2);
    cout << "Epoch year (last two digits): " << epochYear << '\n';

    // Epoch (day of the year and fractional portion of the day)
    string Epoch = line1.substr(20, 12);
    cout << "Epoch: " << Epoch << '\n';

    // First derivative of mean motion; the ballistic coefficient
    string ballisticCoeff = line1.substr(33, 10);
    cout << "First derivative of mean motion (ballistic coefficient): " << ballisticCoeff << " (rev/day per day) \n";

    // Second derivative of mean motion
    string secondDerivMeanMotion = line1.substr(44, 8);
    cout << "Second derivative of mean motion: " << secondDerivMeanMotion << " (rev/day^3) \n";

    // B* (drag term)
    string bStar = line1.substr(53, 8);
    cout << "B*, the drag term: " << bStar << " (1/Earth radii) \n";

    // Ephemeris type
    string ephemerisType = line1.substr(62, 1);
    cout << "Ephemeris type: " << ephemerisType << '\n';

    // Element set number
    string elementSetNumber = line1.substr(64, 4);
    cout << "Element set number: " << elementSetNumber << '\n';

    // Check sum
    string checkSum = line1.substr(68);
    cout << "Checksum (modulo 10): " << checkSum << '\n';

    // LINE 2
    cout << "*-LINE 2 (Classical Orbital Elements)-*" << '\n';

    // Inclination
    string Inclination = line2.substr(8, 9);
    cout << "Inclination: " << Inclination << " (deg) \n";

    // Right ascension of the ascending node (RAAN)
    string RAAN = line2.substr(17, 8);
    cout << "Right ascension of the ascending node: " << RAAN << " (deg) \n";

    // Eccentricity
    string Eccentricity = line2.substr(26, 7);
    cout << "Eccentricity: " << Eccentricity << '\n';

    // Argument of perigee
    string argumentPerigee = line2.substr(34, 8);
    cout << "Argument of Perigee: " << argumentPerigee << " (deg) \n";

    // Mean anomaly
    string meanAnomaly = line2.substr(43, 8);
    cout << "Mean anomaly: " << meanAnomaly << " (deg) \n";

    // Mean motion
    string meanMotion = line2.substr(52, 11);
    cout << "Mean motion: " << meanMotion << " (revolutions per day) \n";

    // Revolution number at Epoch
    string revolutionNumber = line2.substr(63, 5);
    cout << "Revolution number at Epoch: " << revolutionNumber << " (revolutions) \n";

    return 0;
}
