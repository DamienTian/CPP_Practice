#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H
#pragma once

#include "Account.h"
	
class Checking_Account : public Account
{
	private:
    	static constexpr const char *def_name = "Unnamed Account";
    	static constexpr double def_balance = 0.0;
	public:

		// Inherited from base class Account
		Checking_Account(std::string name = def_name, double balance = def_balance);
		// ~Checking_Account();

		bool withdraw(double amount);
};
#endif