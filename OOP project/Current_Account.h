#ifndef CURRENT_ACCOUNT_H
#define CURRENT_ACCOUNT_H

#pragma once
#include "Account.h"
//child class
class Current_Account:public Account
{
public:
    //default constructors
    Current_Account();

    //parameterized constructors
    Current_Account(std::string pAccount_username, int pAccount_num, std::string pAccount_pin, float pAccount_bal);

    //destructor
    ~Current_Account();

    //pure virtual function from parent class
    std::string title_header();

private:

    //members that will be inherited from parent class
    std::string Account_username;
    int Account_num;
    float Account_bal;
    std::string Account_pin;
    
    float Current_minimumAmount;
    
};

#endif // CURRENT_ACCOUNT_H