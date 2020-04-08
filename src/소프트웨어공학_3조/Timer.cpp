#include "Timer.h"
#include <iomanip>
#include <string>
#include "TicketManager.h"
#include "AuctionManager.h"
#include "MemberManager.h"
#pragma warning(disable : 4996)

Timer* Timer::singletonInstance = nullptr;
Timer::Timer() {}
Timer::~Timer() {}


// Function : static Timer * getInstance()
// Description : Timer�� �̱��� Ŭ���� �ν��Ͻ��� ���ٸ� �����ϰ�, �ش� �ν��Ͻ��� ������ ��ȯ.
// Parameters : None
// Return Value : Timer * instance;
// Created : 2019/05/30 09:01 pm
// Author : ������
Timer * Timer::getInstance() {
	if (!singletonInstance) singletonInstance = new Timer();
	return singletonInstance;
}


// Function : void timeRelatedAutomationFunction()
// Description : �̸� �״�� �ð��� ���õ� �ڵ�ȭ �Լ���
//				��� ����/����, ���ο� ��� �� Ƽ�� ������Ʈ, �Ǹ����� 1���� ���� Ƽ�� ������
//				������� ������
// Parameters : None
// Return Value : None 
// Created : 2019/06/03 07:21 am 
// Author : ������
void Timer::timeRelatedAutomationFunction() {
	/*
	! ���� !
	�׻� endAuction, deleteOneYearTickets, updateAuctionTicketList �� ������ ������Ѿ� ��
	*/
	this->endAuction();
	this->deleteOneYearTickets();
	this->updateAuctionTicketList();
}


// Function : void endAuction()
// Description : ��� ���۱��� 6�ð� ���Ϸ� ���� ��Ű� ����� Ƽ�ϵ��� ����/���� ó����
// Parameters : None
// Return Value : None 
// Created : 2019/06/03 07:21 am 
// Author : ������
void Timer::endAuction() {
	TicketManager *tm = TicketManager::getInstance();
	AuctionManager *am = AuctionManager::getInstance();
	MemberManager *mm = MemberManager::getInstance();

	// ��� ���� Ƽ�� ID ����Ʈ �޾ƿ�
	vector<int> auctionTicketIDList = am->getAuctionTicketList();

	// ������ ���� ����Ʈ�� ���� Ƽ�� ��ü�� ����Ʈ�� �޾ƿ�
	tm->setTicketList(auctionTicketIDList);
	vector<pair<int, Ticket>> tickets = tm->getTicketList();

	for (auto ticketPair : tickets) {
		int remainTime = ticketPair.first;
		Ticket ticket = ticketPair.second;
		int ticketID = ticket.getID();
		
		// ���� �ð��� 6�ð� �����ϋ� ����/���� ó����
		if (remainTime <= 60 * 6) {
			tuple<int, int, string> biddingInfo = am->getBiddingInfo(ticketID);
			
			// �����ڰ� ������ -> ����
			int id = get<0>(biddingInfo);
			if (ticketID == id) {
				int price = get<1>(biddingInfo);
				string buyerID = get<2>(biddingInfo);
				
				// Ƽ�� ���Ű���, ������ ����
				tm->reserveTicket(ticketID, price, buyerID);
				// �������� ������ Ƽ�� ��Ͽ� �߰�
				mm->reserveTicket(ticketID, buyerID);
			}
		}
	}
}


// Function : void updateAuctionTicketList()
// Description : �ð��� �帧�� ���� ���� ��ſ� ������ �� Ƽ�ϵ��� ������Ʈ��
// Parameters : None
// Return Value : none
// Created : 2019/06/03 07:21 am 
// Author : ������
void Timer::updateAuctionTicketList() {
	TicketManager *tm = TicketManager::getInstance();
	AuctionManager *am = AuctionManager::getInstance();

	// ��� Ƽ�� �޾ƿ���
	tm->setTicketList();
	vector<pair<int, Ticket>> tickets = tm->getTicketList();

	vector<int> newAuctionTicketIDList;
	for (auto ticketPair : tickets) {
		int remainTime = ticketPair.first;
		Ticket ticket = ticketPair.second;
		Timer::TimeSet matchTime = ticket.getMatchTime();
		string buyerID = ticket.getBuyerID();

		if (buyerID != "") continue;
		// ���� �ð��� 6�ð� �ʰ�, 24�ð� �����϶� ������Ʈ ��Ͽ� �߰���
		if (60 * 6 < remainTime && remainTime <= 60 * 24) {
			newAuctionTicketIDList.push_back(ticket.getID());
		}
	}
	
	//AuctionManager�� ��� �� Ƽ�� ����Ʈ�� �߰�
	am->updateAuctionTicketList(newAuctionTicketIDList);
}


