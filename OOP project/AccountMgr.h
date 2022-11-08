#ifndef ACCOUNTMGR_H
#define ACCOUNTMGR_H
#include <string>
#include "Account.h"
#include "Savings_Account.h"
#include "Current_Account.h"
#include <vector>

#pragma once
class AccountMgr
{
public:
    //default constructor
    AccountMgr();

    //parameterized constructor
    AccountMgr(std::string p_action);

    //destructor
    ~AccountMgr();

    /*std::string withdraw();

    std::string deposit();*/

    //getters
    std::vector<Savings_Account> getsavingsAcc_vect();

  

private:

    std::string action;

    //vector of class Savings_Account type
    std::vector<Savings_Account> savingsAccs = {

      {"Zeming", 2101800, "124", 4000.50, 0.04},
      {"Triston", 2101793, "123", 2500.50, 0.04},
      {"Brook", 2101789, "125", 5600.50, 0.04},
      {"Jonathan", 2101200, "126", 6500.50, 0.04},

    };

    //vector of class Current_Account type
    std::vector<Current_Account> currentAccs = {

      {"Triston Chan", 2101793, "123", 2500.50}
    };


};

#endif //ACCOUNTMGR