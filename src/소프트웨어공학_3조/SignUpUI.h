#pragma once
#include <iostream>
#include <string>
#include "SignUp.h"
using namespace std;

// Class : SignUpUI
// Description : SignUp boundary Ŭ����
// Created : 2019/06/03 02:00pm
// Author : ������
//
// Revision :
//	     1. When & Who : 
//         What : 

class SignUpUI {
public:
	void inputSignUpInformation(ifstream &in_fp, ofstream &out_fp, SignUp &signUp);
};