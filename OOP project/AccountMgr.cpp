#include "AccountMgr.h"
#include "AccountMgr.h"
#include "Savings_Account.h"
#include "Current_Account.h"

//default constructor
AccountMgr::AccountMgr()
{

}

//parameterized constructor
AccountMgr::AccountMgr(std::string p_action)
{
	action = p_action;
}

//destructor
AccountMgr::~AccountMgr()
{

}

//mutator
//takes accnum from SignIn window choosen acc and sets it as that acc num
void AccountMgr::set_accnum(int num)
{
	accnum = num;
}

//Savings_Account AccountMgr::intialize_chosen_acc()
//{
//  for (Savings_Account acc : savingsAccs)
//  {
//    if (acc.get_Account_num() == accnum)
//    {
//      return acc;
//    }
//
//  }
//}