// Function : deleteOneYearTickets()
// Description : 1�� ���� Ƽ���� ������ ������
// Parameters : None
// Return Value : None 
// Created : 2019/06/03 07:21 am 
// Author : ������
void Timer::deleteOneYearTickets() {
	TicketManager *tm = TicketManager::getInstance();
	AuctionManager *am = AuctionManager::getInstance();
	MemberManager *mm = MemberManager::getInstance();

	tm->setTicketList();
	vector<pair<int, Ticket>> ticketList = tm->getTicketList();
	for (auto ticketPair : ticketList) {
		Ticket ticket = ticketPair.second;

		TimeSet enrolledTime = ticket.getEnrolledTime();
		int remainTime = getRemainingTime(enrolledTime);
		//cout << "�ð�: " << remainTime << '\n';
		// 365�� -> 24�ð� -> 60��
		if (remainTime > -(365 * 24 * 60))
			continue;
		//cout << "true\n";

		int ticketID = ticket.getID();
		string sellerID = ticket.getSellerID();
		string buyerID = ticket.getBuyerID();
		
		Ticket t = tm->getTicket(ticketID);
		//cout << "���� �ð�: " << remainTime << endl;
		//cout << "1�� ������ ����: " << t.getPrice() << ' ' << t.getBasicInfo() << endl;

		tm->deleteTicket(ticketID);
		
		mm->deleteMembersTicket(ticketID, sellerID);
		if(buyerID != "")
			mm->deleteMembersTicket(ticketID, buyerID);
	}
}



// Function : TimeSet getCurrentTime()
// Description : ���� �ð��� ���� ���� ��ȯ.
// Parameters : None
// Return Value : (struct) TimeSet currentTime
// Created : 2019/05/29 01:13 am
// Author : ������
Timer::TimeSet Timer::getCurrentTime() {
	return currentTime;
}


// Function : void setCurrentTime(int y, int m, int d, int h, int mi)
// Description : Timer�� ��� ����ü�� currentTime�� �Է� ���� �ð��� ����.
// Parameters : int y - year
//				int m - month
//				int d - day
//				int h - hour
//				int mi - minute
// Return Value : None
// Created : 2019/05/29 01:14 am
// Author : ������
// Revisions:
//	1. When & Who : 2019/06/03 07:55 am by ������
//		What: 1) �Լ��� �������� void Timer::timeRelatedAutomationFunction()�� �����Ű���� ��
//	2.	When & Who : 2019/06/03 05:06 pm by ������
//		What : �Լ� ������ ���� ��Ʈ���� ���۷����� �Է� �޾� �Ľ��� ���� ���� �ð��� ������ �� �ֵ���,
//			�Ű� ������ ���� ��Ʈ������ ���� �� ���� ����
void Timer::setCurrentTime(ifstream & in, ofstream & out)
{
	unsigned int year, month, day, hour, minute;
	string matchDateNTime;

	out << "5.1. ����ð� ����" << endl;
	in >> matchDateNTime;
	// ��¥�� �ð� �з�
	year = stoi(matchDateNTime.substr(0, 4)); month = stoi(matchDateNTime.substr(5, 2)); day = stoi(matchDateNTime.substr(8, 2));
	hour = stoi(matchDateNTime.substr(11, 2)); minute = stoi(matchDateNTime.substr(14, 2));

	currentTime.year = year;
	currentTime.month = month;
	currentTime.day = day;
	currentTime.hour = hour;
	currentTime.min = minute;

	out << "> " << currentTime << endl;

	this->timeRelatedAutomationFunction();
}



// Function : pair<int, int> minToHour_Min(int)
// Description : ������ ��Ÿ�� �ð��� ��:�� �� �������� ��ȯ��
//				�Է����� ���� ���ڴ� 24*60(�ð�*��)�� ���� ����
// Param: int curTime - ������ ��Ÿ�� �ð�
//
// Created : 2019/06/03 10:10 pm
// Author : ������
pair<int, int> Timer::minToHour_Min(int time) {
	return { time / 60, time % 60 };
}

