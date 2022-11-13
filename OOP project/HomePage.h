#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#pragma once
#include <wx/wx.h>

class HomePage: public wxFrame{
	
public:

	//default constructor
	HomePage();

	//parameterized construnctor
	HomePage(const wxString& title, std::string username, int chosen_accnum);

	//destructor
	~HomePage();

private:

	wxPanel* headerpanel;
	wxPanel* btmpanel;
	
	wxStaticText* text;

	//display 
	wxStaticText* Welcome_Message; 
	std::string Acc_username_text;
	int chosen_Sav_accnum;
	int chosen_Curr_accnum;



	//display savings header on Homepage
	wxStaticText* Savingsacc_header;
	wxPanel* savingsacc_colorpanel;
	wxPanel* savingsacc_headerpanel;
	wxPanel* savingsacc_panel;
	//display username on Homepage
	wxStaticText* Acc_username;
	//display account id on Homepage
	wxStaticText* Acc_id;
	//display account balance on Homepage
	wxStaticText* Acc_bal;

	//display current header on Homepage
	wxStaticText* Currentacc_header;
	wxPanel* currentacc_colorpanel;
	wxPanel* currentacc_headerpanel;
	wxPanel* currentacc_panel;
	wxStaticText* Acc_username2;
	//display account id on Homepage
	wxStaticText* Acc_id2;
	//display account balance on Homepage
	wxStaticText* Acc_bal2;

	// funds amount input box in transferfunds box
	wxPanel* transferfunds_panel;
	wxTextCtrl* funds_amt;
	wxStaticText* fundsamt_header;
	wxChoice* acctype;
	wxStaticText* from_acctype;
	wxChoice* acctype2;
	wxStaticText* To_acctype;
	wxButton* transferbutton;

	//when transfer button clicked
	void OntransferButtonClicked(wxCommandEvent& event);
};


#endif // HOMEPAGE_H