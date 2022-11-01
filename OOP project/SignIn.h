#ifndef SIGNIN_H
#define SIGNIN_H

#pragma once
#include <wx/wx.h>


class SignIn:public wxFrame{

public:

	//parameterized construnctor
	SignIn(const wxString& title);

	//username mutator
	void setusername(std::string new_username);

	void setpassword(std::string new_password);

	//username getter
	std::string getusername();

	std::string getpassword();

private:

	//variables
	std::string username = "";
	std::string password = "";
	wxTextCtrl* usernameinput;
	wxTextCtrl* passwordinput;
	wxButton* loginbutton;
	
	//when login button clicked
	void OnLoginButtonClicked(wxCommandEvent& event);
};

#endif // SIGNIN_H
