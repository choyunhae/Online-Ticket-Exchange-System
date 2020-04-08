#pragma once
#include "TicketManager.h"
#include <utility>
#include <algorithm>
TicketManager* TicketManager::ticketManager = nullptr;

TicketManager::TicketManager() :nextID(1) {}

TicketManager::~TicketManager() {}

//-------------------------------------------------------
// Function: TicketManager:: getInstance()
// Description: �̱������� �����ϱ� ���� �Լ�
// Parameters: None
// Return Value: TicketManager
//-------------------------------------------------------
TicketManager* TicketManager::getInstance() {
	if (ticketManager == NULL)
		ticketManager = new TicketManager();
	return ticketManager;
}


//-------------------------------------------------------
// Function: TicketManager:: addNewTicket
// Description:���ο� Ƽ�Ͽ� ���� ������ �Է¹޾� Ƽ���� ���� ����ϴ� �Լ�
// Parameters: Ƽ�� ����
// Return Value:None
// ���� ����:ID���� ���� �������ִ���(�Ķ���ͷ� �Է¹����� Ȥ�� �Լ� ������ ���� ������)
//Revision
//1.when&who:2019.06.04 01:33pm, ������
//what:����� Ƽ���� ���̵� �����ϰ� ����
//-------------------------------------------------------
int TicketManager::addNewTicket(int price, Timer::TimeSet matchTime,
	string home, string away, string seat, bool la, string sellerID) {
	
	Timer::TimeSet curTime = Timer::getInstance()->getCurrentTime();
	Ticket* ticket = new Ticket(nextID++, price, curTime, matchTime, home, away, seat, la, sellerID);
	tickets.push_back(ticket);

	return ticket->getID();
}


//-------------------------------------------------------
// Function: TicketManager:: addTicketToSortedList
// Description:sortList�� �ش� Ƽ�ϰ� �����ð��� �ִ� �Լ�
// Parameters:remain T, ticket
// Return Value:None
//--------------------------------------------------------
void TicketManager::addTicketToSortedList(int remainT, Ticket ticket) {
	sortLists.push_back(make_pair(remainT, ticket));
}


//-------------------------------------------------------
// Function: Ticket* TicketManager::getTicketPointer(int ticketID)
// Description: Ư�� Ƽ���� id�� �޾Ƽ� �ش� Ƽ���� �����͸� ��ȯ
// Parameters: int ticketID - �޾ƿ� Ƽ���� ID
// Return Value: �ش��ϴ� ID�� ���� �� - �ش� Ƽ���� ������
//							 ���� �� - NULL
//--------------------------------------------------------
Ticket* TicketManager::getTicketPointer(int ticketID) {
	for (Ticket* ticket : tickets) {
		if (ticket->getID() == ticketID) {
			return ticket;
		}
	}
	return NULL;
}


//-------------------------------------------------------
// Function: Ticket* TicketManager::getTicketPointer(int ticketID)
// Description: Ư�� Ƽ���� id�� �޾Ƽ� �ش� Ƽ�� ��ü�� ��ȯ
// Parameters: int ticketID - �޾ƿ� Ƽ���� ID
// Return Value: �ش��ϴ� ID�� ���� �� - �ش� Ƽ�� ��ü
//							 ���� �� - �� Ƽ�� ��ü 
//--------------------------------------------------------
Ticket TicketManager::getTicket(int ticketID) {
	Ticket ret;
	for (Ticket* ticket : tickets) {
		if (ticket->getID() == ticketID) {
			return *ticket;
		}
	}
	return Ticket();
}

//-------------------------------------------------------
// Function: TicketManager:: reserveTicket
// Description:Ư�� Ƽ���� �����ش޶�� �޼��� �����ϴ� �Լ�
// Parameters:Ƽ�� ���̵�
// Return Value:None
//--------------------------------------------------------
void TicketManager::reserveTicket(int ticketID, string buyerID) {
	Ticket* ticket = getTicketPointer(ticketID);
	if (!ticket) {
		cout << "void TicketManager::reserveTicket(int ticketID, string buyerID)\n";
		cout << ": nullptr error\n";
		return;
	}
	ticket->setBuyerID(buyerID);
}


//-------------------------------------------------------
// Function: void reserveTicket(int ticketID, int price, string buyerID)
// Description:Ư�� Ƽ���� �����ش޶�� �޼��� �����ϴ� �Լ�
//				�� �Լ��� ��� ������ ���̰� ��
// Parameters: int ticketID - ���� ������ Ƽ��id
//				int price - ������ ����
//				string buyerID - ������ ID
// Return Value:None
//--------------------------------------------------------
void TicketManager::reserveTicket(int ticketID, int price, string buyerID) {
	Ticket* ticket = getTicketPointer(ticketID);

	ticket->setBuyerPrice(price);
	ticket->setBuyerID(buyerID);
	//cout << "reserveTicket: " << ticket->getID() << ' ' << ticket->getBasicInfo() << endl;
}


