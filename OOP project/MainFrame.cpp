#include "MainFrame.h"
#include "HomePage.h"
#include <wx/wx.h>


void MainFrame::setusername(std::string new_username) {
	
	username = new_username;
}

std::string MainFrame::getusername()
{
	return username;
}

MainFrame::MainFrame(const wxString& title):wxFrame(nullptr, wxID_ANY, title) {

	wxPanel* panel = new wxPanel(this);

	//log in button
	loginbutton = new wxButton(panel, wxID_ANY, "Log In", wxPoint(10, 50), wxSize(100, 35));

	//username input textbox
	usernameinput = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(10, 100), wxSize(200, -1));
	setusername(usernameinput->GetValue().ToStdString());

	//password input textbox
	passwordinput = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(10, 150), wxSize(200, -1));
	password = passwordinput->GetValue().ToStdString();


	//binding login button to event
	loginbutton->Bind(wxEVT_BUTTON,&MainFrame::OnLoginButtonClicked, this);

	CreateStatusBar();

}

//When Login Button is Clicked
void MainFrame::OnLoginButtonClicked(wxCommandEvent& event) {

	username = usernameinput->GetValue();
	password = passwordinput->GetValue();

	if (username.empty() || password.empty())
	{
		wxLogMessage("Username or password must not be empty");

	}
	else if ((getusername() == "Triston"))
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
