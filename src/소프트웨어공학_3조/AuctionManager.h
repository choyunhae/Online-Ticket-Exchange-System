#pragma once
#include "Ticket.h"
#include "Timer.h"
#include <vector>
#include <tuple>
#include <string>
using namespace std;
#define ttis tuple<Ticket*, int, string>

//---------------------------------------------------------------------------------------------
// class: AuctionManager
// Description: �������� Ƽ���� �����ϴ� Ŭ����.
//				��𼭵� Ŭ������ ���� �����ϵ��� �̱��� ������ ������
//				��������� tickets, bidderList�� �׻� Ƽ��id������ ������������ �����
// Created: 2019/05/28 04:10 am
// Author: ������
// Revisions:
//	1. When & Who: 2019/06/13 08:13 am by ������
//		What: 1) bidderList �������� biddinginfoList�� ����
//			  2) tuple<int, int, string> getBiddingInfo(int) �Լ� �߰�
//				�� �Լ��� Ƽ��id�� �޾Ƽ� �ش� Ƽ���� biddingInfoList�� ������ �� Ʃ���� ��ȯ,
//				�׷��� ������ �⺻ �����ڷ� ������ Ʃ���� ��ȯ��
//---------------------------------------------------------------------------------------------
class AuctionManager {
private:
	vector<int> tickets;
	vector<tuple<int, int, string>> biddingInfoList; // Ƽ�� id, ��������, buyerID
	
	static AuctionManager* instance;

	AuctionManager();
public:
	static AuctionManager* getInstance();
	bool isAuctionList(int);
	vector<int> getAuctionTicketList();
	void addBiddingInfo(int, int, string);
	void updateAuctionTicketList(vector<int>);
	tuple<int, int, string> getBiddingInfo(int);

};