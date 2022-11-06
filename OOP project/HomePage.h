#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#pragma once
#include <wx/wx.h>

class HomePage: public wxFrame{
	
public:

	//default constructor
	HomePage();

	//parameterized construnctor
	HomePage(const wxString& title);

private:

	wxPanel* headerpanel;
	wxPanel* btmpanel;

	wxPanel* savingsacc_colorpanel;
	wxPanel* savingsacc_headerpanel;
	wxPanel* savingsacc_panel;

	wxPanel* currentacc_colorpanel;
	wxPanel* currentacc_headerpanel;
	wxPanel* currentacc_panel;

	wxStaticText* text;

	//display 
	wxStaticText* Welcome_Message; 

	//display savings header on Homepage
	wxStaticText* Savingsacc_header;

	//display current header on Homepage
	wxStaticText* Currentsacc_header;

	//display username on Homepage
	wxStaticText* Acc_username;

	//display account id on Homepage
	wxStaticText* Acc_id;

	//display account balance on Homepage
	wxStaticText* Acc_bal;


};

#endif // HOMEPAGE_H