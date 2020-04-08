#include <iostream>
#include <fstream>
#include <string>
#include "RegisterTicket.h"
#include "Timer.h"
#include "TicketManager.h"
#include "MemberManager.h"
using namespace std;

// function : requestNewTicket(int price, int year, int month, int day, int hour, int minute,
//														string homeTeam, string awayTeam, string seatPos, bool selectLTA)
// description : Ƽ�� ����� ��û�ϴ� �Լ�
// parameter : ifstream &in_fp :��ǲ����
//						ofstream &out_fp : �ƿ�ǲ����
// return value : bool - Ƽ�� ��� �����ϸ� true, �����ϸ� false

bool RegisterTicket::requestNewTicket(int price, int year, int month, int day, int hour, int minute,
																	string homeTeam, string awayTeam, string seatPos, bool selectLTA) {
	Timer::TimeSet ticketTime(year, month, day, hour, minute);
	int remainingtime = Timer::getInstance()->getRemainingTime(ticketTime);

	//������ �����۱��� ��Ʋ �̻� ������ ���� ���
	if (remainingtime > 48*60) {
		int ticketID = TicketManager::getInstance()->addNewTicket(price, ticketTime, homeTeam, awayTeam, seatPos, selectLTA, MemberManager::getInstance()->getCurrentSessionID());
		
		((Seller*)(MemberManager::getInstance() ->getCurrentMemberPtr()))->addSellerTicketList(ticketID);

		return true;//Ƽ�� ��� ����
	}
	else {
		return false;//Ƽ�� ��� ����
	}
}