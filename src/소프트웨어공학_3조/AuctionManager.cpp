#pragma once
//#include <iostream>
#include "AuctionManager.h"
#include "Ticket.h"
#include <algorithm>
using namespace std;



AuctionManager* AuctionManager::instance = nullptr;

AuctionManager::AuctionManager() {}


//-----------------------------------------------------------------------------
// Function: AuctionManager* getInstance()
// Description: �̱��� ������ �����ϱ� ���� �Լ�
//				�ν��Ͻ��� ������� �ִٸ� �ش� �ν��Ͻ��� �ּҸ�,
//				�׷��� �ʴٸ� �ν��Ͻ��� ���� �����Ҵ��� �� �ּҸ� ��ȯ��
// Parameters: None
// Return Value: AuctionManager �ν��Ͻ��� ������
//-----------------------------------------------------------------------------
AuctionManager* AuctionManager::getInstance() {
	if (!instance) instance = new AuctionManager();
	return instance;
}


//-----------------------------------------------------------------------------
// Function: bool isAuctionList(int ticketID)
// Description: ������� Ƽ�� ����Ʈ�� �Ķ���ͷ� ���� Ƽ���� ���ԵǴ��� Ȯ��
// Parameters: int ticketID - ���ԵǴ��� Ȯ���� Ƽ���� ID
// Return Value: boolean - ���ԵǸ� true, or false;
//-----------------------------------------------------------------------------
bool AuctionManager::isAuctionList(int ticketID) {
	bool hasTicket = binary_search(tickets.begin(), tickets.end(), ticketID);
	if (hasTicket) return true;
	return false;
}


//-----------------------------------------------------------------------------
// Function: vector<int> getAuctionTicketList()
// Description: ���� ��� ���� Ƽ�� ����Ʈ�� ��ȯ�Ѵ�
// Parameters: None
// Return Value: vector<int> tickets - ���� ��� ���� Ƽ��ID ����Ʈ
//-----------------------------------------------------------------------------
vector<int> AuctionManager::getAuctionTicketList() {
	return tickets;
}


//-----------------------------------------------------------------------------
// Function: void addBiddingInfo(int ticketID, int price, string buyerID)
// Description: �����ڰ� ���� �õ��� ���� ������ ������.
//				��, ID�� ���� Ƽ�Ͽ� ���� ������ �õ��� ���������� �̹� ��ϵ� �������� �� ���ٸ�
//				�ƹ��ϵ� ���� �ʰ� ����.
//				���� �������� �׻� Ƽ��ID�� �������� ������������ ����ǵ��� �߰���
// Parameters:	int ticketID - ������ �õ��ϴ� Ƽ���� ID
//				int price - ������
//				string buyerID - ������ �õ��� �������� ID
// Return Value: None
//-----------------------------------------------------------------------------
void AuctionManager::addBiddingInfo(int ticketID, int price, string buyerID) {
	if (!isAuctionList(ticketID)) return;

	auto it = lower_bound(biddingInfoList.begin(), biddingInfoList.end(), make_tuple(ticketID, 0, ""));
	int id = 0;

	if (it != biddingInfoList.end())
		id = get<0>(*it);

	auto info = make_tuple(ticketID, price, buyerID);

	// ���� �����ڰ� ���� ���
	if (id != ticketID) {
		biddingInfoList.insert(it, info);
	}
	else {
		int old_price = get<1>(*it);
		// ���ο� �������� ���� ���������� ũ�� info ������ ��ü 
		if (price > old_price) {
			*it = info;
		}
	}
}


//------------------------------------------------------------------------------
// Function: void updateAuctionTicketList(vector<int> newAuctionList)
// Description: ���ο� ��� ���� Ƽ�� ����Ʈ�� �޾� ����Ʈ�� ���� ����
//				Ƽ���� �ߺ��ؼ� �������� ������, �׻� ������������ ���ĵ�
// Parameters: vector<int> newAuctionList - ���ο� ��� ���� Ƽ�� ����Ʈ
// Return Value: None
//------------------------------------------------------------------------------
void AuctionManager::updateAuctionTicketList(vector<int> newAuctionList) {
	// tickets �ʱ�ȭ
	tickets.clear();

	// �Է����� ���� ����Ʈ �ߺ� ����
	sort(newAuctionList.begin(), newAuctionList.end());
	newAuctionList.erase(unique(newAuctionList.begin(), newAuctionList.end()), newAuctionList.end());

	tickets = newAuctionList;

	sort(tickets.begin(), tickets.end());
}


//------------------------------------------------------------------------------
// Function: tuple<int, int, string> getBiddingInfo(int ticketID)
// Description: ticketID�� �޾� �ش� Ƽ�Ͽ� ���� ������ biddingInfoList�� ������ �� Ʃ���� ��ȯ��
// Parameters: int ticketID - ã�⸦ ���ϴ� Ƽ�� id
// Return Value: ������ - �ش� Ƽ���� ��������
//				���н� - �⺻ �����ڷ� �ʱ�ȭ�� Ʃ��
//------------------------------------------------------------------------------
tuple<int, int, string> AuctionManager::getBiddingInfo(int ticketID) {
	for (auto biddingInfo : biddingInfoList) {
		int id = get<0>(biddingInfo);
		if (id == ticketID)
			return biddingInfo;
	}
	return tuple<int, int, string>();
}


/*
// Test code ------------------------------------------------
int main() {
	AuctionManager* am = AuctionManager::getInstance();
	vector<int> p;
	p.push_back(1); p.push_back(2); p.push_back(10); p.push_back(5); p.push_back(2);
	am->updateAuctionTicketList(p);
	//cout << "ID: " << *am << '\n';
	am->addBiddingInfo(4, 999, "�̰Գ�����ȵ�");
	am->addBiddingInfo(5, 555, "5��1");
	am->addBiddingInfo(2, 222, "2��1");
	am->addBiddingInfo(1, 123, "1��1");
	am->addBiddingInfo(5, 666, "5��2");
	am->addBiddingInfo(5, 333, "5��x");
	am->addBiddingInfo(1, 321, "1��2");
	cout << *am;
}
*/