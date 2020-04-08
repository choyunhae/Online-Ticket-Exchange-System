#pragma once
#include "Ticket.h"


Ticket::BasicInfo::BasicInfo()
	:matchTime(Timer::TimeSet()), homeTeam(""), awayTeam(""), seatPosition("") {}

Ticket::Ticket()
	: ID(0), sellerPrice(0), buyerPrice(0), enrolledTime(Timer::TimeSet()), basicInfo(),
	limitedAuction(false), sellerID(""), buyerID("") {}


//---------------------------------------------------------------------------------------
// Function: Ticket::Ticket(�Ķ���ʹ� �Ʒ� ����)
// Description: Ticket�� ��� ����� �ʱ�ȭ�ϴ� ��������.
//				buyerID�� �Ķ���ͷ� ���� �ʰ� empty string���� �ʱ�ȭ ��.
// Parameters:	int ID - Ƽ�� ID
//				int price - Ƽ�� ����
//				Timer::TimeSet matchTime - ��� ��¥, �ð�
//				string home - �ش� ����� Ȩ�� �̸�
//				string away - �ش� ����� ������� �̸� 
//				pair<int, int> seat - �¼� ��ġ
//				bool la - limited auction üũ ����
//				string sellerID - �Ǹ��� ID
// Return Value: None
//---------------------------------------------------------------------------------------
Ticket::Ticket(int ID, int sellerPrice, Timer::TimeSet enrolledTime, Timer::TimeSet matchTime, string home, string away,
	string seat, bool la, std::string sellerID)
	: ID(ID), sellerPrice(sellerPrice),buyerPrice(sellerPrice), enrolledTime(enrolledTime), basicInfo(matchTime, home, away, seat),
	limitedAuction(la), sellerID(sellerID), buyerID("") {}


//-------------------------------------------------------
// Function: void setBuyerID(string id)
// Description: Ƽ���� �����ھ��̵� ���� ������
// Parameters: string buyerID - ���ο� buyerID ��
// Return Value: None
//-------------------------------------------------------
void Ticket::setBuyerID(std::string buyerID) {
	this->buyerID = buyerID;
}


//-------------------------------------------------------
// Function: void setBuyerPrice(int price)
// Description: ���� ���� ���� ������ ������
// Parameters: int price - ���ο� Ƽ�� ����
// Return Value: None
//-------------------------------------------------------
void Ticket::setBuyerPrice(int price) {
	this->buyerPrice = price;
}


//----------------------------------------------------
// Function: int getID()
// Description: Ƽ���� ID ���� ��ȯ��
// Return Value: Ƽ���� ID
//----------------------------------------------------
int Ticket::getID() {
	return ID;
}


//----------------------------------------------------
// Function: int getBuyerPrice()
// Description: Ƽ���� ���� ���Ű����� ��ȯ��
// Return Value: Ƽ���� ���� ����
//----------------------------------------------------
int Ticket::getBuyerPrice() {
	return buyerPrice;
}


//----------------------------------------------------
// Function: int getSellerPrice()
// Description: Ƽ���� ����ǸŰ����� ��ȯ��
// Return Value: Ƽ���� ��� ����
//----------------------------------------------------
int Ticket::getSellerPrice() {
	return sellerPrice;
}


//----------------------------------------------------
// Function: Timer::TimeSet getMatchTime()
// Description: Ƽ���� ��� ��¥ + �ð��� ��ȯ��
// Return Value: Ƽ���� ��� ��¥ + �ð�
//----------------------------------------------------
Timer::TimeSet Ticket::getMatchTime() {
	return basicInfo.matchTime;
}


//----------------------------------------------------
// Function: string getHomeTeam()
// Description: �ش� ����� Ȩ���� ��ȯ
// Return Value: Ƽ���� Ȩ��
//----------------------------------------------------
std::string Ticket::getHomeTeam() {
	return basicInfo.homeTeam;
}


