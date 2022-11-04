#pragma once
#include "Account.h"

class Current_Account:public Account
{
public:
    // Constructors
    Current_Account();
    Current_Account(std::string pAccount_username, std::string pAccount_pin, int pAccount_num, float pAccount_bal, float pminmumAmount);

    // Destructor
    ~Current_Account();

    // Function to overwrite
    void print();

private:

    float Account_bal;
    float minimumAmount;
    std::string Account_username; 
    std::string Account_pin; 
    int Account_num;
};

