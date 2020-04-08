#include "WithdrawUI.h"



//function : void clickWithdrawButton(ifstream &in_fp, ofstream &out_fp, Withdraw &withdraw);
//description : ȸ��Ż�� UI

void WithdrawUI::clickWithdrawButton(ifstream &in_fp, ofstream &out_fp, Withdraw &withdraw) {
	string id;

	id = withdraw.showWithdrawal();
	out_fp << "1.2 ȸ��Ż��" << endl;
	//out_fp << "> " << id << endl;
	if (id == "") {
		out_fp << "> ȸ��Ż�����" << endl;
	}
	else {
		out_fp << "> " << id << endl;
	}

}