#include "LogInUI.h"


//function : void inputLogInInformation(ifstream &in_fp, ofstream &out_fp, LogIn &logIn);
//description : �α��� UI
//parameter : ifstream &in_fp-�����Է�, ofstream &out_fp-�������, LogIn &logIn-��Ʈ�� 

void LogInUI::inputLogInInformation(ifstream &in_fp, ofstream &out_fp, LogIn &logIn){

	string inputID, inputPassword;
	bool logInMember;
	out_fp << "2.1. �α���" << endl;
	in_fp >> inputID >> inputPassword;
	logInMember = logIn.showLogIn(inputID, inputPassword);
	
	if (logInMember == true){

		out_fp << "> " << inputID << " " << inputPassword << endl;
	}
	else{ 
		out_fp << "> �α��� ����" << endl;
	}

	
}