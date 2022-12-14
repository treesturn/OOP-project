#include "SignIn.h"
#include "AccountMgr.h"
#include "HomePage.h"
#include "Account.h"
#include <wx/wx.h>


//instantiate Sign In page AccountMgr 
AccountMgr SI_accmgr;

//Mutators
void SignIn::setusername(std::string new_username) {
	
	username = new_username;
}

void SignIn::setpin(std::string new_pin) {
	
	pin = new_pin;
}

//Getters
std::string SignIn::getusername()
{
	return username;
}

std::string SignIn::getpin()
{
	return pin;
}

//Sign In default constructor
SignIn::SignIn(){

}

//Sign In parameterized constructor
SignIn::SignIn(const wxString& title):wxFrame(nullptr, wxID_ANY, title) {


	wxPanel* panel = new wxPanel(this);
	
	//Bank Logo
	wxPNGHandler* handler = new wxPNGHandler;
	wxImage::AddHandler(handler);
	wxStaticBitmap* image;
	image = new wxStaticBitmap(panel, wxID_ANY, wxBitmap("Triston Bank App Smaller.png", wxBITMAP_TYPE_PNG), wxPoint(70, 15), wxSize(250, 250));


	//username input textbox
	usernameinput = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(100, 250), wxSize(200, -1));
	usernameinput->SetHint("Username");
	setusername(usernameinput->GetValue().ToStdString());

	//password input textbox
	pininput = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(100, 300), wxSize(200, -1), wxTE_PASSWORD);
	pininput->SetHint("Pin");
	setpin(pininput->GetValue().ToStdString());

	//log in button
	loginbutton = new wxButton(panel, wxID_ANY, "Log In", wxPoint(160, 350), wxSize(80, 35));


	//binding login button to event
	loginbutton->Bind(wxEVT_BUTTON,&SignIn::OnLoginButtonClicked, this);

	CreateStatusBar();

}

//When Login Button is Clicked, create HomePage
void SignIn::OnLoginButtonClicked(wxCommandEvent& event) {

	bool loggedin = false;
	username = usernameinput->GetValue();
	pin = pininput->GetValue();

	if (username.empty() || pin.empty())
	{
		wxLogMessage("Username or password must not be empty");

	}
	else {
		for (Account* acc : SI_accmgr.getAcc_DB())
		{
			if (username == acc->get_Account_username() && pin == acc->get_Account_pin())
			{


				wxLogStatus("Login Button Clicked");
				HomePage* homepage = new HomePage("HomePage", acc->get_Account_username(), acc->get_Account_num());
				homepage->SetClientSize(600, 600);
				homepage->Center();
				homepage->Show();


				//Close login page, release memory
				Close(true);
				loggedin = true;
				break;
			}
		}
		if (!(loggedin)) {
			wxLogMessage("Wrong Credentials");
		}
	}
}

//destructor
SignIn::~SignIn()
{

}
