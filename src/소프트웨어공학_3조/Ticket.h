#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "Timer.h"
using namespace std;

//---------------------------------------------------------------------------------------------
// class: Ticket
// Description: Ƽ�Ͽ� ���� ������ �����ϴ� Ŭ����.
//				���������� ��¿� �ʿ��� �������� ���� ���ο� BasicInfo ����ü�� public���� ���� ����.
//				BasicInfo ����ü�� ostream, ofstream�� �����ε� �Ǿ�����. ��� ����� ���Ŀ� �°� �����.
// Created: 2019/05/27 05:29 am
// Author: ������
// Revisions:
//	1. When & Who : 2019/05/28 02:11 am by ������
//		What: 1) getID(), getPrice(), getMatchTime(), getHomeTeam(), getBuyerID() �߰�
//			  2) getRemainingTime()�� ��Ȯ�� �𸣰���. ���ǰ� �ʿ��غ���
//	2. When & Who : 2019/05/30 05:32 pm by ������
//		What: 1) ���������� Ƽ���� ���� ������ �ٲ�. TicketDetail ����ü�� ����
//			  2) ��¥, �ð��� Ticket::TimeSet����ü�� �����ϱ�� ��
//			    �׿� ���� Ticket::Date, Ticket::Time ����ü�� ������ ����,
//				��¥+�ð� ������ Timer::TimeSet matchTime���� ����
//			  3) ����(1.2)���� ������ getRemainingTime()�� TimerŬ������ ������� ��
//			  4) price�� ����� �� �־ const�� ����(Ƽ�� ������ price ����). price�� setter �ۼ���
//	3. When & Who : 2019/05/31 08:54 pm by ������
//		What: 1) ���Ǹ� ���� BasicInfo ����ü�� ����. ����δ� ��⳯¥+�ð�, Ȩ��, �������, �¼���ġ�� ����
//			   �׿� ���� Ticket�� ��� �� ������ ���� ������� �����ǰ�, Ticket�� const BasicInfo basicInfo ����� �߰���
//			  3) BasicInfo ����ü�� ostream& <<, ofstream& << �����ε��� �Ǿ�����. ���Ŀ� �°� ��µǵ��� ��
//			  4) Ƽ�� Ŭ������ ������ < �����ε���(���̵� ��������).
//				���� TicketManager���� sort�� ���� comparator�� ���� �ʾƵ� ��
//	4. When & Who: 2019/06/03 01:07 am by ������
//		What: 1) ����� ��� const�� ������. (�Ҵ� �������� �����ε��� �Ұ����� ������ �Ұ��� ��)
//			  2) Timer::TimeSet ����ü�� ostream, ofstream << ������ �����ε��� ����
//				Ticket::BasicInfo ����ü�� �����ε� �Լ��� ���� �����ε��� �̿��ϰԲ� ����
//	5. When & Who: 2019/06/03 05:02 am by ������
//		What: 1) Ticket::BasicInfo�� seatPosition�� string���� ����
//			  2) Timer::TimeSet enrolledTime ������ �߰�
//				 �� ������ ����� ��¥/�ð��� ������
//			  3) ��Ͻð��� ��ȯ�ϴ� Timer::TimeSet getEnrolledTime() �Լ� ����
//---------------------------------------------------------------------------------------------

class Ticket {
public:
	struct BasicInfo {
		Timer::TimeSet matchTime;
		string homeTeam;
		string awayTeam;
		string seatPosition;
		
		BasicInfo();
		BasicInfo(Timer::TimeSet, string, string, string);
		friend ostream& operator << (ostream&, const BasicInfo&);
		friend ofstream& operator << (ofstream&, const BasicInfo&);
	};
private:
	int ID;
	int buyerPrice;
	int sellerPrice;
	Timer::TimeSet enrolledTime;
	Ticket::BasicInfo basicInfo;
	bool limitedAuction;
	string sellerID;
	string buyerID;

public:
	Ticket();
	Ticket(int ID, int sellerPrice, Timer::TimeSet enrolledTime, Timer::TimeSet matchTime, string home, string away,
		string seat, bool la, string sellerID);
	void setBuyerID(string buyerID);
	void setBuyerPrice(int price);
	int getID();
	int getBuyerPrice();
	int getSellerPrice();
	Timer::TimeSet getMatchTime();
	string getHomeTeam();
	string getBuyerID();
	string getSellerID();
	Ticket::BasicInfo getBasicInfo();
	bool getLimitedAuction();
	Timer::TimeSet getEnrolledTime();
	friend bool operator < (const Ticket &a, const Ticket &b);
}; 