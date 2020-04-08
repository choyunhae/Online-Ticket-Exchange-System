#include "LogIn.h"

//function : bool showLogIn(string inputID, string inputPassword)
//description : �α����� ���� �Լ�
//parameter : string inputID-�Է¹��� ���̵�, string inputPassword-�Է¹��� �н�����

bool LogIn::showLogIn(string inputID, string inputPassword){
	bool logInMember=false;
	MemberManager *memberManager = MemberManager::getInstance();
	logInMember = memberManager->requestLogIn(inputID, inputPassword);
	return logInMember;
}