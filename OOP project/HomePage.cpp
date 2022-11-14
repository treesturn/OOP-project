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

//mutators
void HomePage::set_sav_bal(float amt)
{
	sav_bal = amt;

}

void HomePage::set_curr_bal(float amt) 
{
	curr_bal = amt;
}

//getter
float HomePage::get_sav_bal()
{
	return sav_bal;
}

float HomePage::get_curr_bal()
{
	return curr_bal;
}


//Home Page parameterized constructor
HomePage::HomePage(const wxString& title, std::string username, int chosen_accnum) :wxFrame(nullptr, wxID_ANY, title) {


	Acc_username_text = username;
	//User savings and current account can be excessed togther in one session
	chosen_Sav_accnum = chosen_accnum; 
	chosen_Curr_accnum = chosen_accnum+1;

	//instantiate the Accounts
	//Savings_Account a = Savings_Account("Triston Chan", 2101793, "123", 2500.50, 0.04);
	//Current_Account b = Current_Account("Triston Chan", 2101793, "123", 2500.50);

	//instantiate an Account Manager
	AccountMgr HP_accmgr(chosen_accnum);

	curr_bal = (HP_accmgr.getchosen_CurrAcc())->get_Account_bal();
	sav_bal = (HP_accmgr.getchosen_SavAcc())->get_Account_bal();



	//instantiate Home Page page AccountMgr 
	//AccountMgr HP_accmgr;

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
	savingsacc_panel->SetSize(200, 250);
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
	currentacc_panel->SetSize(200, 250);
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
	transferfunds_panel->SetPosition(wxPoint(50, 350));



	//display Welcome message
	Welcome_Message = new wxStaticText(headerpanel, wxID_ANY, "Welcome " + Acc_username_text + "\n", wxPoint(10, 50));
	wxFont font = Welcome_Message->GetFont();
	font.SetPointSize(13);
	font.SetWeight(wxFONTWEIGHT_BOLD);
	Welcome_Message->SetFont(font);
	Welcome_Message->SetForegroundColour(*wxWHITE);

	//display savingsacc title header on Homepage savingsacc box (Polymorphism, ACCOUNT type element using child class; SAVINGS_ACCOUNT type functions)
	Savingsacc_header = new wxStaticText(savingsacc_headerpanel, wxID_ANY, HP_accmgr.getchosen_SavAcc()->title_header(), wxPoint(19, 30));
	wxFont font2 = Savingsacc_header->GetFont();
	font2.SetPointSize(11);
	font2.SetWeight(wxFONTWEIGHT_BOLD);
	Savingsacc_header->SetFont(font2);
	Savingsacc_header->SetForegroundColour(*wxWHITE);

	//display username on Homepage savingsacc box (Polymorphism, ACCOUNT type element using child class; SAVINGS_ACCOUNT type functions)
	Acc_username = new wxStaticText(savingsacc_panel, wxID_ANY, (HP_accmgr.getchosen_SavAcc())->get_Account_username(), wxPoint(10, 100));
	wxFont name_font = Acc_username->GetFont();
	name_font.SetPointSize(11);
	name_font.SetWeight(wxFONTWEIGHT_BOLD);
	Acc_username->SetFont(name_font);

	//display account id on Homepage savingsacc box
	Acc_id = new wxStaticText(savingsacc_panel, wxID_ANY, to_string((HP_accmgr.getchosen_SavAcc())->get_Account_num()), wxPoint(10, 150));
	wxFont id_font = Acc_id->GetFont();
	id_font.SetPointSize(11);
	id_font.SetWeight(wxFONTWEIGHT_BOLD);
	Acc_id->SetFont(id_font); 

	//display account balance on Homepage savingsacc box
	Acc_bal = new wxStaticText(savingsacc_panel, wxID_ANY, '$' + to_string(get_sav_bal()), wxPoint(10, 200));
	wxFont bal_font = Acc_bal->GetFont();
	bal_font.SetPointSize(11);
	bal_font.SetWeight(wxFONTWEIGHT_BOLD);
	Acc_bal->SetFont(bal_font);


	//display username on Homepage currentsacc box (Polymorphism, ACCOUNT type element using child class; CURRENT_ACCOUNT type functions)
	Acc_username2 = new wxStaticText(currentacc_panel, wxID_ANY, (HP_accmgr.getchosen_CurrAcc())->get_Account_username(), wxPoint(10, 100));
	wxFont name_font2 = Acc_username2->GetFont();
	name_font2.SetPointSize(11);
	name_font2.SetWeight(wxFONTWEIGHT_BOLD);
	Acc_username2->SetFont(name_font2);

	////display account id on Homepage savingsacc box
	Acc_id2 = new wxStaticText(currentacc_panel, wxID_ANY, to_string((HP_accmgr.getchosen_CurrAcc())->get_Account_num()), wxPoint(10, 150));
	wxFont id_font2 = Acc_id2->GetFont();
	id_font2.SetPointSize(11);
	id_font2.SetWeight(wxFONTWEIGHT_BOLD);
	Acc_id2->SetFont(id_font2);

	////display account balance on Homepage savingsacc box
	Acc_bal2 = new wxStaticText(currentacc_panel, wxID_ANY, '$' + to_string(get_curr_bal()), wxPoint(10, 200));
	wxFont bal_font2 = Acc_bal2->GetFont();
	bal_font2.SetPointSize(11);
	bal_font2.SetWeight(wxFONTWEIGHT_BOLD);
	Acc_bal2->SetFont(bal_font2);


	//display currentsacc title header on Homepage currentsacc box (Polymorphism, ACCOUNT type element using child class; CURRENT_ACCOUNT type functions)
	Currentacc_header = new wxStaticText(currentacc_headerpanel, wxID_ANY, HP_accmgr.getchosen_CurrAcc()->title_header(), wxPoint(20, 30));
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
	funds_amt = new wxTextCtrl(transferfunds_panel, wxID_ANY, "", wxPoint(10, 35), wxSize(90, -1));
	funds_amt->SetHint("Enter amount");


	//from, account type in transferfunds panel
	from_acctype = new wxStaticText(transferfunds_panel, wxID_ANY, "From this account... ", wxPoint(140, 15));
	wxFont font5 = from_acctype->GetFont();
	font5.SetPointSize(8);
	from_acctype->SetFont(font5);

	//select account type
	wxArrayString choices;
	choices.Add("Savings");
	choices.Add("Current");
	acctype = new wxChoice(transferfunds_panel, wxID_ANY, wxPoint(140, 35), wxSize(90, -1), choices);

	//To, account type in transferfunds panel
	To_acctype = new wxStaticText(transferfunds_panel, wxID_ANY, "To this account... ", wxPoint(275, 15));
	wxFont font6 = To_acctype->GetFont();
	font6.SetPointSize(8);
	To_acctype->SetFont(font6);

	//select account type
	acctype2 = new wxChoice(transferfunds_panel, wxID_ANY, wxPoint(275, 35), wxSize(90, -1), choices);
	
	//transfer button
	transferbutton = new wxButton(transferfunds_panel, wxID_ANY, "Transfer", wxPoint(395, 25), wxSize(80, 35));
	
	//binding login button to event
	transferbutton->Bind(wxEVT_BUTTON, &HomePage::OntransferButtonClicked, this);

	//When transfer Button is Clicked, use HP_ACCMGR to transfer money between savings and current
	//void OntransferButtonClicked(wxCommandEvent& event);
	

	CreateStatusBar();


}

