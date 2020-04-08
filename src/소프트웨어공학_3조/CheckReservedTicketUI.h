#pragma once
#include <fstream>
#include <string>
#include "CheckReservedTicket.h"


// Class : CheckReservedTicketUI
// Description : use case.Check Reserved Ticket�� <<boundary>> Ŭ����
// Created : 2019/06/02 03:00 am
// Author : ������
// Revisions :
//	1.	When & Who : 2019/06/03 03:41 am by ������
//		What : fstream, string ��� �߰�
class CheckReservedTicketUI
{
public:
	~CheckReservedTicketUI();
	CheckReservedTicketUI();
	void startCheckReservedTicket(ifstream & in, ofstream & out);
};

