#ifndef TRUST_ACCOUNT_H
#define TRUST_ACCOUNT_H
#pragma once

#include "Savings_Account.h"

// NOTE
// Deposit:
//		Will be test with "final" keyword
// Withdraw:
//		Will be test with "final" keyword
//

class Trust_Account : public Savings_Account
{
	private:
		static constexpr const char *def_name = "Unnamed Savings Account";
    	static constexpr double def_balance = 0.0;
    	static constexpr double def_int_rate = 0.0;
		int withdraw_times {3};

	public:

		Trust_Account(std::string name = def_name, double balance =def_balance, double int_rate = def_int_rate);
		virtual ~Trust_Account() = default;
		
		// Learning Note:
    	//  Need to override (rewrite) all virtual functions in the pure virtual base class
    	//  in order to solve complier error, otherwise the derived class is also a pure virtual class,
    	//  and cannot be initialize.
		virtual bool deposit(double amount) override /*final*/;
    	virtual bool withdraw(double amount) override final;
		virtual void print(std::ostream& os) const override;
};
#endif