#pragma once
#include <vector>
#include <utility>
#include "MemberManager.h"
#include "TicketManager.h"

using namespace std;

// Class : CheckReservedTicketUI
// Description : use case.Check Reserved Ticket�� <<control>> Ŭ����
// Created : 2019/06/02 03:40 am
// Author : ������
class CheckReservedTicket
{
public:
	~CheckReservedTicket();
	CheckReservedTicket();
	vector<pair<int, Ticket>> getReservedTicketList();
};

