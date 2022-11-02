#include "HomePage.h"
#include "Account.h"
#include <wx/wx.h>
#include <string.h>
using namespace std;

//Home Page default constructor
HomePage::HomePage() {

}

//Home Page parameterized constructor
HomePage::HomePage(const wxString& title) :wxFrame(nullptr, wxID_ANY, title) {

	//instantiate an Account 
	Account a = Account("Triston Chan", 2101793, 2500.50);

	headerpanel = new wxPanel(this);
	headerpanel->SetBackgroundColour(wxColor(40, 41, 52));
	headerpanel->SetSize(600, 50);

	btmpanel = new wxPanel(this);
	btmpanel->SetBackgroundColour(wxColor(240, 240, 245));

	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
	sizer->Add(headerpanel, 0, wxEXPAND | wxLEFT | wxTOP | wxRIGHT, 0);
	sizer->Add(btmpanel, 1, wxEXPAND | wxALL, 0);
	

	this->SetSizerAndFit(sizer);

	//display 
	Welcome_Message = new wxStaticText(headerpanel, wxID_ANY, "Welcome " + a.get_Account_username() + "\n", wxPoint(10, 60));
	wxFont font = Welcome_Message->GetFont();
	font.SetPointSize(13);
	font.SetWeight(wxFONTWEIGHT_BOLD);
	Welcome_Message->SetFont(font);

	//display username on Homepage
	Acc_username = new wxStaticText(btmpanel, wxID_ANY, a.get_Account_username(), wxPoint(10, 100));

	//display account id on Homepage
	Acc_id = new wxStaticText(btmpanel, wxID_ANY, to_string(a.get_Account_num()), wxPoint(10, 150));

	//display account balance on Homepage
	Acc_bal = new wxStaticText(btmpanel, wxID_ANY, to_string(a.get_Account_bal()), wxPoint(10, 200));

	CreateStatusBar();


}
