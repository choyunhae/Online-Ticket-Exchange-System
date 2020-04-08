#pragma once
#include <iostream>
#include <string>
#include "RegisterTicket.h"
using namespace std;

// Class : RegisterTicketUI
// Description : RegisterTicket BoundaryŬ����
// Created : 2019/06/03 02:55pm
// Author : ������
//
// Revision :
//	     1. When & Who : 
//         What : 

class RegisterTicketUI {
public:
	void inputTicketInformationToRegister(ifstream &in_fp, ofstream &out_fp, RegisterTicket& registerTicket);
};