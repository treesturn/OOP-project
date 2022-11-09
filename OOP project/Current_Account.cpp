#include "Current_Account.h"

//default constructor
Current_Account::Current_Account()
{
    Account_bal = 0.00;
    Current_minimumAmount = 500.00;
}

//parameterized constructor
Current_Account::Current_Account(std::string pAccount_username, int pAccount_num, std::string pAccount_pin, float pAccount_bal)
    :Account(pAccount_username, pAccount_num, pAccount_pin, pAccount_bal)
{
    
    //set the minimum amount required
    Current_minimumAmount = 0;
}

//destructor
Current_Account::~Current_Account()
{

}

std::string Current_Account::title_header() const
{
    return ("Your Current Account");
}