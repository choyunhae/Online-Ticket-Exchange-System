#include <string>
#include <iostream>
#pragma once
using namespace std;

//Class:Member
//Description: Member�� ���� ������  �����ϴ� Ŭ����
// Revisions:
// 1. When & Who: 2019/06/04 11:52 am by ������
//	What: 1) ����� Ƽ�� ��Ͽ��� Ƽ���� �����ϴ�
//			void deleteTicket(int) �����Լ� �߰�
//			Seller, Buyer���� ���� �������̵���

class Member{
protected:
	int userType;
	string name;
	int identityNumber;
	bool logInState = false;
	string savedID;
	string savedPassword;
public:
	Member(int, string, int, bool, string, string);
	string getPassword();
	string getID();
	bool getLogInState();
	int getUserType();
	void setLogInState(bool logInState);
	virtual void deleteTicket(int) = 0;
};