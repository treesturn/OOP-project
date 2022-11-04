#ifndef SIGNIN_H
#define SIGNIN_H

#pragma once
#include <wx/wx.h>


class SignIn:public wxFrame{

public:

	//default constructor
	SignIn();
	
	//parameterized construnctor
	SignIn(const wxString& title);

	//username mutator
	void setusername(std::string new_username);

	void setpin(std::string new_pin);

	//username getter
	std::string getusername();

	std::string getpin();

private:

	//variables
	std::string username = "";
	std::string pin = "";
	wxTextCtrl* usernameinput;
	wxTextCtrl* pininput;
	wxButton* loginbutton;
	wxBitmap  my_square;
	
	//when login button clicked
	void OnLoginButtonClicked(wxCommandEvent& event);
};

#endif // SIGNIN_H
