#include <iostream>
#include <string>
#include "SignUp.h"
#include "MemberManager.h"
using namespace std;

// function : showSignUp(string savedID, string savedPassword, string name, int identityNumber, int userType)
// description : ȸ�������� ����  �Լ�
// parameter : string savedID, 
//						string savedPassword,
//						string name
//						int identityNumber
//						int userType
// return value : ����

void SignUp::showSignUp(string savedID, string savedPassword, string name, int identityNumber, int userType) {
	MemberManager* membermanager = MemberManager::getInstance();
	membermanager->requestSignUp(savedID, savedPassword, name, identityNumber, userType);
}