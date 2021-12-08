// Section 15
// Challenge 
#include <iostream>
#include <vector>
//#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;

int main() {
    cout.precision(2);
    cout << fixed;
   
    // // Accounts
    // vector<Account> accounts;
    // accounts.push_back(Account {});
    // accounts.push_back(Account {"Larry"});
    // accounts.push_back(Account {"Moe", 2000} );
    // accounts.push_back(Account {"Curly", 5000} );
    
    // cout << "=== Account ================="<< endl;
    // display(accounts);
    // deposit(accounts, 1000);
    // withdraw(accounts,2000);
    // cout << endl;
    
    // // Savings 
    // vector<Savings_Account> sav_accounts;
    // sav_accounts.push_back(Savings_Account {} );
    // sav_accounts.push_back(Savings_Account {"Superman"} );
    // sav_accounts.push_back(Savings_Account {"Batman", 2000} );
    // sav_accounts.push_back(Savings_Account {"Wonderwoman", 5000, 5.0} );
    
    // display(sav_accounts);
    // deposit(sav_accounts, 1000);
    // withdraw(sav_accounts, 2000);
    // cout << endl;

    // Checking
    vector<Checking_Account> check_accounts;
    check_accounts.push_back(Checking_Account {} );
    check_accounts.push_back(Checking_Account {"Sam"} );
    check_accounts.push_back(Checking_Account {"Dead Man"} );
    check_accounts.push_back(Checking_Account {"Heart Man", 3000.0} );

    display(check_accounts);
    deposit(check_accounts, 1000);
    withdraw(check_accounts, 2000);
    cout << endl;
    
    // Trust
    vector<Trust_Account> trust_accounts;
    trust_accounts.push_back(Trust_Account {});
    trust_accounts.push_back(Trust_Account {"Oscar"});
    trust_accounts.push_back(Trust_Account {"Solar", 2000});
    trust_accounts.push_back(Trust_Account {"Gwen", 6000});

    display(trust_accounts);
    deposit(trust_accounts, 1000);
    deposit(trust_accounts, 6000);
    withdraw(trust_accounts, 2000);
    withdraw(trust_accounts, 1000);
    withdraw(trust_accounts, 500);
    withdraw(trust_accounts, 250);
    cout << endl;

    return 0;
}

