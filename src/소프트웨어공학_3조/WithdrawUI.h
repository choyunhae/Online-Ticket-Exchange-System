#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Member.h"
#include "Withdraw.h"
#include "TicketManager.h"
using namespace std;


//class : WithdrawUI
//description : ȸ��Ż��UI
//created : 2019/06/03 1:21am
// Author : ������

class WithdrawUI{

public:
	void clickWithdrawButton(ifstream &in_fp,ofstream &out_fp,Withdraw &withdraw);
};