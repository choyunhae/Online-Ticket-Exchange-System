#include "LogOutUI.h"


//function : void clickLogOutButton(ifstream &in_fp, ofstream &out_fp, LogOut &logOut);
//description : �α׾ƿ� UI
//parameters : ifstream &in_fp, ofstream &out_fp, LogOut &logOut

void LogOutUI::clickLogOutButton(ifstream &in_fp, ofstream &out_fp, LogOut &logOut){
	
	string curID = MemberManager::getInstance()->getCurrentSessionID();
	logOut.showLogOut();//�α��� ���� �ٲ�
	out_fp << "2.2. �α׾ƿ�" << endl;
	out_fp << "> " << curID << endl;
}