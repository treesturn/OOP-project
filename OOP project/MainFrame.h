#ifndef MAINFRAME_H
#define MAINFRAME_H

#pragma once
#include <wx/wx.h>


class MainFrame:public wxFrame{

public:

	//parameterized construnctor
	MainFrame(const wxString& title);

	//username mutator
	void setusername(std::string new_username);

	//username getter
	std::string getusername();

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

#endif // MAINFRAME_H
