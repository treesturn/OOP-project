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

    //mutator
    //takes accnum from SignIn window choosen acc and sets it as that acc num
    void set_accnum(int num);

    /*std::string withdraw();

    std::string deposit();*/

    /*Savings_Account intialize_chosen_acc();*/

    //vector of class Savings_Account type
    std::vector<Savings_Account> savingsAccs = {

      {"Zeming", 2101800, "124", 4000.50, 0.04},
      {"Triston Chan", 2101793, "123", 2500.50, 0.04}
    };

    //vector of class Current_Account type
    std::vector<Current_Account> currentAccs = {

      {"Triston Chan", 2101793, "123", 2500.50}
    };

private:

    std::string action;
    int accnum;


};

#endif //ACCOUNTMGR