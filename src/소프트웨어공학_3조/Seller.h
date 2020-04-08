#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Member.h"
#include "Ticket.h"
using namespace std;

// Class : Seller
// Description : Seller�� ���� ������ �����ϴ� Ŭ����
// Created : 2019/05/30 09:00pm
// Author : ������
//
// Revision :
//	1. When & Who : 2019/05/31 10:00pm, ������
//         What : ticket list ������ id���� Ticket*�� ����
//                    registerTicketList��, getSellerTicketList ���� Ÿ��, addSellerTicketList�� �Ű����� ����
//	2. When & Who : 2019/06/03 10:00pm, ������
//         What : ticket list ������ Ticket*���� id�� ����
//                    registerTicketList��, getSellerTicketList ���� Ÿ��, addSellerTicketList�� �Ű����� ����
//  3. When & Who : 2019/06/03 6:28pm, ������
//         What : Seller�Ҹ��� �߰�
// 4. When & Who: 2019/06/04 11:52 am by ������
//	What: 1) ����� Ƽ�� ��Ͽ��� Ƽ���� �����ϴ�
//			void deleteTicket(int) �Լ� �߰�
class Seller : public Member {
private:
	vector<int> registerTicketList;
public:
	Seller(int userType, string name, int identityNumber, bool loginState, string savedID, string savedPassword);
	vector<int> getSellersTicketList();
	void addSellerTicketList(int ticketID);
	~Seller();

	virtual void deleteTicket(int);
};