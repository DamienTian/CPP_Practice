// Section 19 Challenge 4
// Add Line Number to .txt file
// Answer by Hao Tian

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

// Function Prototypes
void addLineNum(std::ifstream& inFile, std::ofstream& outFile, bool lineHasTextOnly);

int main(){
    std::ifstream inFile {"romeoandjuliet.txt"};
    std::ofstream outFile{"romeoandjuliet_line.txt"};
    if (!inFile) {
        std::cerr << "Error opening input file" << std::endl;
        return 1;
    }
     if (!outFile) {
        std::cerr << "Error opening output file" << std::endl;
        return 1;
    }
    
    addLineNum(inFile, outFile, true);
    
    return 0;
}

// Add line number
void addLineNum(std::ifstream& inFile, std::ofstream& outFile, bool lineHasTextOnly){
    std::string line{};
    int currentLine {1};
    while (std::getline(inFile, line)){
        if(lineHasTextOnly){
            if(!line.empty()){
                outFile << std::setw(10) << std::left << std::setfill(' ') 
                    << currentLine << line << std::endl;
                currentLine++;
            }
            else{
                outFile << line << std::endl;
            }
        }
        else{
            outFile << std::setw(10) << std::left
                << currentLine << line << std::endl;
            currentLine++;
        }
    }
    
    std::cout << "File copied" << std::endl;
    inFile.close();
    outFile.close();
}

