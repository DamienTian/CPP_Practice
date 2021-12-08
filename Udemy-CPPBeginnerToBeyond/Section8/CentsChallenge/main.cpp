/*
 * Section 8 Challenge 
 * Cents calculator: enter the amount of cents and calculate the way of changing money
 * */

#include <iostream>

using namespace std;

int main(){
    int cents {0};
    
    cout << "Enter an amount in cents: ";
    cin >> cents;
    
    // change rate (equals to how much cents)
    const int centToDollar {100},
                     centToQuarter {25},
                     centToDime {10},
                     centToNickel {5},
                     centToPenny {1};
    
    // amout of change result
    int dollar {0}, quarter {0}, dime {0}, nickel {0}, penny {0};
    
    // Calculate results
    dollar = cents / centToDollar;
    cents %= centToDollar;
    
    quarter = cents / centToQuarter;
    cents %= centToQuarter;
    
    dime = cents / centToDime;
    cents %= centToDime;
    
    nickel = cents / centToNickel;
    cents %= centToNickel;
    
    penny = cents / centToPenny;
    cents %= centToPenny;
    
    // Print results
    cout << "Dollar: " << dollar << endl;
    cout << "Quarter: " << quarter << endl;
    cout << "Dime: " << dime << endl;
    cout << "Nickel: " << nickel << endl;
    cout << "Penny: " << penny << endl;
    
    return 0;
}