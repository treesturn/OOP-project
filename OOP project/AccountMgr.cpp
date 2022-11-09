#include "AccountMgr.h"
#include "AccountMgr.h"
#include "Savings_Account.h"
#include "Current_Account.h"

//default constructor
AccountMgr::AccountMgr()
{

}

//parameterized constructor


//destructor
AccountMgr::~AccountMgr()
{

}

//getters
std::vector<Account*> AccountMgr::getAcc_DB()
{
	return Accs_DB;
}