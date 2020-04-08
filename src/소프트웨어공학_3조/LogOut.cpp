#include "LogOut.h"



//function : void showLogOut()
//description : �α׾ƿ� �Լ�����

void LogOut::showLogOut(){
	MemberManager *memberManager = MemberManager::getInstance();
	memberManager->requestLogOut();
	
}