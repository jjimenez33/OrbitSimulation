#include <iostream>
#include <string>
#include <fstream>
 
// This is a program for parsing Two Line Elements (TLEs) and printing the result.

int main() {
    // Open the file
    std::ifstream file("TLE_ISS.txt");
    
    // Check that it opened succesfully
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file." << std::endl;
        return 1;
    }

    // Read and print the file
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << '\n';
    }

    // Close the file
    file.close();
    return 0;
}
