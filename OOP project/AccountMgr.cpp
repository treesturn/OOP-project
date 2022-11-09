#include "AccountMgr.h"
#include "AccountMgr.h"
#include "Account.h"
#include "Savings_Account.h"
#include "Current_Account.h"

//default constructor
AccountMgr::AccountMgr()
{

}

//parameterized constructor
//takes a unique chosen acc_num to be used for the rest of the session from Homepage
AccountMgr::AccountMgr(int p_chosen_accnum)
{
	chosen_accnum = p_chosen_accnum;

	for (Account* acc : Accs_DB)
	{
		if (chosen_accnum == acc->get_Account_num())
		{
			chosen_acc = acc;
			break;
		}
	}
}

//destructor
AccountMgr::~AccountMgr()
{

}

//getters
std::vector<Account*> AccountMgr::getAcc_DB()
{
	return Accs_DB;
}

Account* AccountMgr::getchosen_acc()
{
	return chosen_acc;
}