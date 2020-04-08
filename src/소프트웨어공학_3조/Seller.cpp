#include <iostream>
#include "Seller.h"
using namespace std;

// Class : Seller
// Description : Seller�� ���� ������ �����ϴ� Ŭ����
// Created : 2019/05/30 09:00pm
// Author : ������
//
// Revision :
//	     1. When & Who : 2019/05/31 10:00pm, ������
//         What : ticket list ������ id���� Ticket*�� ����
//                    registerTicketList��, getSellerTicketList ���� Ÿ��, addSellerTicketList�� �Ű����� ����
//	     2. When & Who : 2019/06/03 01:00am, ������
//         What : ticket list ������ Ticket*���� id�� ����
//                    registerTicketList��, getSellerTicketList ���� Ÿ��, addSellerTicketList�� �Ű����� ����

// function : Seller(int userType, string name, int identityNumber, bool loginState, string savedID, string savedPassword)
// description : Seller ��ü�� �����ϴ� ������
// parameter : int userType - 0�̸� buyer, 1�̸� seller�� ��Ÿ��
//             string name - Buyer ��ü�� �̸�
//             identityNumber - �� member���� �ο��� ���� ��ȣ
//             loginState - true�� login�� ����, false�� logout�� ����
//             savedID - Seller�� ID
//             savedPassword - Seller�� password
// return value : ����

Seller::Seller(int userType, string name, int identityNumber, bool loginState, string savedID, string savedPassword)
	: Member(userType, name, identityNumber, loginState, savedID, savedPassword){
	//������
}
//funtion : ~Seller()
//description : Seller��ü �Ҹ���

Seller::~Seller(){}
// function : vector<int> getSellersTicketList();
// description : Seller�� ����� Ƽ�ϸ���Ʈ�� �����Ѵ�
// parameter : ����
// return value : ��� Ƽ�� ����Ʈ
vector<int> Seller::getSellersTicketList() {
	return this->registerTicketList;
}

// function : void addSellerTicketList(int ticketID)
// description : Seller�� ����� Ƽ���� Seller�� ��� Ƽ�� ����Ʈ�� �߰��Ѵ�
// parameter : int ticketID - ���� ����� ticket�� ID
// return value : ����
void Seller::addSellerTicketList(int ticketID) {
	this->registerTicketList.push_back(ticketID);
}

// function : void deleteTicket(int)
// description : Ƽ��id�� �޾Ƽ� ��� Ƽ�� ��Ͽ��� ����
// parameter : int ticketID
// return value :None
void Seller::deleteTicket(int ticketID) {
	auto fst = registerTicketList.begin();
	for (int i = 0; i < registerTicketList.size(); i++) {
		if (ticketID == registerTicketList[i]) {
			registerTicketList.erase(fst + i);
			return;
		}
	}
}