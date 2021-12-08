#include "MyString.h"

int main(){
    MyString empty;
    MyString great("Great");
    MyString myWife(great);
    MyString moveCtr(MyString("move"));

    myWife = moveCtr;
    myWife = "Sexy and Beautiful";

    MyString wifeLower = -myWife;
    MyString myGreatWife = myWife + great;

    //std::cout << myWife << " " << wifeLower << " " << myGreatWife << std::endl; 

    // Test < > == !=
    std::cout << (myWife == myWife ? "T" : "F") << std::endl;
    std::cout << (myWife != wifeLower ? "T" : "F") << std::endl;
    std::cout << (myWife > wifeLower ? "T" : "F") << std::endl;
    std::cout << (myWife < wifeLower ? "T" : "F") << std::endl;
    std::cout << (myWife != myGreatWife ? "T" : "F") << std::endl;
    std::cout << (myWife > myGreatWife ? "T" : "F") << std::endl;
    std::cout << (myWife < myGreatWife ? "T" : "F") << std::endl;


    // Invalid test for member function +
    // MyString friendMyString {"Friend " + myWife + " " + great};

    // std::cout << "\n" << std::endl;

    // Test +=
    empty += great;
    std::cout << empty << std::endl;

    // Test * *=
    MyString times {empty * 3};
    MyString selfTimes {great};
    selfTimes *= 3;
    std::cout << times << "\t" << selfTimes << std::endl;

    // Test []
    for(int i {0}; i < 5; ++i){
        std::cout << times[i] << std::endl;
    }


    // MyString input;
    // std::cout << "Enter a string without space: ";
    // std::cin >> input;
    // std::cout << "Your input is " << input << std::endl;

    MyString caseSwitch {"sWiTcH iS FuN LoL!"};

    std::cout << ++caseSwitch << std::endl;
    std::cout << caseSwitch << std::endl << std::endl;

    std::cout << --caseSwitch << std::endl;
    std::cout << caseSwitch << std::endl << std::endl;

    std::cout << caseSwitch++ << std::endl;
    std::cout << caseSwitch << std::endl << std::endl;

    std::cout << caseSwitch-- << std::endl;
    std::cout << caseSwitch << std::endl << std::endl;

    return 0;
}