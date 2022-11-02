#include "App.h"
#include "SignIn.h"
#include "Account.h"
#include <wx/wx.h>

//macro to start app
wxIMPLEMENT_APP(App);

bool App::OnInit() {


	//start the sign in page frame
	SignIn* signin = new SignIn("Sign In Page");
	signin->SetClientSize(400, 500);
	signin->Center();
	signin->Show();
	return true;
}