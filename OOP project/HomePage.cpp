#include "HomePage.h"
#include "Account.h"
#include <wx/wx.h>
#include <string.h>
using namespace std;


HomePage::HomePage(const wxString& title) :wxFrame(nullptr, wxID_ANY, title) {

	//instantiate an Account 
	Account a = Account("Triston Chan", 2101793, 2500.50);

	wxPanel* panel = new wxPanel(this);

	wxStaticText* text = new wxStaticText(panel, wxID_ANY, "HOMEPAGE");

	//display 
	wxStaticText* Welcome_Message = new wxStaticText(panel, wxID_ANY, "Welcome " + a.get_Account_username() + "\n", wxPoint(10, 50));

	//display username on Homepage
	wxStaticText* Acc_username = new wxStaticText(panel, wxID_ANY, a.get_Account_username(), wxPoint(10, 100));

	//display account id on Homepage
	wxStaticText* Acc_id = new wxStaticText(panel, wxID_ANY, to_string(a.get_Account_num()), wxPoint(10, 150));

	//display account balance on Homepage
	wxStaticText* Acc_bal = new wxStaticText(panel, wxID_ANY, to_string(a.get_Account_bal()), wxPoint(10, 200));


}
