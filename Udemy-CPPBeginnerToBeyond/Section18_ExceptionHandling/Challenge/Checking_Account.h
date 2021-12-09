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
		virtual ~Checking_Account() = default;

		// Learning Note:
    	//  Need to override (rewrite) all virtual functions in the pure virtual base class
    	//  in order to solve complier error, otherwise the derived class is also a pure virtual class,
    	//  and cannot be initialize.
		virtual bool deposit(double amount) override;
		virtual bool withdraw(double amount) override;
		virtual void print(std::ostream &os) const override;
};
#endif