#include "Withdraw.h"



// Function : string showWithdrawal()
// description : ���� �α����� ����� ȸ��Ż�� �� ��� ����Ǵ� �Լ�
// parameter : None
// Return Value: string ID
// Revisions :
//	1.	When & Who : 2019/06/05 08:08 pm by ������
//		What : ȸ��Ż�� �� ��� ��Ͽ��� �ش� ��� �����ϴ� �Լ� �߰� �ۼ�
//	2.	When & Who : 2019/06/05 09:02 pm by ������
//		What : ���� ���� ����
string Withdraw::showWithdrawal(){
	int ticketID=0;
	string buyerID;
	string id;
	MemberManager *memberManager = MemberManager::getInstance();
	TicketManager *ticket = TicketManager::getInstance();
	Member *m=memberManager->getCurrentMemberPtr();
	
	if (m->getUserType() == 1){
		//sellerTicketNum = ((Seller*)m)->getSellersTicketList().size();
		vector <int>sellerTicketList = ((Seller*)m)->getSellersTicketList();
		for (vector<int>::iterator iter = sellerTicketList.begin(); iter != sellerTicketList.end();iter++){
			ticketID = *iter;
			buyerID=ticket->getTicket(ticketID).getBuyerID();
			if (buyerID == ""){
				return "";
			}
			
		}
		//return m->getID();
		id=m->getID();
	    memberManager->requestLogOut();
		memberManager->eraseMember(id);
		delete m;
	}
	
	else if (m->getUserType() == 0){
		id = m->getID();
		memberManager->requestLogOut();
		memberManager->eraseMember(id);
		delete m;
	}
	return id;
}