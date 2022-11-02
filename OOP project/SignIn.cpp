#include "SignIn.h"
#include "HomePage.h"
#include <wx/wx.h>

//Mutators
void SignIn::setusername(std::string new_username) {
	
	username = new_username;
}

void SignIn::setpassword(std::string new_password) {
	
	password = new_password;
}

//Getters
std::string SignIn::getusername()
{
	return username;
}

std::string SignIn::getpassword()
{
	return password;
}

//Sign In default constructor
SignIn::SignIn(){

}

//Sign In parameterized constructor
SignIn::SignIn(const wxString& title):wxFrame(nullptr, wxID_ANY, title) {

	wxPanel* panel = new wxPanel(this);


	//username input textbox
	usernameinput = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(100, 170), wxSize(200, -1));
	usernameinput->SetHint("Username");
	setusername(usernameinput->GetValue().ToStdString());

	//password input textbox
	passwordinput = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(100, 220), wxSize(200, -1), wxTE_PASSWORD);
	passwordinput->SetHint("Password");
	setpassword(passwordinput->GetValue().ToStdString());

	//log in button
	loginbutton = new wxButton(panel, wxID_ANY, "Log In", wxPoint(160, 270), wxSize(80, 35));



	//binding login button to event
	loginbutton->Bind(wxEVT_BUTTON,&SignIn::OnLoginButtonClicked, this);

	CreateStatusBar();

}

//When Login Button is Clicked
void SignIn::OnLoginButtonClicked(wxCommandEvent& event) {

	username = usernameinput->GetValue();
	password = passwordinput->GetValue();

	if (username.empty() || password.empty())
	{
		wxLogMessage("Username or password must not be empty");

	}
	else if ((getusername() == "Triston") && (getpassword() == "123"))
	{
		wxLogStatus("Login Button Clicked");
		HomePage* homepage = new HomePage("HomePage");
		homepage->SetClientSize(800, 600);
		homepage->Center();
		homepage->Show();

		//Close login page, release memory
		Close(true);
	}

	else {
		wxLogMessage("Wrong Credentials");
	}

}
