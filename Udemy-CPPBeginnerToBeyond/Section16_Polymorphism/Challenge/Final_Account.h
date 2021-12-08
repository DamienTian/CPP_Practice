#ifndef FINAL_ACCOUNT_H
#define FINAL_ACCOUNT_H
#pragma once

#include "Trust_Account.h"

class Final_Account : public Trust_Account
{
	private:

	public:

		Final_Account();
		// virtual ~Final_Account();

		// NOTE: without "virtual" keyword is NOT the best practice
		bool deposit(double amount) override{
			std::cout << "You cannot overwrite a final\n";
			return true;
		};

		
};
#endif