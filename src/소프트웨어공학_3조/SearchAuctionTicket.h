#pragma once
#include <vector>
#include <string>
#include "Ticket.h"
using namespace std;
//------------------------------------------------------------------------------------
// class: SearchAuctionTicket
// Description: ��� ���� Ƽ�� �˻��� ���Ǵ� ��Ʈ�� Ŭ����
// Created: 2019/06/03 03:49 am
// Author: ������
//------------------------------------------------------------------------------------
class SearchAuctionTicket {
public:
	vector<pair<int, Ticket>> showSelectedHomeTeamAuctionTicketList(string);
	void showAuctionParticipationInterface(Timer::TimeSet, string, string, int);
};