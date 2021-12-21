// Section 19 Challenge 3
// Word finder
// Answer by Hao Tian

#include <iostream>
#include <fstream>
#include <string>

int main(){
    const std::string file_name {"romeoandjuliet.txt"};
    int total_word {0}, matched_word {0};
    
    // Open file
    std::fstream in_file;
    in_file.open(file_name, std::fstream::in);
    if(!in_file.is_open()){
        std::cerr << "Error opening file" << std::endl;
        return -1;
    }
    
    // Read input and store in target
    std::string target {};
    std::cout << "Enter the word you want to search: ";
    std::cin >> target;
    
    // Read words in file and find substring
    std::string word;
    while(in_file >> word){
        if(word.find(target) != std::string::npos){
            matched_word++;
        }
        total_word++;
    }
    
    std::cout << "Total words: " << total_word << std::endl;
    std::cout << "Matched target :\"" << target << "\" words: " << matched_word << std::endl;
    
    in_file.close();
    
    return 0;
}