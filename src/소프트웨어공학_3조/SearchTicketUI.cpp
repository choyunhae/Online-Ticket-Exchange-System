#include <iostream>
#include <fstream>
#include <string>
#include "SearchTicketUI.h"
#include "SearchTicket.h"
#include "TicketManager.h"
#include "Timer.h"
using namespace std;

// function : SearchTicketUI::selectHomeTeamToTicketList(ifstream& in_fp, ofstream& out_fp, SearchTicket& searchTicket)
// description : ������ hometeam�� ���� ���� ������ Ƽ���� ������
// parameter : ifstream &in_fp :��ǲ����
//						ofstream &out_fp : �ƿ�ǲ����
//						SearchTicket& searchTicket
// return value : ����
//revision
//1. when&who: 2019/06/04 01:56pm, ������
//what: ��� ����

void SearchTicketUI::selectHomeTeamToTicketList(ifstream& in_fp, ofstream& out_fp, SearchTicket& searchTicket) {
	string homeTeam;

	out_fp << "4.1. Ƽ�� �˻�" << endl;
	in_fp >> homeTeam;

	vector<pair<int, Ticket>> homeTeamTicketList = searchTicket.showHomeTeamTicketList(homeTeam);

	for (int i = 0; i < homeTeamTicketList.size(); ++i) {
		out_fp << "> " << homeTeamTicketList[i].second.getSellerPrice() << " " << homeTeamTicketList[i].second.getBasicInfo() << endl;
	}
}

// function : selectTicketToReserve(ifstream& in_fp, ofstream& out_fp, SearchTicket& searchTicket)
// description : ������ Ƽ���� ����
// parameter : ifstream &in_fp :��ǲ����
//						ofstream &out_fp : �ƿ�ǲ����
//						SearchTicket& searchTicket
// return value : ����

void SearchTicketUI::selectTicketToReserve(ifstream& in_fp, ofstream& out_fp, SearchTicket& searchTicket) {
	out_fp << "4.2. Ƽ�� ����" << endl;
	Timer::TimeSet time;
	string awayTeam, seatPos;
	in_fp >> time >> awayTeam >> seatPos;
	
	Ticket reservedTicket = searchTicket.requestReserveTicket(time, awayTeam, seatPos);

	out_fp << "> " << reservedTicket.getSellerPrice() << " " << reservedTicket.getMatchTime() << " " << reservedTicket.getHomeTeam() << " " << awayTeam << " " << seatPos << endl;
}