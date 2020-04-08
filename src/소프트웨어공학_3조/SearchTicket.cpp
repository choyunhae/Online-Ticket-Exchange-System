#include <iostream>
#include <fstream>
#include <string>
#include "SearchTicket.h"
#include "TicketManager.h"
#include "MemberManager.h"
using namespace std;

// function : showHomeTeamTicketList(string homeTeam)
// description : ������ Ȩ���� ���� ���� ������ Ƽ�� ��� ���
// parameter : string homeTeam : ���� ���� Ȩ��
// return value : ����

vector<pair<int, Ticket>> SearchTicket::showHomeTeamTicketList(string homeTeam) {
	TicketManager::getInstance()->setTicketList(homeTeam);
	
	return TicketManager::getInstance()->getTicketList();
}

// function : requestReserveTicket(Timer::TimeSet time, string awayTeam, string seatPos)
// description : ������ Ƽ���� ���� ��û
// parameter : Timer::TimeSet time
//						string awayTeam
//						string seatPos
// return value : ����
// revision :
//1.when&who: 2019/06/04 01:45pm, ������
//what:���� ����Ʈ �߰�

Ticket SearchTicket::requestReserveTicket(Timer::TimeSet time, string awayTeam, string seatPos) {
	vector<pair<int, Ticket>> homeTeamTicketList = TicketManager::getInstance()->getTicketList();

	for (int i = 0; i < homeTeamTicketList.size(); ++i) {
		Ticket::BasicInfo ticketInfo = homeTeamTicketList[i].second.getBasicInfo();
		if (awayTeam == ticketInfo.awayTeam && seatPos == ticketInfo.seatPosition && (time == ticketInfo.matchTime)) {
			TicketManager::getInstance()->reserveTicket(homeTeamTicketList[i].second.getID(), MemberManager::getInstance()->getCurrentSessionID());
			MemberManager::getInstance()->reserveTicket(homeTeamTicketList[i].second.getID(), MemberManager::getInstance()->getCurrentSessionID());

			return homeTeamTicketList[i].second;
		}
	}
}