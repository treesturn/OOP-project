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

//getters
std::vector<Savings_Account> AccountMgr::getsavingsAcc_vect()
{
	return savingsAccs;
}