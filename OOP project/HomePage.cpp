#include "HomePage.h"
#include "Account.h"
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

	//Header top panel
	headerpanel = new wxPanel(this);
	headerpanel->SetBackgroundColour(wxColor(40, 41, 52));
	headerpanel->SetSize(600, 50);

	//Main panel below header panel
	btmpanel = new wxPanel(this);
	btmpanel->SetBackgroundColour(wxColor(84, 82, 94));

	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
	sizer->Add(headerpanel, 0, wxEXPAND | wxLEFT | wxTOP | wxRIGHT, 0);
	sizer->Add(btmpanel, 1, wxEXPAND | wxALL, 0);
	

	this->SetSizerAndFit(sizer);

	//savings account box
	savingsacc_panel = new wxPanel(btmpanel);
	savingsacc_panel->SetBackgroundColour(wxColor(240, 240, 246));
	savingsacc_panel->SetSize(200, 300);
	savingsacc_panel->SetPosition(wxPoint(50, 70));

	savingsacc_headerpanel = new wxPanel(btmpanel);
	savingsacc_headerpanel->SetBackgroundColour(wxColor(40, 41, 52));
	savingsacc_headerpanel->SetSize(200, 60);
	savingsacc_headerpanel->SetPosition(wxPoint(50, 70));

	savingsacc_colorpanel = new wxPanel(btmpanel);
	savingsacc_colorpanel->SetBackgroundColour(wxColor(203, 76, 100));
	savingsacc_colorpanel->SetSize(200, 5);
	savingsacc_colorpanel->SetPosition(wxPoint(50, 70));

	//current account box
	currentacc_panel = new wxPanel(btmpanel);
	currentacc_panel->SetBackgroundColour(wxColor(240, 240, 246));
	currentacc_panel->SetSize(200, 300);
	currentacc_panel->SetPosition(wxPoint(340, 70));

	currentacc_headerpanel = new wxPanel(btmpanel);
	currentacc_headerpanel->SetBackgroundColour(wxColor(40, 41, 52));
	currentacc_headerpanel->SetSize(200, 60);
	currentacc_headerpanel->SetPosition(wxPoint(340, 70));

	currentacc_colorpanel = new wxPanel(btmpanel);
	currentacc_colorpanel->SetBackgroundColour(wxColor(84, 141, 208));
	currentacc_colorpanel->SetSize(200, 5);
	currentacc_colorpanel->SetPosition(wxPoint(340, 70));

	//display Welcome message
	Welcome_Message = new wxStaticText(headerpanel, wxID_ANY, "Welcome " + a.get_Account_username(), wxPoint(10, 50));
	wxFont font = Welcome_Message->GetFont();
	font.SetPointSize(13);
	font.SetWeight(wxFONTWEIGHT_BOLD);
	Welcome_Message->SetFont(font);

	//display savingsacc title header on Homepage savingsacc box
	Savingsacc_header = new wxStaticText(savingsacc_headerpanel, wxID_ANY, a.title_header(), wxPoint(19, 30));
	wxFont font2 = Savingsacc_header->GetFont();
	font2.SetPointSize(11);
	font2.SetWeight(wxFONTWEIGHT_BOLD);
	Savingsacc_header->SetFont(font2);

	//display username on Homepage savingsacc box
	Acc_username = new wxStaticText(savingsacc_panel, wxID_ANY, a.get_Account_username(), wxPoint(10, 100));

	//display account id on Homepage savingsacc box
	Acc_id = new wxStaticText(savingsacc_panel, wxID_ANY, to_string(a.get_Account_num()), wxPoint(10, 150));

	//display account balance on Homepage savingsacc box
	Acc_bal = new wxStaticText(savingsacc_panel, wxID_ANY, to_string(a.get_Account_bal()), wxPoint(10, 200));



	//display currentsacc title header on Homepage currentsacc box
	Currentsacc_header = new wxStaticText(currentacc_headerpanel, wxID_ANY, b.title_header(), wxPoint(20, 30));
	wxFont font3 = Currentsacc_header->GetFont();
	font3.SetPointSize(11);
	font3.SetWeight(wxFONTWEIGHT_BOLD);
	Currentsacc_header->SetFont(font3);



	CreateStatusBar();


}
