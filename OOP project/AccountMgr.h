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
    //takes a unique chosen acc_num to be used for the rest of the session from Homepage
    //constructor overloading
    AccountMgr(int p_chosen_accnum);

    //destructor
    ~AccountMgr();

    //getters
    std::vector<Account*>getAcc_DB();
    Account* getchosen_acc();

  

private:

    int chosen_accnum;
    Account* chosen_acc;

    //vector of Account pointer type
    std::vector<Account*> Accs_DB = {

      new Savings_Account{"Zeming", 2101800, "124", 4000.50, 0.04},
      new Current_Account{"Zeming", 3101800, "124", 4000.50},

      new Savings_Account{"Triston", 2101793, "123", 2500.50, 0.04},
      new Current_Account{"Triston", 3101793, "123", 2500.50},

      new Savings_Account{"Brook", 2101789, "125", 5600.50, 0.04},
      new Current_Account{"Brook", 3101789, "125", 5600.50},

      new Savings_Account{"Jonathan", 2101200, "126", 6500.50, 0.04},
      new Current_Account{"Jonathan", 3101200, "126", 6500.50}

    };


};

#endif //ACCOUNTMGR