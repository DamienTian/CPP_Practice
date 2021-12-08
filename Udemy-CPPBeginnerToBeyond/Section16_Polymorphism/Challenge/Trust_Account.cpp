#include "Trust_Account.h"  
	
Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    : Savings_Account(name, balance, int_rate) {}
// Trust_Account::~Trust_Account(){}

bool Trust_Account::deposit(double amount){
    return Savings_Account::deposit((amount > 5000.0 ? amount + 50.0 : amount));
}

bool Trust_Account::withdraw(double amount){
    if(withdraw_times <= 0 || amount >= 0.2 * balance)
        return false;
    --withdraw_times;
    return Savings_Account::withdraw(amount);
}

void Trust_Account::print(std::ostream &os) const {
    os << "[Trust Account: " << name << ": " << balance << " Int Rate: " << int_rate << " Withdraw Time Left: " << withdraw_times << "]";
}