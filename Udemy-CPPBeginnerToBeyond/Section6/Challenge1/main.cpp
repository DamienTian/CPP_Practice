#include <iostream>

using std::cout;
using std::endl;
using std::cin;

// function for calculate the total prices (w\o tax)
// note: I wrote this only for FUN!
float totalCost(int smallRoomCount, float smallRoomPrice, int largeRoomCount, float largeRoomPrice, float taxRate, bool withTax){
    float withoutTaxCost {smallRoomCount * smallRoomPrice + largeRoomCount * largeRoomPrice};
    if(!withTax){
        return withoutTaxCost;
    }
    else{
        return withoutTaxCost * (1 + taxRate);
    }
    return -1;
}

int main(){
    
    // Prices
    const float smallRoomPrice {25.0};
    const float largeRoomPrice {35.0};
    // Slaes tax rate
    const float salesTaxRate {0.06};
    // Estimate valid days
    const int estimatedValidDays {30};
    
    // number of rooms
    int smallRoomCount {0}, largeRoomCount {0};

    cout << "Hello, welcome to Hao's carpet cleaning company.\n";
    cout << "How many small rooms would you like cleaned? ";
    cin >> smallRoomCount;
    cout << "How many large rooms would you like cleaned? ";
    cin >> largeRoomCount;
    
    cout << endl;
    cout << "Estimate for carpet cleaning services" << endl;
    cout << "Number of small rooms: " << smallRoomCount << endl;
    cout << "Number of slarge rooms: " << largeRoomCount << endl;
    cout << "Price per small room: $" << smallRoomPrice << endl;
    cout << "Price per large room: $" << largeRoomPrice << endl;
    cout << "Cost: $" << totalCost(smallRoomCount, smallRoomPrice, largeRoomCount, largeRoomPrice, salesTaxRate, false) << endl;
    cout << "Tax: $" << totalCost(smallRoomCount, smallRoomPrice, largeRoomCount, largeRoomPrice, salesTaxRate, false)  * salesTaxRate << endl;
    cout << "=======================" << endl;
    cout << "Total estimate: $" << totalCost(smallRoomCount, smallRoomPrice, largeRoomCount, largeRoomPrice, salesTaxRate, true) << endl;
    cout << "This estimate is valid for " << estimatedValidDays <<" days" << endl;
    
    return 0;
}