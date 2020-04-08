#include <iostream>
#include <fstream>
#include <string>
#include "RegisterTicketUI.h"
#include "RegisterTicket.h"
using namespace std;

// function : inputTicketInformationToRegister()
// description : Ƽ�� ����� ���� ������ �Է��ϴ� �Լ�
// parameter : ifstream &in_fp :��ǲ����
//						ofstream &out_fp : �ƿ�ǲ����
// return value : ����

void RegisterTicketUI::inputTicketInformationToRegister(ifstream &in_fp, ofstream &out_fp, RegisterTicket& registerTicket) {
	int price, year, month, day, hour, minute; int remainHour, remainMinute;
	string matchDateNTime; string seatPos; 
	string homeTeam, awayTeam;
	bool selectLTA, soldOut;

	out_fp << "3.1. �Ǹ�Ƽ�� ���" << endl;
	in_fp >> price >> matchDateNTime >> homeTeam >> awayTeam >> seatPos >> selectLTA;
	// ��� ��¥�� �ð� �з�
	year = stoi(matchDateNTime.substr(0, 4)); month = stoi(matchDateNTime.substr(5, 2)); day = stoi(matchDateNTime.substr(8, 2));
	hour = stoi(matchDateNTime.substr(11, 2)); minute = stoi(matchDateNTime.substr(14, 2));
	
	bool success = registerTicket.requestNewTicket(price, year, month, day, hour, minute, homeTeam, awayTeam, seatPos, selectLTA);

	if (success) {
		out_fp << "> " << price << " " << matchDateNTime << " " << homeTeam << " " << awayTeam << " " << seatPos << " " << (unsigned int)selectLTA << endl;
	}
	else {
		out_fp << "Ƽ�� ��� ����" << endl;
	}
}