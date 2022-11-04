#pragma once
#include <string>

class Account
{
public:

	//default construtor
	Account();

	//parameterized constructor
	Account(std::string pAccount_username, std::string pAccount_pin, int pAccount_num, float pAccount_bal);



	//mutators
	void set_Account_username(std::string text);

	void set_Account_num(int num);

	void set_Account_bal(float bal);

	//getters
	std::string get_Account_username() const;

	int get_Account_num() const;

	float get_Account_bal() const;

	std::string get_Account_pin() const;

private:

	//variables
	std::string Account_username;
	std::string Account_pin;
	int Account_num;
	float Account_bal;

};

