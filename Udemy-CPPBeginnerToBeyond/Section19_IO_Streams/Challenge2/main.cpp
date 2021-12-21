// Section 19 Challenge 2
// Automated Grader
// Answer by Hao Tian

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

int main(){
    const std::string file_name {"responses.txt"};
    
    // Open file
    std::fstream in_file;
    in_file.open(file_name, std::fstream::in);
    if(!in_file.is_open()){
        std::cerr << "Error opening file" << std::endl;
        return -1;
    }
    
    // Read answer
    std::string answer {};
    in_file >> answer;
    
    // Read responds and output result
    int d {20};
    std::cout << std::setfill(' ') << std::setw(d) << std::left 
                << "Name" << "Score" << std::endl;
    std::cout << std::setfill('-') << std::setw(d*2) << std::left 
                << "" << std::setfill(' ') << std::endl;
    
    // Read in input holder
    std::string name {}, res {};
    // Store total scores and number of students
    double totalScore {0.0}, numOfStudents {0};
    while(in_file >> name >> res){
        // Calculate score for each student
        int score {0};
        for(size_t i {0}; i < res.length(); ++i){
            score += (res[i] == answer[i]) ? 1 : 0;
        }
        
        // Print out output
        std::cout << std::setw(d) << std::left 
                << name << score << "/" << res.length() << std::endl;
                
        // Accumulate score and number of students
        totalScore += score;
        numOfStudents++;
    }
    
    std::cout << std::setfill('=') << std::setw(d*2) << std::left 
                << "" << std::setfill(' ') << std::endl;
    std::cout << std::setfill(' ') << std::setw(d) << std::left 
                << "Average" << totalScore/numOfStudents << std::endl;
                
    in_file.close();
    
    return 0;
}