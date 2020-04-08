#include <iostream>
#pragma once
#include <string>
#include <map>
#include <vector>
#include "Member.h"
#include "Buyer.h"
#include "Seller.h"

using namespace std;

//Class : MemberManager
//description : MemberManager�� ���� ���� ����
//Revisions:
// 1.When & Who 2019/6/2 19:34 pm by ������
// What : ���������� ����, iter����, 
//		getLogInMember ����Ÿ�Լ���,getMember����, requestLogOut����
//		getMember����
// 2. When & Who: 2019/06/03 05:23 am by ������
// ****** ȸ������, ȸ��Ż�� ���� �Լ��� �߰�/������ ������ �� �˷��ּ��� ******
// ****** ���� �ϴ� �Ʒ� ���븸 �����߽��ϴ� *****
// ****** ȸ������ ���� ����� ���� �ȵ��־ �׽�Ʈ�� ���غý��ϴ� *****
//	What: 1) string currentSession �߰�
//			 void changeSession(string memberID) �߰�
//			 string getCurrentSession() �߰�
//		  2) requestLogOut()�Լ� ��κ� ����
//			 requestLogIn()�Լ� ��κ� ����
//			 logInMembers�� Ÿ���� map<string, Member*>���� vector<string> ���� ����
//		  3) map<string, Member*> getLogInMember() ����
// 3. When & Who: 2019/06/03 08:03 am by ������
//	What: 1) ���Ƽ�� ������ ��� �����ڿ� ���� ������ ����� �ٸ�.
//			���� buyerID�� Ƽ�� ������ �޾� Ƽ���� �����ϴ� ������ �ϴ� �Լ��� ����
//			void reserveTicket(int, string) �Լ���
// 4. When & Who : 2019/06/03 2:29pm, ������
//	What: requestSignUp����
// 5. When & Who: 2019/06/03 09:13 pm by ������
//	What: 1) Login�� ������ �α����� ����� ����
//		  2) Logout�� ������ �� ���ڿ��� ����
// 6. When & Who : 2019/06/03 10:04 pm by ������
//	What :	���� ������ ����� ������ �� �ִ� ������ ��ȯ �Լ� �ۼ�
// 7. When & Who : 2019/06/04 11:03 am by ������
//	What: 1) ��� ���̵�� Ƽ�� ���̵� �޾� �ش� ����� Ƽ�ϸ���Ʈ���� Ƽ���� �����ϴ� �Լ� �߰�
//			void deleteMembersTicket(int ticketID, string memberID);
// 8. When & Who : 2019/06/05 08:04 pm by ������
//  What : �Է� ���� ID�� �ش��ϴ� ��� ���� �Լ� �߰�


class MemberManager{
private:
	string currentSessionID;
	map< string, Member* > members;//string�� savedID
	vector<string> logInMembers;
	MemberManager();
	static MemberManager * memberManagerInstance;
	

public:
	static MemberManager *getInstance();
	bool requestLogIn(string, string);
	void requestLogOut();
	void requestSignUp(string savedID, string savedPassword, string name, int identityNumber, int userType);
	void changeSession(string);
	string getCurrentSessionID();
	void eraseMember(string ID);

	void reserveTicket(int, string);
	void deleteMembersTicket(int, string);

	Member * getCurrentMemberPtr();
};