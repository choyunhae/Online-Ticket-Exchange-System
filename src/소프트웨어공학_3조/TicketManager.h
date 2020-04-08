#pragma once
#include <vector>
#include <string>
#include "Ticket.h"
#include "Timer.h"
#include "AuctionManager.h"

using namespace std;


//---------------------------------------------------------------------------------------------
// class: TicketManager
// Description: Ƽ�� ������ �����ϰ� �ϱ� ���� Ŭ����(?). Ƽ�ϵ��� Ƽ�� ����Ʈ�� �����ϸ� �ش� �������� sorting��
//				 Ƽ�������͸� ���� Ƽ�� ����Ʈ�� sorting�� ������ ���� sortList�� ��������
// Created: 2019/05/31 02:29 am
// Author: ������
// Revisions:
//	1. When & Who : 2019/05/31 02:30 am by ������
//		What: 1) sorting������ usecase���� �ٸ��� �ϴµ� �̸� ��� ó�������� ���� �����غ� �� 
//			  2) Ƽ�� Ŭ�����κ��� detail����ü�� �ƴ� tickets�� �޴� ������ ����.
//			  3) set�Լ� �߰��ؾ���
//			  4) ���� �ð��� Ÿ�̸ӷκ��� �޾ƿ�
//			  5) tickets����Ʈ�� pair�� �ƴ� ticket �����͸� ������ ������ ����
//  2. When & Who : 2019/06/02 09:03 pm by ������
//		What: 1) ���� �����ڰ� ���� ���ְ� ������ �ȵǾ�����
//				��ī���� ��Ȳ�� ���� ������ ������.
//			  2) sortLists�� setter�� �������̽����� �������־���
//				���� �и� �̾Ƴ��� string Ȥ�� vector<int>�� ���ڷ� �޾� set�ϰԲ� ����
//			  3) (2.2)�� ����
//				(1) setTicketListToSearchTicket(string)
//				(2) setTicketListToCheckReservedTicket(vector<Ticket*>)
//				(3) getDefaultList()
//				(4) setHometeamAuctionTicketToSortList(string)
//			    ���� 4�� �Լ��� ����
//			  *4) ��� ���� Ƽ���� ���� ������ ������ �ٲٴ� �Լ��� �ʿ���
//				�켱 winAuction()���� �̸� ����״µ� ���߿� �����ؾ��� ��
//			  5) �⺻ �����ڿ��� nextID�� 1�� �ʱ�ȭ�ϵ��� ��
//	3. When & Who : 2019/06/03 07:24 am by ������
//		What: 1) ��� Ƽ���� sortLists�� �����صδ� void setTicketList() �Լ� ����
//			  2) Ƽ��id, ����, buyerID�� ���ڷ� �޾� Ƽ�� ������ ������Ʈ�ϴ�
//				void reserveTicket(int, int, string) �Լ� ����(�����ε���)
//			  3) (3.2)�� ���� winAuction()�Լ� ����
//	4. When & Who : 2019/06/04 10:57 am by ������
//		What: 1) Ƽ�� �����Լ� void deleteTicket(int ticketID) �߰�
//5. When & Who : 2019/06/04 01:33pm, ������
//		What: 1) addNewTicket�� ����Ÿ�� ����
//---------------------------------------------------------------------------------------------


class TicketManager {
private:
	vector<Ticket*> tickets;
	vector<pair<int, Ticket>> sortLists;//�����ð��� int������
	int nextID;
	static TicketManager* ticketManager;//singleton

	TicketManager();//������
	TicketManager(const TicketManager& other);
	~TicketManager();
	Ticket* getTicketPointer(int);
	void sortList();
	void addTicketToSortedList(int, Ticket);
public:
	static TicketManager* getInstance();
	int addNewTicket(int, Timer::TimeSet, string, string, string, bool, string);
	void setTicketList();
	void setTicketList(string);
	void setTicketList(vector<int>);
	void setTicketList(string, vector<int>);
	void reserveTicket(int, string);
	void reserveTicket(int, int, string);
	void deleteTicket(int);
	vector<pair<int, Ticket>> getTicketList();
	Ticket getTicket(int);
}; 