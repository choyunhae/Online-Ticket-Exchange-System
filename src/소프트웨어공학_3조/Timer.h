#pragma once
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

// Class : Timer
// Description : �ð��� ���õ� ���� �����ϴ� Ŭ����.
//				���� �ð��� �����ϱ� ���� ctime include.
//				�ð��� ���� ������, �ð��� ���� �����ϰ� �Ǵ� �Լ��� ������ ����.
//				��� ������ timeSet ����ü�� currentTime�� ������ ����.
//				timeSet ����ü�� �ð��� ���� ���� ������ �� �ֵ��� int���� ������ ����.
//				��� �Լ��δ� getCurrenTime(), setCurrentTime(), addTicketToAuctionList()�� ������ ����.
// Created : 2019/05/29 01:00 am
// Author : ������
// Revisions: 
//	1. When & Who : 2019/06/03 01:58 am by ������
//		What: 1) struct TimeSet�� public���� ����
//			  2) Ŭ���� ���ο� ����� �Լ����� �и��Ͽ� cpp���Ͽ� ����
//			  3) static Timer* singletonInstance; �� �ʱ�ȭ�ϵ��� cpp���Ͽ� �ڵ� �߰�
//			  4) Timer() �����ڸ� ���� �صΰ� �������� ���� -> cpp���Ͽ� ������
//			  5) Timer::TimeSet ����ü�� ostream, ofstream << ������ �����ε� ��.
//				���Ŀ� �°Բ� ����ϵ��� �����ε�
//			  6) Timer::TimeSet ����ü�� istream, ifstream >> ������ �����ε� ��
//				���Ŀ� �°Բ� �Է¹޵��� �����ε�
//			  7) Timer::TimeSet ����ü == ������ �����ε�, ��� ����� ������ true ��ȯ
//	2. When & Who : 2019/06/03 07:38 am by ������
//		What: 1) �Լ� �߰�
//				(1) void timeRelatedAutomationFunction()
//					: setCurrentTime() ����� �������� �����. �Ʒ� �� ���� �Լ��� ��������ִ� �Լ�
//				(2) void endAuction(): ������� Ƽ���� ����/������ �����ϰ� �׿����� ó��
//				(3) void updateAuctionTicketList(): �ð��� �帧�� ���� ���ο� ����� Ƽ�� ������Ʈ
//				(4) void deleteOneYearTickets(): �Ǹŵ��� 1���� ���� Ƽ���� ����
// 3. When & Who: 2019/06/23 10:23 pm by ������
//		Waht: 1) pair<int, int> minToHour_Min(int) �Լ� �߰�

class Timer
{
public:
	~Timer();
	struct TimeSet {
		unsigned int year, month, day, hour, min;

		TimeSet() { year = month = day = hour = min = 0; }
		TimeSet(int y, int m, int d, int h, int mi) : year(y), month(m), day(d), hour(h), min(mi) {}
		friend ostream& operator << (ostream&, const TimeSet&);
		friend ofstream& operator << (ofstream&, const TimeSet&);
		friend ifstream& operator >> (ifstream&, TimeSet&);
		friend istream& operator >> (istream&, TimeSet&);
		bool operator == (const TimeSet&);
	};
private:
	Timer();
	static Timer* singletonInstance;
	TimeSet currentTime;

	void timeRelatedAutomationFunction();
	void updateAuctionTicketList();
	void endAuction();
	void deleteOneYearTickets();
public:
	static Timer* getInstance();
	TimeSet getCurrentTime();

	void setCurrentTime(ifstream & in, ofstream & out);
	pair<int, int> minToHour_Min(int);
	int getRemainingTime(TimeSet t);
};

