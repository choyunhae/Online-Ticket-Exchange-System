#pragma once
#include <fstream>
#include "SearchAuctionTicket.h"
using namespace std;

//---------------------------------------------------------------------------------------------
// class: SearchAuctionTicketUI
// Description: ��� ���� Ƽ�� �˻��� ���Ǵ� boudary Ŭ����
// Created:2019/06/03 03:50 am
// Author: ������
//---------------------------------------------------------------------------------------------
class SearchAuctionTicketUI {
public:
	void selectHomeTeam(ifstream&, ofstream&, SearchAuctionTicket);
	void participateAuction(ifstream& infile, ofstream& outfile, SearchAuctionTicket);
};