//----------------------------------------------------
// Function: string getBuyerID()
// Description: �ش� Ƽ���� ������ ���̵� ��ȯ��
// Return Value: Ƽ���� buyerID
//----------------------------------------------------
std::string Ticket::getBuyerID() {
	return buyerID;
}


//----------------------------------------------------
// Function: string getSellerID()
// Description: �ش� Ƽ���� �Ǹ��� ���̵� ��ȯ��
// Return Value: Ƽ���� sellerID
string Ticket::getSellerID() {
	return sellerID;
}


//----------------------------------------------------
// Function: bool getLimitedAuction()
// Description: �ش� Ƽ���� ���� ���θ� ��ȯ
// Return Value: Ƽ���� ���� ����
//----------------------------------------------------
bool Ticket::getLimitedAuction() {
	return limitedAuction;
}


//----------------------------------------------------
// Function: Timer::TimeSet getEnrolledTime()
// Description: �ش� Ƽ���� ��ϵ� �ð��� ��ȯ
// Return Value: ��ϵ� �ð�
//----------------------------------------------------
Timer::TimeSet Ticket::getEnrolledTime() {
	return enrolledTime;
}

//----------------------------------------------------
// Function: BasicInfo(Timer::TimeSet, string, string, pair<int, int>)
// Description: Ticket::BasicInfo ��Ʈ��Ʈ�� ������. ��� ����� �ʱ�ȭ�Ѵ�
// Parameters:	Timer::TimerSet time - ��� �ð�
//				string home - Ȩ��, string away - �������
//				pair<int, int> seat - �¼� ��ȣ(��, ��)
//----------------------------------------------------
Ticket::BasicInfo::BasicInfo(Timer::TimeSet time, string home, string away, string seat)
	:matchTime(time), homeTeam(home), awayTeam(away), seatPosition(seat) {}


//----------------------------------------------------
// Function: bool operator < (const TIcket &a, const Ticket &b)
// Description: TicketŬ������ < �����ڸ� �����ε�
// Return Value: a.ID < b.ID �ΰ�
//----------------------------------------------------
bool operator < (const Ticket &a, const Ticket &b) {
	return a.ID < b.ID;
}


//----------------------------------------------------
// Function: ostream& operator <<(ostream & os, const TIcket::BasicInfo &bi)
// Description: Ticket::BasicInfo ����ü�� ostream �����ε� �Լ�.
//				��� ���Ŀ� �°� ����ϵ��� ��
//----------------------------------------------------
ostream& operator << (ostream & os, const Ticket::BasicInfo &bi) {
	os << bi.matchTime<< ' ' << bi.homeTeam << ' ' << bi.awayTeam << ' ' << bi.seatPosition;
	return os;
}


//----------------------------------------------------
// Function: ostream& operator <<(ostream & os, const TIcket::BasicInfo &bi)
// Description: Ticket::BasicInfo ����ü�� ofstream �����ε� �Լ�.
//				��� ���Ŀ� �°� ����ϵ��� ��
//----------------------------------------------------
ofstream& operator << (ofstream& ofs, const Ticket::BasicInfo &bi) {
	ofs <<bi.matchTime<< ' ' << bi.homeTeam << ' ' << bi.awayTeam << ' ' << bi.seatPosition;
	return ofs;
}


//----------------------------------------------------
// Function: Ticket::BasicInfo getBasicInfo()
// Description: Ticket Ŭ������ basicinfo ����� ��ȯ
// Return Value: basicInfo
//----------------------------------------------------
Ticket::BasicInfo Ticket::getBasicInfo() {
	return basicInfo;
}


/*

//stream �����ε� �׽�Ʈ
int main() {
	Ticket ticket(1, 1000, Timer::TimeSet(2019, 5, 20, 18, 0), "home", "away", { 51, 3 }, true, "seller");
	Ticket::BasicInfo bi = ticket.getBasicInfo();
	ofstream outfile("out.txt");
	cout << bi;
	outfile << bi;
}
*/
