/*
 * Challenge Assignment 1
 * Author: Hao Tian
*/

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(){
    string input {};
    cout << "Enter the string to make the pyramid: ";
    cin >> input;
    
    // Outer loop for building levels of pyramid
    for(int i {0}; i < input.length(); ++i){
        // Calculate the number of letter in each level
        const int numberOfLetter {i * 2 + 1};
        // Indication of the half of the numberOfLetter, used for switch the search order
        const int half {numberOfLetter / 2 + 1};
        // Number of space to add on the left of the level
        const int numberOfSpace {static_cast<int>(input.length()) - (i + 1)};
        
        // Level
        string level {};
        // Record the current index of the input string 
        int indexRecord {0};
        
        // Build a level
        for(int j {0}; j < numberOfLetter; ++j){
            // Concatenate letter(s)
            level += input.at(indexRecord);
            
            // Switch the looping direction if half of the level has been built
            if(level.length() < half){
                ++indexRecord;
            }
            else{
                --indexRecord;
            }
        }
        
        // Concatenate space on the left
        string spaceOnLeft (numberOfSpace, ' ');
        level = spaceOnLeft + level;
        
        // Print out the level
        cout  << level << endl;
    }
    
    return 0;
}