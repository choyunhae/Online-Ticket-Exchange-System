#include "CheckReservedTicketUI.h"

CheckReservedTicketUI::CheckReservedTicketUI()
{
}

CheckReservedTicketUI::~CheckReservedTicketUI()
{
}

// Function : void startCheckReservedTicket(ifstream & in, ofstream & out)
// Description : use case.Check Reserved Ticket�� �����ϱ� ���� �Լ�.
// Parameters :
//				ifstream & in - input �ؽ�Ʈ ������ ���۷���
//				ofstream & out - output �ؽ�Ʈ ������ ���۷���
// Return Value : None
// Created : 2019/06/02 03:22 pm
// Author : ������
// Revisions :
//	1.	When & Who : 2019/06/03 03:41 am by ������
//		What : startCheckReservedTicket �Լ����� ���� ������� ���� �Ű� ������ ���Ͻ�Ʈ�� ���۷��� �߰� �� ���� ����
//	2.	When & Who : 2019/06/05 07:30 pm by ������
//		What : ������ Ƽ���� ���� ��쿡 "> " �� ������ ��µǰ� ����
void CheckReservedTicketUI::startCheckReservedTicket(ifstream & in, ofstream & out)
{
	CheckReservedTicket CRT;
	unsigned int price, year, month, day, hour, minute;
	string seatPos;
	string homeTeam, awayTeam;

	out << "4.5. ���� ���� ��ȸ" << endl;
	vector<pair<int, Ticket>> list(CRT.getReservedTicketList());

	for (int i = 0; i < list.size(); i++)
	{
		price = list[i].second.getBuyerPrice();
		year = list[i].second.getMatchTime().year;
		month = list[i].second.getMatchTime().month;
		day = list[i].second.getMatchTime().day;
		hour = list[i].second.getMatchTime().hour;
		minute = list[i].second.getMatchTime().min;

		homeTeam = list[i].second.getHomeTeam(); awayTeam = list[i].second.getBasicInfo().awayTeam;
		seatPos = list[i].second.getBasicInfo().seatPosition;
		Timer::TimeSet match(year, month, day, hour, minute);

		out << "> " << price << " " << match << " " << homeTeam << " " << awayTeam << " " << seatPos << endl;
	}
}
