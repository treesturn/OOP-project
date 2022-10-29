#include "App.h"
#include "MainFrame.h"
#include "Account.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(App);

bool App::OnInit() {


	//start the sign in page frame
	MainFrame* mainFrame = new MainFrame("Sign In Page");
	mainFrame->SetClientSize(400, 200);
	mainFrame->Center();
	mainFrame->Show();
	return true;
}