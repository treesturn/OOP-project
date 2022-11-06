#include <string>
#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#pragma once
#include "Account.h"

class Savings_Account :public Account
{

public:

	//default constructor
	Savings_Account();

	//parameterized constructor
	Savings_Account(std::string pAccount_username, int pAccount_num, std::string pAccount_pin, float pAccount_bal, float pSavings_interestrate);

	//destructor
	~Savings_Account();

	//mutators
	void setinterestrate(float pSavings_interestrate);

	//getters
	float getinterestrate() const;

	float getAccount_bal() const;

	float getInterest() const;

	//pure virtual function from parent class
	std::string title_header();

private:
	
	//members that will be inherited from parent class
	std::string Account_username;
	int Account_num;
	float Account_bal;
	std::string Account_pin;
	
	//only savings account have interest rate
	float Savings_interestrate;
	float Savings_interest;
	int Savings_timesoftransactions;
};

#endif // SAVINGS_ACCOUNT_H