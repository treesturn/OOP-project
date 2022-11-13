#include "Savings_Account.h"


//default constructor
Savings_Account::Savings_Account()
{

}

//parameterized constructor
Savings_Account::Savings_Account(std::string pAccount_username, int pAccount_num, std::string pAccount_pin, float pAccount_bal, float pSavings_interestrate)
	:Account(pAccount_username, pAccount_num, pAccount_pin, pAccount_bal)
{	
	Savings_interestrate = pSavings_interestrate;
	Savings_interest = 0;
	Savings_timesoftransactions = 0;
}

//destructor
Savings_Account::~Savings_Account()
{
	
}

//mutators
void Savings_Account::setinterestrate(float pSavings_interestrate)
{
	Savings_interestrate = pSavings_interestrate;
}

//getters
float Savings_Account::getinterestrate() const
{
	return Savings_interestrate;
}

float Savings_Account::getAccount_bal() const
{
	return Account_bal;

}

float Savings_Account::getInterest() const
{
	return Savings_interest;
}

std::string Savings_Account::title_header() const
{
	return ("Your Savings Account");
}