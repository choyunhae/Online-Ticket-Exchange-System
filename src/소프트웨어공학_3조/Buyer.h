#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Member.h"
#include "Ticket.h"
using namespace std;

// Class : Buyer
// Description : Buyer�� ���� ������ �����ϴ� Ŭ����
// Created : 2019/05/30 09:00pm
// Author : ������
//
// Revision :
//	     1. When & Who : 2019/05/31 10:00pm, ������
//         What : ticket list ������ id���� Ticket*�� ����
//                    reserveTicketList��, getReserveTicketList ���� Ÿ��, addBuyersTicketList�� �Ű����� ����
//	     1. When & Who : 2019/06/03 01:00am, ������
//         What : ticket list ������ Ticket*���� id�� ����
//                    reserveTicketList��, getReserveTicketList ���� Ÿ��, addBuyersTicketList�� �Ű����� ����
/*       1. When & Who : 2019/06/03 6:28pm, ������
What : Buyer�Ҹ��� �߰�*/
// 4. When & Who: 2019/06/04 11:52 am by ������
//	What: 1) ����� Ƽ�� ��Ͽ��� Ƽ���� �����ϴ�
//			void deleteTicket(int) �Լ� �߰�
class Buyer : public Member {
private:
	vector<int> reserveTicketList;	//������ Ƽ���� ���̵� �����ϴ� ����Ʈ
public:
	Buyer(int userType, string name, int identityNumber, bool loginState, string savedID, string savedPassword);
	~Buyer();
	vector<int> getReserveTicketList();
	void addBuyersTicketList(int ticketID);
	virtual void deleteTicket(int);
};