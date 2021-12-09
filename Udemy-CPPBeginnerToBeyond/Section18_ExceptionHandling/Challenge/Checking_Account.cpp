#include "Checking_Account.h"  
	
Checking_Account::Checking_Account(std::string name, double balance)
    : Account(name, balance) {}	

bool Checking_Account::deposit(double amount){
    return Account::deposit(amount);
}

bool Checking_Account::withdraw(double amount){
    return Account::withdraw(amount + 1.5);
}

void Checking_Account::print(std::ostream &os) const{
    os << "[Checking Account: " << name << ": " << balance << "]";
}