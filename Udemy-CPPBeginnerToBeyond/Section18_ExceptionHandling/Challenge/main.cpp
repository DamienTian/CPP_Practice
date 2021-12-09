// Section 15
// Challenge 
#include <iostream>
#include <vector>
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Final_Account.h"
#include "Account_Util.h"
#include "IllegalBalanceException.h"
#include "InsufficientFundsException.h"


using namespace std;

void saving_account_test(){
    // Savings 
    vector<Account*> sav_accounts;

    Account* empty {new Savings_Account()};
    Account* superman {new Savings_Account("Superman")};
    Account* batman {new Savings_Account("Batman", 2000)};
    Account* wonderwoman {new Savings_Account("Wonderwoman", 5000, 5.0)};

    sav_accounts.push_back(empty);
    sav_accounts.push_back(superman);
    sav_accounts.push_back(batman);
    sav_accounts.push_back(wonderwoman);
    
    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts, 2000);
    cout << endl;

    delete empty;
    delete superman;
    delete batman;
    delete wonderwoman;
}

void checking_account_test(){
    // Checking
    vector<Account*> check_accounts;

    Account* empty {new Checking_Account()};
    Account* sam {new Checking_Account("Sam")};
    Account* dead_man {new Checking_Account("Dead Man")};
    Account* heart_man {new Checking_Account("Heart Man", 3000.0)};

    check_accounts.push_back(empty);
    check_accounts.push_back(sam);
    check_accounts.push_back(dead_man);
    check_accounts.push_back(heart_man);

    display(check_accounts);
    deposit(check_accounts, 1000);
    withdraw(check_accounts, 2000);
    cout << endl;

    delete empty;
    delete sam;
    delete dead_man;
    delete heart_man;
}

void trust_account_test(){
    // Trust
    vector<Account*> trust_accounts;

    Account* empty {new Trust_Account()};
    Account* oscar {new Trust_Account("Oscar")};
    Account* solar {new Trust_Account("Solar", 2000)};
    Account* gwen {new Trust_Account("Gwen", 6000)};

    trust_accounts.push_back(empty);
    trust_accounts.push_back(oscar);
    trust_accounts.push_back(solar);
    trust_accounts.push_back(gwen);

    display(trust_accounts);
    deposit(trust_accounts, 1000);
    deposit(trust_accounts, 6000);
    withdraw(trust_accounts, 2000);
    withdraw(trust_accounts, 1000);
    withdraw(trust_accounts, 500);
    withdraw(trust_accounts, 250);
    cout << endl;

    delete empty;
    delete oscar;
    delete solar;
    delete gwen;
}

int main() {
    cout.precision(2);
    cout << fixed;

    Account* final_account {nullptr}; 
    double input1 {0}, input2 {0};

    try{
        std::cout << "Enter an init price: ";
        std::cin >> input1;
        final_account = new Savings_Account("Final", input1);
        std::cout << "Enter an withdraw price: ";
        std::cin >> input2;
        final_account->withdraw(input2);
    }
    catch(IllegalBalanceException& ex){
        std::cout << ex.what() << std::endl;
    }
    catch(InsufficientFundsException& ex){
        std::cout << ex.what() << std::endl;
    }

    if(final_account)
        delete final_account;

    return 0;
}


