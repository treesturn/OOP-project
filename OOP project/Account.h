#pragma once
#include <string>

class Account
{
public:

	//default construtor
	Account();

	//parameterized constructor
	Account(std::string pAccount_username, int pAccount_num, double pAccount_bal);



	//mutators
	void set_Account_username(std::string text);

	void set_Account_num(int num);

	void set_Account_bal(double bal);

	//getters
	std::string get_Account_username() const;

	int get_Account_num() const;

	double get_Account_bal() const;

private:

	//variables
	std::string Account_username;
	int Account_num;
	double Account_bal;

};

