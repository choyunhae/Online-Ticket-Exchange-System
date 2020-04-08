#include "Member.h"

//function : Member(int userType, string name, int identityNumber, bool logInState, string savedID, string savedPassword)
//description : Member ��ü�� �����ϴ� ������
/*parameter :
int userType(0/buyer,1/seller)
string name : ����� �̸�
int identityNumber : ����� �ֹι�ȣ
bool logInState : �α��λ��� Ȯ��(0/false,1/true)
string savedID : ����� ID, ��ȿ�� �˻�� ���
string savedPassword : ����� password,��ȿ�� �˻�� ���
*/
Member::Member(int userType, string name, int identityNumber, bool logInState, string savedID, string savedPassword){

	this->userType = userType;
	this->name = name;
	this->identityNumber = identityNumber;
	this->logInState = logInState;
	this->savedID = savedID;
	this->savedPassword = savedPassword;
}

//function : string getPassword()
//description : savedPassword�������� �Լ�

string Member::getPassword(){
	return savedPassword;
}

//function : string getID()
//description : savedID�������� �Լ�

string Member::getID(){
	return savedID;
}

//function : bool getLogInState()
//description : logInState�������� �Լ�(LogIn/out���� ���)
//default��=false

bool Member::getLogInState(){
	return logInState;
}

//function : int getUserType()
//description : userType������(ȸ��Ż��� ���)

int Member::getUserType(){
	return userType;
}

//function : void setLogInState(bool logInState)
//description : �α��λ��� �ٲ� �� ���
void Member::setLogInState(bool logInState){
	this->logInState = logInState;
}

