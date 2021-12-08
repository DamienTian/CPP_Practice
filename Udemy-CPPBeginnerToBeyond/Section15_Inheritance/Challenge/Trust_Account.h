#ifndef TRUST_ACCOUNT_H
#define TRUST_ACCOUNT_H
#pragma once

#include "Savings_Account.h"

class Trust_Account : public Savings_Account
{
	private:
		static constexpr const char *def_name = "Unnamed Savings Account";
    	static constexpr double def_balance = 0.0;
    	static constexpr double def_int_rate = 0.0;
		int withdraw_times {3};

	public:

		Trust_Account(std::string name = def_name, double balance =def_balance, double int_rate = def_int_rate);
		// ~Trust_Account();

		bool deposit(double amount);
    	bool withdraw(double amount);

		int get_withdraw_times() {return withdraw_times;}
		void set_withdraw_times(int withdraw_times) {this->withdraw_times = withdraw_times;}
};
#endif