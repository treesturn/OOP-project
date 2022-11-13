#include "AccountMgr.h"
#include "AccountMgr.h"
#include "Account.h"
#include "Savings_Account.h"
#include "Current_Account.h"
#include <string>

//default constructor
AccountMgr::AccountMgr()
{

}

//parameterized constructor
//takes a unique chosen acc_num to be used for the rest of the session from Homepage
AccountMgr::AccountMgr(int p_chosen_accnum)
{
	chosen_SavAccnum = p_chosen_accnum;
	//current account always savings account num + 1
	chosen_CurrAccnum = p_chosen_accnum + 1;

	//for (Account* acc : Accs_DB)
	//{
	//	if (chosen_SavAccnum == acc->get_Account_num())
	//	{
	//		chosen_SavAcc = acc;
	//		chosen_CurrAcc = 
	//		break;
	//	}
	//}

	for (int i = 0; i < Accs_DB.size()-1; i++)
	{
		if (chosen_SavAccnum == Accs_DB[i]->get_Account_num())
		{
			//current_account always savings_account num + 1
			chosen_SavAcc = Accs_DB[i];
			chosen_CurrAcc = Accs_DB[i + 1];
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

Account* AccountMgr::getchosen_SavAcc()
{
	return chosen_SavAcc;
}

Account* AccountMgr::getchosen_CurrAcc()
{
	return chosen_CurrAcc;
}