// Function : int getRemainingTime(TimeSet t)
// Description : TimeSet ����ü Ÿ������ Ƽ���� ��� �ð� ������ �޾ƿ�,
//				���� ����� �ð����� ���� �ð��� ����Ͽ� ��ȯ.
// Parameters : TimeSet t
// Return Value : (int) remainT
// Created : 2019/05/30 09:36 pm
// Author : ������
// Revisions :
//	1.	When & Who : 2019 / 06 / 03 02 : 50 am by ������
//		What: ���� ������, �ݺ��� ���� ����
int Timer::getRemainingTime(TimeSet t)
{
	TimeSet local_timeSet(t.year - 1900, t.month - 1, t.day, t.hour, t.min);
	TimeSet local_currentTimeSet(currentTime.year - 1900, currentTime.month - 1, currentTime.day, currentTime.hour, currentTime.min);
	unsigned int remainT;
	int mday[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	local_timeSet.month += local_timeSet.year * 12;
	for (; local_timeSet.month > 11; local_timeSet.month -= 12) local_timeSet.day += 365;
	for (int i = 0; i < local_timeSet.month; i++) local_timeSet.day += mday[i];
	local_timeSet.hour += local_timeSet.day * 24;
	local_timeSet.min += local_timeSet.hour * 60;

	local_currentTimeSet.month += local_currentTimeSet.year * 12;
	for (; local_currentTimeSet.month > 11; local_currentTimeSet.month -= 12) local_currentTimeSet.day += 365;
	for (int i = 0; i < local_currentTimeSet.month; i++) local_currentTimeSet.day += mday[i];
	local_currentTimeSet.hour += local_currentTimeSet.day * 24;
	local_currentTimeSet.min += local_currentTimeSet.hour * 60;

	remainT = local_timeSet.min - local_currentTimeSet.min;

	return remainT;
}


// Function : ostream& operator <<(ostream& os, const Timer::TimeSet& time)
// Description : Timer::TimeSet ����ü�� ostream << �����ε� �Լ�
//				���Ŀ� �°Բ� ����ϵ��� ��
// Created : 2019/06/03 02:10 am
// Author : ������
ostream& operator << (ostream& os, const Timer::TimeSet& time) {
	int year = time.year;
	int mon = time.month;
	int day = time.day;
	int hour = time.hour;
	int min = time.min;

	os << setw(4) << setfill('0') << year << ":" << setw(2) << setfill('0') << mon << ":" << setw(2) << setfill('0') << day
		<< ":" << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << min;

	return os;
}


// Function : ofstream& operator <<(ofstream& os, const Timer::TimeSet& time)
// Description : Timer::TimeSet ����ü�� ofstream << �����ε�
//				���Ŀ� �°Բ� ��������ϵ��� ��
// Created : 2019/06/03 02:10 am
// Author : ������
ofstream& operator << (ofstream& ofs, const Timer::TimeSet& time) {
	int year = time.year;
	int mon = time.month;
	int day = time.day;
	int hour = time.hour;
	int min = time.min;

	ofs << setw(4) << setfill('0') << year << ":" << setw(2) << setfill('0') << mon << ":" << setw(2) << setfill('0') << day
		<< ":" << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << min;

	return ofs;
}


// Function : ifstream& operator <<(ifstream& ifs, const Timer::TimeSet& time)
// Description : Timer::TimeSet ����ü�� ifstream >> �����ε�
//				���Ŀ� �°Բ� ��������ϵ��� ��
// Created : 2019/06/03 02:10 am
// Author : ������
ifstream& operator >> (ifstream& ifs, Timer::TimeSet& time) {
	string tmp;

	getline(ifs, tmp, ':');
	time.year = stoi(tmp);
	getline(ifs, tmp, ':');
	time.month = stoi(tmp);
	getline(ifs, tmp, ':');
	time.day = stoi(tmp);
	getline(ifs, tmp, ':');
	time.hour = stoi(tmp);
	ifs >> tmp;
	time.min = stoi(tmp);

	return ifs;
}


// Function : istream& operator <<(istream& is, const Timer::TimeSet& time)
// Description : Timer::TimeSet ����ü�� istream >> �����ε�
//				���Ŀ� �°Բ� �����Է� �޵��� ��
// Created : 2019/06/03 04:45 am
// Author : ������
istream& operator >> (istream& is, Timer::TimeSet& time) {
	string tmp;

	getline(is, tmp, ':');
	time.year = stoi(tmp);
	getline(is, tmp, ':');
	time.month = stoi(tmp);
	getline(is, tmp, ':');
	time.day = stoi(tmp);
	getline(is, tmp, ':');
	time.hour = stoi(tmp);
	is >> tmp;
	time.min = stoi(tmp);

	return is;
}

bool Timer::TimeSet::operator == (const TimeSet& oth) {
	if (year != oth.year) return false;
	if (month != oth.month) return false;
	if (day != oth.day) return false;
	if (hour != oth.hour) return false;
	if (min != oth.min) return false;
	return true;
}