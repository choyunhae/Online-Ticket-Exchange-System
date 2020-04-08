#pragma once
#include "TicketManager.h"
#include "Seller.h"
#include "CheckEnrolledTicket.h"
#include "Ticket.h"
#include <vector>
#include "MemberManager.h"
using namespace std;

// function : getSellersTIcketList()
// description : Ư�� ������ ����� Ƽ�� ����Ʈ�� �����Ͽ� �������ִ� �Լ�
// parameter : None
// return value : vector<pair<int, TIcket*>>sortedList
vector<pair<int,Ticket>> CheckEnrolledTicket:: getSellersTIcketList() {
	MemberManager *sellerManager = MemberManager::getInstance();
	TicketManager *ticketManager = TicketManager::getInstance();
	Seller * seller =(Seller*)sellerManager->getCurrentMemberPtr();
	vector<int> sellerList = seller->getSellersTicketList();
	ticketManager -> setTicketList(sellerList);
	vector<pair<int, Ticket>> sortedList = ticketManager->getTicketList();
	return sortedList;
}
