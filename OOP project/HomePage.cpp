#include "HomePage.h"
#include "Account.h"
#include "AccountMgr.h"
#include "Savings_Account.h"
#include "Current_Account.h"
#include <wx/wx.h>
#include <string.h>
using namespace std;

//Home Page default constructor
HomePage::HomePage() {

}

//Home Page parameterized constructor
HomePage::HomePage(const wxString& title) :wxFrame(nullptr, wxID_ANY, title) {

	//instantiate the Accounts
	Savings_Account a = Savings_Account("Triston Chan", 2101793, "123", 2500.50, 0.04);
	Current_Account b = Current_Account("Triston Chan", 2101793, "123", 2500.50);

	//instantiate Home Page page AccountMgr 
	AccountMgr HP_accmgr;

	//Header top panel
	headerpanel = new wxPanel(this);
	headerpanel->SetBackgroundColour(wxColor(57, 58, 77));
	headerpanel->SetSize(600, 50);

	//Main panel below header panel
	btmpanel = new wxPanel(this);
	btmpanel->SetBackgroundColour(wxColor(43, 44, 59));

	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
	sizer->Add(headerpanel, 0, wxEXPAND | wxLEFT | wxTOP | wxRIGHT, 0);
	sizer->Add(btmpanel, 1, wxEXPAND | wxALL, 0);
	

	this->SetSizerAndFit(sizer);

	//savings account box
	savingsacc_panel = new wxPanel(btmpanel);
	savingsacc_panel->SetBackgroundColour(wxColor(220, 220, 226));
	savingsacc_panel->SetSize(200, 300);
	savingsacc_panel->SetPosition(wxPoint(50, 70));

	savingsacc_headerpanel = new wxPanel(btmpanel);
	savingsacc_headerpanel->SetBackgroundColour(wxColor(57, 58, 77));
	savingsacc_headerpanel->SetSize(200, 60);
	savingsacc_headerpanel->SetPosition(wxPoint(50, 70));

	savingsacc_colorpanel = new wxPanel(btmpanel);
	savingsacc_colorpanel->SetBackgroundColour(wxColor(203, 76, 100));
	savingsacc_colorpanel->SetSize(200, 5);
	savingsacc_colorpanel->SetPosition(wxPoint(50, 70));

	//current account box
	currentacc_panel = new wxPanel(btmpanel);
	currentacc_panel->SetBackgroundColour(wxColor(220, 220, 226));
	currentacc_panel->SetSize(200, 300);
	currentacc_panel->SetPosition(wxPoint(340, 70));

	currentacc_headerpanel = new wxPanel(btmpanel);
	currentacc_headerpanel->SetBackgroundColour(wxColor(57, 58, 77));
	currentacc_headerpanel->SetSize(200, 60);
	currentacc_headerpanel->SetPosition(wxPoint(340, 70));

	currentacc_colorpanel = new wxPanel(btmpanel);
	currentacc_colorpanel->SetBackgroundColour(wxColor(84, 141, 208));
	currentacc_colorpanel->SetSize(200, 5);
	currentacc_colorpanel->SetPosition(wxPoint(340, 70));

	//transfer funds box
	transferfunds_panel = new wxPanel(btmpanel);
	transferfunds_panel->SetBackgroundColour(wxColor(220, 220, 226));
	transferfunds_panel->SetSize(490, 80);
	transferfunds_panel->SetPosition(wxPoint(50, 400));



	//display Welcome message
	Welcome_Message = new wxStaticText(headerpanel, wxID_ANY, "Welcome " + a.get_Account_username() + "\n", wxPoint(10, 50));
	wxFont font = Welcome_Message->GetFont();
	font.SetPointSize(13);
	font.SetWeight(wxFONTWEIGHT_BOLD);
	Welcome_Message->SetFont(font);
	Welcome_Message->SetForegroundColour(*wxWHITE);

	//display savingsacc title header on Homepage savingsacc box
	Savingsacc_header = new wxStaticText(savingsacc_headerpanel, wxID_ANY, a.title_header(), wxPoint(19, 30));
	wxFont font2 = Savingsacc_header->GetFont();
	font2.SetPointSize(11);
	font2.SetWeight(wxFONTWEIGHT_BOLD);
	Savingsacc_header->SetFont(font2);
	Savingsacc_header->SetForegroundColour(*wxWHITE);

	//display username on Homepage savingsacc box
	Acc_username = new wxStaticText(savingsacc_panel, wxID_ANY, a.get_Account_username(), wxPoint(10, 100));

	//display account id on Homepage savingsacc box
	Acc_id = new wxStaticText(savingsacc_panel, wxID_ANY, to_string(a.get_Account_num()), wxPoint(10, 150));

	//display account balance on Homepage savingsacc box
	Acc_bal = new wxStaticText(savingsacc_panel, wxID_ANY, to_string(a.get_Account_bal()), wxPoint(10, 200));



	//display currentsacc title header on Homepage currentsacc box
	Currentacc_header = new wxStaticText(currentacc_headerpanel, wxID_ANY, b.title_header(), wxPoint(20, 30));
	wxFont font3 = Currentacc_header->GetFont();
	font3.SetPointSize(11);
	font3.SetWeight(wxFONTWEIGHT_BOLD);
	Currentacc_header->SetFont(font3);
	Currentacc_header->SetForegroundColour(*wxWHITE);

	//funds amount input box in transferfunds panel
	fundsamt_header = new wxStaticText(transferfunds_panel, wxID_ANY, "I want to transfer... ", wxPoint(10, 15));
	wxFont font4 = fundsamt_header->GetFont();
	font4.SetPointSize(8);
	fundsamt_header->SetFont(font4);

	//funds amount input textbox
	funds_amt = new wxTextCtrl(transferfunds_panel, wxID_ANY, "", wxPoint(10, 35), wxSize(120, -1));
	funds_amt->SetHint("Enter amount");


	//from, account type in transferfunds panel
	from_acctype = new wxStaticText(transferfunds_panel, wxID_ANY, "From this account... ", wxPoint(180, 15));
	wxFont font5 = from_acctype->GetFont();
	font5.SetPointSize(8);
	from_acctype->SetFont(font5);

	//select account type
	wxArrayString choices;
	choices.Add("Savings");
	choices.Add("Current");
	acctype = new wxChoice(transferfunds_panel, wxID_ANY, wxPoint(180, 35), wxSize(125, -1), choices);

	//To, account type in transferfunds panel
	To_acctype = new wxStaticText(transferfunds_panel, wxID_ANY, "To this account... ", wxPoint(355, 15));
	wxFont font6 = To_acctype->GetFont();
	font6.SetPointSize(8);
	To_acctype->SetFont(font6);

	//select account type
	acctype2 = new wxChoice(transferfunds_panel, wxID_ANY, wxPoint(355, 35), wxSize(125, -1), choices);
	



	CreateStatusBar();


}
