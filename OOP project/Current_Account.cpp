#include "Current_Account.h"
#include "Account.h"

// Default constructor
Current_Account::Current_Account()
{
    Account_bal = 0.00;
    minimumAmount = 500.00;
}

//
// Parameterized constructor. Note the use of the initializer list to tell the
// compiler to invoke the base class parameterized constructor.
//
Current_Account::Current_Account(std::string pAccount_username, std::string pAccount_pin, int pAccount_num, float pAccount_bal, float pminmumAmount)
    :Account(pAccount_username, pAccount_pin, pAccount_num, pAccount_bal)
{

    // Set the minimum amount required
    minimumAmount = pminmumAmount;
}

//
// Destructor
//
Current_Account::~Current_Account()
{

}

//
// This override of the base class function prints out additional information
// specific to this type of bin.
//
void Current_Account::print()
{
    if (Account_bal < 500.00)
    {
        throw "Minimum amount must be 500.00";
    }
}