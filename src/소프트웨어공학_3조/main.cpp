#include <iostream>
#include <fstream>
#include <string>
#include "Timer.h"
//ȸ������
#include "SignUpUI.h"
#include "SignUp.h"
//Ƽ�ϵ��
#include "RegisterTicketUI.h"
#include "RegisterTicket.h"
//Ƽ�ϰ˻�
#include "SearchTicketUI.h"
#include "SearchTicket.h"
//����Ƽ��
#include "SearchAuctionTicketUI.h"
#include "SearchAuctionTicket.h"
//�α���
#include "LogInUI.h"
#include "LogIn.h"
//�α׾ƿ�
#include "LogOutUI.h"
#include "LogOut.h"
//ȸ��Ż��
#include "WithdrawUI.h"
#include "Withdraw.h"
//��� Ƽ�� Ȯ��
#include "CheckEnrolledTicketUI.h"
#include "CheckEnrolledTicket.h"
//���� ���� ��ȸ
#include "CheckReservedTicketUI.h"

#pragma warning(disable : 4996)
using namespace std;

//revision:
//1.when&who : 2019/06/03 02:52pm, ������
//what : signup ���� SignUpUI.h, SignUp.h include
//				void signUpInterface �Լ� �߰�
//				doTask�� signup �κ� ����
//2.when&who : 2019/06/03 03:01pm, ������
//what : registerticket ���� RegisterTickeUI.h, RegisterTicket.h include
//				void registerTicketInterface �Լ� �߰�
//				doTask�� registerticket �κ� ����
// 3. When & Who : 2019/06/03 07:38 pm ������
//	What: 1) ����ð������� �����ϰ� main������ ������ ��/��� �ϴ� �κ� ��� ����
//		  2) 5.1 ����ð� �����κ� �ۼ�
//4.when&who : 2019/06/03 08:17pm, ������
//what : searchticket ���� SearchTickeUI.h, SearchTicket.h include
//				void searchTicketInterface �Լ� �߰�
//				doTask�� searchticket �κ� ����
//5.when&who : 2019/06/03 08:49pm, ������
//what : reserveticket ���� void reserveTicketInterface �Լ� �߰�
//				doTask�� reserveticket �κ� ����
//6.When&who : 2019/06/03 12:55am, ������
//What : LogInUI,LogIn, LogOutUI,LogOut,WithdrawUI,Withdraw �Լ� �߰�
void doTask();

void signUpInterface(ifstream& in_fp, ofstream& out_fp);

void registerTicketInterface(ifstream& in_fp, ofstream& out_fp);

void searchTicketInterface(ifstream& in_fp, ofstream& out_fp);

void reserveTicketInterface(ifstream& in_fp, ofstream& out_fp);

void searchAuctionTicketInterface(ifstream& in_fp, ofstream& out_fp);
void participateAuctionInterface(ifstream& in_fp, ofstream& out_fp);
void LogInInterface(ifstream &in_fp, ofstream &out_fp);
void LogOutInterface(ifstream &in_fp, ofstream &out_fp);
void WithdrawInterface(ifstream &in_fp, ofstream &out_fp);
void startCheckEnrolledTicket(ifstream &in_fp, ofstream &out_fp);
void startCheckReservedTicket(ifstream & in_fp, ofstream & out_fp);
int main(void)
{

	doTask();

	return 0;
}

