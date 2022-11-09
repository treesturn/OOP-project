#include "Account.h"
#include <string>
using namespace std;

//default constructor 
Account::Account()
{

}

//parameterized constructor 
Account::Account(std::string pAccount_username, int pAccount_num, std::string pAccount_pin, float pAccount_bal)
{
	Account_username = pAccount_username;
	Account_num = pAccount_num;
	Account_pin = pAccount_pin;
	Account_bal = pAccount_bal;
	
}

//destructor
Account::~Account()
{

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

void Account::set_Account_bal(float bal)
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

float Account::get_Account_bal() const
{
	return Account_bal;
}

string Account::get_Account_pin() const
{
	return Account_pin;
}

//std::string Account::title_header()
//{
//	return ("Your Account");
//}