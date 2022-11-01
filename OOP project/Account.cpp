#include "Account.h"
#include <string>
using namespace std;

//default constructor implementation
Account::Account()
{

}

//parameterized constructor implementation
Account::Account(string pAccount_username, int pAccount_num, double pAccount_bal)
{
	Account_username = pAccount_username;
	Account_num = pAccount_num;
	Account_bal = pAccount_bal;
}

//mutators
void Account::set_Account_username(std::string text)
{
	Account_username = text;
}

void Account::set_Account_num(int num)
{
	Account_num = num;
}

void Account::set_Account_bal(double bal)
{
	Account_bal = bal;
}

//getters
string Account::get_Account_username() const
{
	return Account_username;
}

int Account::get_Account_num() const
{
	return Account_num;
}

double Account::get_Account_bal() const
{
	return Account_bal;
}