void doTask()
{
	Timer * timer = Timer::getInstance();

	// �޴� �Ľ�
	int menu_level_1 = 0, menu_level_2 = 0;


	bool is_program_exit = false;

	ifstream in_fp("input.txt");
	ofstream out_fp("output.txt");

	if (!in_fp.is_open())
	{
		out_fp << "Error : Can not open this file.." << endl;
		return;
	}

	while (!is_program_exit)
	{
		in_fp >> menu_level_1 >> menu_level_2;

		switch (menu_level_1)
		{
		case 1:
		{
			switch (menu_level_2)
			{
			case 1: // ȸ������
			{
				signUpInterface(in_fp, out_fp);
			}
			break;

			case 2:	// ȸ��Ż��
			{
				WithdrawInterface(in_fp, out_fp);
			}
			break;

			default:
				break;
			}
		}
		break;

		case 2:
		{
			switch (menu_level_2)
			{
			case 1:	// �α���
			{
				LogInInterface(in_fp, out_fp);
			}
			break;

			case 2: // �α׾ƿ�
			{
				LogOutInterface(in_fp, out_fp);
			}
			break;

			default:
				break;
			}
		}
		break;

		case 3:
		{
			switch (menu_level_2)
			{
			case 1: // �Ǹ�Ƽ�� ���
			{
				registerTicketInterface(in_fp, out_fp);
			}
			break;

			case 2: // ���Ƽ�� ��ȸ
			{

				startCheckEnrolledTicket(in_fp, out_fp);
			}
			break;

			default:
				break;
			}
		}
		break;

		case 4:
		{
			switch (menu_level_2)
			{
			case 1: // Ƽ�� �˻�
			{
				searchTicketInterface(in_fp, out_fp);
			}
			break;

			case 2: // Ƽ�� ����
			{
				reserveTicketInterface(in_fp, out_fp);
			}
			break;

			case 3: // ��� ���� Ƽ�� �˻�
			{
				searchAuctionTicketInterface(in_fp, out_fp);
			}
			break;

			case 4: // ��� ����
			{
				participateAuctionInterface(in_fp, out_fp);
			}
			break;

			case 5: // ���� ���� ��ȸ
			{
				startCheckReservedTicket(in_fp, out_fp);
			}
			break;

			default:
				break;
			}
		}
		break;

		case 5:
		{
			switch (menu_level_2)
			{
			case 1: // ����ð� ����
			{
				//Timer::TimeSet curTime;
				//in_fp >> curTime;
				Timer::getInstance()->setCurrentTime(in_fp, out_fp);
				//out_fp << "> " << curTime << endl;
			}
			break;

			default:
				break;
			}
		}
		break;

		case 6:
		{
			switch (menu_level_2)
			{
			case 1: // session ����
			{
				out_fp << "6.1. session ����" << endl;

				string id;
				in_fp >> id;
				MemberManager::getInstance()->changeSession(id);
				out_fp << "> " << id << endl;
			}
			break;

			case 2: // guest session���� ����
			{
				out_fp << "6.2. guest session���� ����" << endl;
				MemberManager::getInstance()->changeSession("guest");
			}
			break;

			default:
				break;
			}
		}
		break;

		case 7:
		{
			switch (menu_level_2)
			{
			case 1:
				is_program_exit = true;
				out_fp << "7.1. ����" << endl;
				break;

			default:
				break;
			}
		}
		break;

		default:
			break;
		}
		out_fp << endl;
	}

	in_fp.close();
	out_fp.close();
}


void signUpInterface(ifstream& in_fp, ofstream& out_fp) {
	SignUpUI signUpUI;
	SignUp signUp;
	signUpUI.inputSignUpInformation(in_fp, out_fp, signUp);
}

void registerTicketInterface(ifstream& in_fp, ofstream& out_fp) {
	RegisterTicketUI registerTicketUI;
	RegisterTicket registerTicket;
	registerTicketUI.inputTicketInformationToRegister(in_fp, out_fp, registerTicket);
}

void searchTicketInterface(ifstream& in_fp, ofstream& out_fp) {
	SearchTicketUI searchTicketUI;
	SearchTicket searchTicket;
	searchTicketUI.selectHomeTeamToTicketList(in_fp, out_fp, searchTicket);
}

void reserveTicketInterface(ifstream& in_fp, ofstream& out_fp) {
	SearchTicketUI searchTicketUI;
	SearchTicket searchTicket;
	searchTicketUI.selectTicketToReserve(in_fp, out_fp, searchTicket);
}
void searchAuctionTicketInterface(ifstream& in_fp, ofstream& out_fp) {
	SearchAuctionTicketUI searchAuctionTicketUI;
	SearchAuctionTicket searchAuctionTicket;
	searchAuctionTicketUI.selectHomeTeam(in_fp, out_fp, searchAuctionTicket);
}
void participateAuctionInterface(ifstream& in_fp, ofstream& out_fp) {
	SearchAuctionTicketUI searchAuctionTicketUI;
	SearchAuctionTicket searchAuctionTicket;
	searchAuctionTicketUI.participateAuction(in_fp, out_fp, searchAuctionTicket);
}
void LogInInterface(ifstream &in_fp, ofstream &out_fp) {

	LogInUI logInUI;
	LogIn logIn;
	logInUI.inputLogInInformation(in_fp, out_fp, logIn);
}
void LogOutInterface(ifstream &in_fp, ofstream &out_fp) {
	LogOutUI logOutUI;
	LogOut logOut;
	logOutUI.clickLogOutButton(in_fp, out_fp, logOut);
}
void WithdrawInterface(ifstream &in_fp, ofstream &out_fp) {
	WithdrawUI withdrawUI;
	Withdraw withdraw;
	withdrawUI.clickWithdrawButton(in_fp, out_fp, withdraw);
}

void startCheckEnrolledTicket(ifstream &in_fp, ofstream &out_fp) {
	CheckEnrolledTicketUI checkEnrolledTicketUI;
	checkEnrolledTicketUI.startCheckEnrolledTicket(in_fp, out_fp);
}

void startCheckReservedTicket(ifstream &in_fp, ofstream &out_fp) {
	CheckReservedTicketUI checkReservedTicketUI;
	checkReservedTicketUI.startCheckReservedTicket(in_fp, out_fp);
}