//-------------------------------------------------------
// Function: TicketManager:: sortList
// Description:sortLists�� �ִ� Ƽ�� ��ϵ��� ��⳯¥ �� �ð��� ���� Ƽ�Ϻ��� �����Ͽ� ���
// Parameters:None
// Return Value:SortLists
//--------------------------------------------------------
void TicketManager::sortList() {
	sort(sortLists.begin(), sortLists.end());
}

// Function: void setTicketList(string home)
// Description: ��� Ƽ�� ����� sortLists�� ������
//				���� �ð��� �ǽð����� ���Ͽ� �Բ� ������
// Parameters: None
// Return Value: None
void TicketManager::setTicketList() {
	sortLists.clear();

	for (Ticket *tp : tickets) {
		Ticket ticket = *tp;
		Timer::TimeSet matchTime = ticket.getMatchTime();
		int remainTime = Timer::getInstance()->getRemainingTime(matchTime);
		addTicketToSortedList(remainTime, ticket);
	}

	sortList();
}
// Function: void setTicketList(string home)
// Description: home���� �޾� �ش� Ȩ���� *���� ������* Ƽ�� ����� sortLists�� ������
//				���� �ð��� �ǽð����� ���Ͽ� �Բ� ������
// Parameters: string home - Ȩ��
// Return Value: None
void TicketManager::setTicketList(string home) {
	sortLists.clear();

	for (Ticket* tp : tickets) {
		Ticket ticket = *tp;

		string ticketHome = ticket.getHomeTeam();
		string buyerID = ticket.getBuyerID();
		if ((ticketHome != home) || (buyerID != "")) continue;

		int id = ticket.getID();
		if (AuctionManager::getInstance()->isAuctionList(id)) continue;

		Timer::TimeSet matchTime = ticket.getMatchTime();
		int remainTime = Timer::getInstance()->getRemainingTime(matchTime);
		if (remainTime <= 60 * 24) continue;

		addTicketToSortedList(remainTime, ticket);
	}

	sortList();
}


// Function: void setTicketList(vector<int> lst)
// Description: Ƽ�� ID���� ����Ʈ�� �޾� �ش� Ƽ���� sortLists�� �߰���
//				���� �ð��� �ǽð����� ���Ͽ� �Բ� ����
// Parameters: vector<int> lst - �߰��� Ƽ���� ID ����Ʈ
// Return Value: None
void TicketManager::setTicketList(vector<int> lst) {
	sortLists.clear();

	for (int id : lst) {
		Ticket ticket = getTicket(id);
		Timer::TimeSet matchTime = ticket.getMatchTime();
		int remainTime = Timer::getInstance()->getRemainingTime(matchTime);

		addTicketToSortedList(remainTime, ticket);
	}

	sortList();
}


// Function: void setTicketList(string home, vector<int> lst)
// Description: Ȩ���� Ƽ�� ID���� ����Ʈ�� ���� �� �ش�Ǵ� Ȩ���� Ƽ���̶�� Ƽ���� sortLists�� �߰���
//				���� �ð��� �ǽð����� ���Ͽ� �Բ� ������
// Parameters:	string home - ���ϴ� Ȩ��
//				vector<int> lst - �߰��� Ƽ���� ID ����Ʈ
// Return Value: None
void TicketManager::setTicketList(string home, vector<int> lst) {
	sortLists.clear();

	for (int id : lst) {
		Ticket ticket = getTicket(id);
		Timer::TimeSet matchTime = ticket.getMatchTime();
		string ticketHomeTeam = ticket.getHomeTeam();
		int remainTime = Timer::getInstance()->getRemainingTime(matchTime);

		if (home == ticketHomeTeam)
			addTicketToSortedList(remainTime, ticket);
	}

	sortList();
}

// Function: vector<pair<int, Ticket>> getTicketList()
// Description: setTicketList()�� ���� ������ sortLists�� ��ȯ��
// Parameters: None
// Return Value: ��� ���� sortLists
vector<pair<int, Ticket>> TicketManager::getTicketList() {
	return sortLists;
}

void TicketManager::deleteTicket(int ticketID) {
	Ticket *pticket = getTicketPointer(ticketID);
	for (int i = 0; i < tickets.size(); i++) {
		Ticket *t = tickets[i];
		if (t->getID() == ticketID) {
			tickets.erase(tickets.begin() + i);
			break;
		}
	}
	delete pticket;
}
