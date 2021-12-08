#include "Checking_Account.h"  
	
Checking_Account::Checking_Account(std::string name, double balance)
    : Account(name, balance) {}	
// Checking_Account::~Checking_Account(){}

bool Checking_Account::withdraw(double amount){
    return Account::withdraw(amount + 1.5);
}