#include "MyString.h"  
	
MyString::MyString() : str(nullptr) {
	str = new char[1];
    str[0] = '\0';
}
	
MyString::MyString(const char* str) : str(nullptr) {
    if(str == nullptr){
        this->str = new char[1];
        this->str[0] = '\0';
    }
    else{
        this->str = new char[std::strlen(str) + 1];
        strcpy(this->str, str);
    }
}

MyString::MyString(const MyString& mystring) : str(nullptr) {
    str = new char[std::strlen(mystring.str) + 1];
    strcpy(str, mystring.str);
    // std::cout << "Copy ctr constructor called" << std::endl;
}

MyString::MyString(MyString&& mystring) : str(mystring.str) {
    mystring.str = nullptr;
    // std::cout << "Move ctr constructor called" << std::endl;
}

MyString::~MyString(){
	delete [] str;
}

MyString& MyString::operator=(const MyString& rhs){
    // std::cout << "(Copy assignment called on \"" << rhs.str << "\")" << std::endl;
    if(this == &rhs){
        return *this;
    }
    // Clean exist allocated space
    delete [] str;
    // Allocate new space
    str = new char[std::strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

MyString& MyString::operator=(MyString&& rhs){
    // std::cout << "(Move assignment called on \"" << rhs.str << "\")" << std::endl;
    if(this == &rhs){
        return *this;
    }
    // Clean exist allocated space
    delete [] str;
    // Point to the rhs.str and set rhs.str to null
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

char& MyString::operator[](int index){
    // https://www.geeksforgeeks.org/overloading-subscript-or-array-index-operator-in-c/
    if (index >= getLength()) {
        std::cout << "Index out of bound, exiting";
        exit(0);
    }
    return str[index];
}

int MyString::getLength(){
    return std::strlen(str);
}

const char* MyString::getString(){
    return str;
}

MyString operator-(const MyString& myString){
    char* resultChar = new char[std::strlen(myString.str) + 1];
    for(int i {0}; i < std::strlen(myString.str); ++i){
        resultChar[i] = std::tolower(myString.str[i]);
    }
    MyString result(resultChar);
    delete [] resultChar;
    return result;
}

MyString operator+(const MyString& lhs, const MyString& rhs){
    char* resultChar = new char[std::strlen(lhs.str) + std::strlen(rhs.str) + 1];
    strcpy(resultChar, lhs.str);
    strcat(resultChar, rhs.str);
    MyString result(resultChar);
    delete [] resultChar;
    return result;
}

MyString& operator+=(MyString& lhs, const MyString& rhs){
    lhs = lhs + rhs;
    return lhs;
}

MyString operator*(const MyString& lhs, int time){
    char* resultChar {new char[std::strlen(lhs.str) * time + 1]};
    strcpy(resultChar, lhs.str);
    for(int i {1}; i < time; ++i){
        strcat(resultChar, lhs.str);
    }
    MyString result(resultChar);
    delete [] resultChar;
    return result;
}

MyString& operator*=(MyString& lhs, int time){
    lhs = lhs * time;
    return lhs;
}

bool operator==(const MyString& lhs, const MyString& rhs){
    return std::strcmp(lhs.str, rhs.str) == 0;
}

bool operator!=(const MyString& lhs, const MyString& rhs){
    return std::strcmp(lhs.str, rhs.str) != 0;
}

bool operator<(const MyString& lhs, const MyString& rhs){
    return std::strcmp(lhs.str, rhs.str) < 0;
}

bool operator>(const MyString& lhs, const MyString& rhs){
    return std::strcmp(lhs.str, rhs.str) > 0;
}

std::ostream& operator<<(std::ostream& os, const MyString& myString){
    os << myString.str;
    return os;
}

std::istream& operator>>(std::istream& is, MyString& myString){
    char* temp {new char[1000]};
    is >> temp;
    myString = MyString(temp);
    delete [] temp;
    return is;
}

MyString& operator++(MyString& myString){
    for(int i {0}; i < std::strlen(myString.str); ++i){
        myString[i] = std::toupper(myString[i]);
    }
    return myString;
}

MyString operator++(MyString& myString, int){
    MyString result(myString);
    ++myString;
    return result;
}

MyString& operator--(MyString& myString){
    for(int i {0}; i < std::strlen(myString.str); ++i){
        myString[i] = std::tolower(myString[i]);
    }
    return myString;
}

MyString operator--(MyString& myString, int){
    MyString result(myString);
    --myString;
    return result;
}