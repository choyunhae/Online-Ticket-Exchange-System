#include <iostream>
#include "Buyer.h"
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


// function : Buyer(int userType, string name, int identityNumber, bool loginState, string savedID, string savedPassword)
// description : Buyer ��ü�� �����ϴ� ������
// parameter : int userType - 0�̸� buyer, 1�̸� seller�� ��Ÿ��
//             string name - Buyer ��ü�� �̸�
//             identityNumber - �� member���� �ο��� ���� ��ȣ
//             loginState - true�� login�� ����, false�� logout�� ����
//             savedID - Buyer�� ID
//             savedPassword - Buyer�� password
// return value : ����

Buyer::Buyer(int userType, string name, int identityNumber, bool loginState, string savedID, string savedPassword)
	: Member(userType, name, identityNumber, loginState, savedID, savedPassword){

}

//fuction : ~Buyer()
//description : Buyer��ü �Ҹ���

Buyer::~Buyer(){}
// function : 
// description : Buyer�� ������ Ƽ�� ����Ʈ�� �����Ѵ�
// parameter : ����
// return value : ���� Ƽ�� ����Ʈ
vector<int> Buyer::getReserveTicketList() {
	return this->reserveTicketList;
}

// function : void addBuyersTicketList(int TicketID)
// description : Buyer�� Ƽ�ϸ���Ʈ�� ���� ������ Ƽ���� ���̵� �߰��Ѵ�
// parameter : int TicketID - ���� �߰��ϴ� Ƽ���� ID
// return value : ����
void Buyer::addBuyersTicketList(int ticketID) {
	this->reserveTicketList.push_back(ticketID);
}


// function : void deleteTicket(int)
// description : Ƽ��id�� �޾Ƽ� ��� Ƽ�� ��Ͽ��� ����
// parameter : int ticketID
// return value :None
void Buyer::deleteTicket(int ticketID) {
	auto fst = reserveTicketList.begin();
	for (int i = 0; i < reserveTicketList.size(); i++) {
		if (ticketID == reserveTicketList[i]) {
			reserveTicketList.erase(fst + i);
			return;
		}
	}
}
