#pragma once
#include "CheckEnrolledTicketUI.h"
#include "CheckEnrolledTicket.h"
#include "TicketManager.h"
#include "Member.h"
#include "TicketManager.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <string>

using namespace std;
// function : startCheckEnrolledTicket(ifstream &in_fp, ofstream &out_fp, CheckEnrolledTicket& enrolledTicketList)
// description : ���Ͱ� ��� Ƽ�� ��ȸ�� �����ϵ��� ��û�ϴ� �Լ�
// parameter :ifstream &in_fp, ofstream &out_fp, CheckEnrolledTicket& enrolledTicketList
// return value : None
//revision:
//1.when&who:2019/06/04 02:01pm, ������
//what :��¹� ���� ���߱� ���� ����
//1.when&who:2019/06/04 02:01pm, ������
//what :�ð� ��� �κ� ����

void CheckEnrolledTicketUI::startCheckEnrolledTicket(ifstream &in_fp, ofstream &out_fp) {
	CheckEnrolledTicket ticketList;
	vector<pair <int, Ticket>> enrolledTicketList = ticketList.getSellersTIcketList();
	unsigned int price;
	string matchDateNTime; string seatPos;
	string homeTeam, awayTeam;
	Timer::TimeSet time;

	int i = 0;
	out_fp << "3.2. ���Ƽ�� ��ȸ" << endl;
	for (i; i < enrolledTicketList.size(); i++) {
		price = enrolledTicketList[i].second.getSellerPrice();
		time = enrolledTicketList[i].second.getMatchTime();
		homeTeam = enrolledTicketList[i].second.getHomeTeam();
		awayTeam = enrolledTicketList[i].second.getBasicInfo().awayTeam;
		seatPos = enrolledTicketList[i].second.getBasicInfo().seatPosition;
		bool la = enrolledTicketList[i].second.getLimitedAuction();
		out_fp << "> "
			<< price << " "
			<< time << " "
			<< homeTeam << " "
			<< awayTeam << " "
			<< seatPos << " "
			<< la << " ";
		if (enrolledTicketList[i].second.getBuyerID() != "")
			out_fp << "1" << endl;
		else
			out_fp << "0" << endl;
	}
}