//destructor
HomePage::~HomePage()
{

}

void HomePage::OntransferButtonClicked(wxCommandEvent& event)
{
	wxLogStatus("transfer Button Clicked");

	AccountMgr mgr(chosen_Sav_accnum);

	if ((acctype->GetString(acctype->GetCurrentSelection()) == "Savings") && (acctype2->GetString(acctype2->GetCurrentSelection()) == "Current"))
	{

		float amount = std::stof(funds_amt->GetValue().ToStdString());
		mgr.savings_to_current(amount);

		set_curr_bal((mgr.getchosen_CurrAcc())->get_Account_bal());
		set_sav_bal((mgr.getchosen_SavAcc())->get_Account_bal());

		Acc_bal->SetLabel("$" + to_string(get_sav_bal()));
		Acc_bal2->SetLabel("$" + to_string(get_curr_bal()));

	}
	else if ((acctype->GetString(acctype->GetCurrentSelection()) == "Current") && (acctype2->GetString(acctype2->GetCurrentSelection()) == "Savings"))
	{

		float amount = std::stof(funds_amt->GetValue().ToStdString());
		mgr.current_to_savings(amount);

		set_curr_bal((mgr.getchosen_CurrAcc())->get_Account_bal());
		set_sav_bal((mgr.getchosen_SavAcc())->get_Account_bal());

		Acc_bal->SetLabel("$" + to_string(get_sav_bal()));
		Acc_bal2->SetLabel("$" + to_string(get_curr_bal()));
	}


}
