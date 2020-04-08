#include <iostream>
#include <fstream>
#include <string>
#include "SignUpUI.h"
#include "SignUp.h"
using namespace std;

// function : inputSignUpInformation(ifstream &in_fp, ofstream &out_fp)
// description : ȸ�������� ���� ������ �Է��ϴ� �Լ�
// parameter : ifstream &in_fp :��ǲ����
//						ofstream &out_fp : �ƿ�ǲ����
// return value : ����

void SignUpUI::inputSignUpInformation(ifstream &in_fp, ofstream &out_fp, SignUp &signUp) {
	string savedID, savedPassword, name, userTypeBuff;
	int identityNumber, userType;

	out_fp << "1.1. ȸ������" << endl;
	in_fp >> savedID >> savedPassword >> name >> identityNumber >> userTypeBuff;
	userType = (userTypeBuff == "buyer") ? 0 : 1;	 //0�̸� buyer, 1�̸� seller�� ��Ÿ��
	
	signUp.showSignUp(savedID, savedPassword, name, identityNumber, userType);

	out_fp << "> " << savedID << " " << savedPassword << " " << name << " " << identityNumber << " " << userTypeBuff << endl;
}