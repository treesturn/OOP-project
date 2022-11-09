#ifndef ACCOUNT_H
#define ACCOUNT_H

#pragma once
#include <string>

//parent class and an ABC
class Account
{
public:

	//default construtor
	Account();

	//parameterized constructor
	Account(std::string pAccount_username, int pAccount_num, std::string pAccount_pin, float pAccount_bal);

	//destructor
	~Account();
	
	//mutators
	void set_Account_username(std::string text);

	void set_Account_num(int num);

	void set_Account_bal(float bal);

	//getters
	std::string get_Account_username() const;

	int get_Account_num() const;

	float get_Account_bal() const;

	std::string get_Account_pin() const;

	//PURE virtual function that must be overidden in child class, making this class an ABC
	virtual std::string title_header() const = 0;

private:

	//members
	std::string Account_username;
	int Account_num;
	std::string Account_pin;
	float Account_bal;

};

#endif // ACCOUNT_H