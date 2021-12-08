#include "helper.h"
// #include <iostream>

int main(){
    std::cout << "Enter your favorite number between 0-100: ";
    int res = helperFunction();
    std::cout << "Amazing!! That's my favorite number too! " << res << std::endl;
    std::cout << "No Really!! " << res << " is my favorite number!" << std::endl;
    return 0;
}