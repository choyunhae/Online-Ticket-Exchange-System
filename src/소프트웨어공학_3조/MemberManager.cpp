#include "MemberManager.h"

MemberManager*MemberManager::memberManagerInstance = nullptr;
MemberManager::MemberManager(){}
// Function : static MemberManager *getInstance() 
// description : MemberManager��ü�� �ѹ��� �����ǰ� �� ���Ŀ��� ������ ��ü ��ȯ
MemberManager*MemberManager::getInstance(){
	if (memberManagerInstance == NULL){
		memberManagerInstance = new MemberManager();
	}
	return memberManagerInstance;
}


//Function : void requestLogIn(string inputID,string inputPassword)
// description : �α����� ó���Ѵ�. ���� ���� ID�̰ų� ��й�ȣ�� Ʋ�� ��쿣 false�� �����Ѵ�.
//				 ���������� �α��ν� logInMembers�� �߰��Ѵ�.
// parameter : string inputID - �α��� �õ��ϴ� ID
//			   string inputPasswd - �α��� �õ��ϴ� ��й�ȣ
// Return Value: true - �α��� ������
//				 false - �α��� ���н� 
bool MemberManager::requestLogIn(string inputID, string inputPasswd) {
	if (members.find(inputID) == members.end()) return false;
	Member* member = members[inputID];
	string memPasswd = member->getPassword();
	if (inputPasswd != memPasswd) return false;
	
	member->setLogInState(true);
	logInMembers.push_back(member->getID());
	changeSession(member->getID());
	
	return true;
}

// Function : void requestLogOut();
// description : �α׾ƿ��� ó���Ѵ�. ���� ������ ����� �α׾ƿ� �ϴ� ��Ȳ�� ������ �����Ѵ�.
// parameter : None
// Return Value: None
void MemberManager::requestLogOut(){
	string curSessionID = getCurrentSessionID();
	Member* member = members[curSessionID];
	
	member->setLogInState(false);
	for (int i = 0; i < logInMembers.size(); i++) {
		string loginID = logInMembers[i];
		if (loginID == curSessionID) {
			logInMembers.erase(logInMembers.begin() + i);
			changeSession("");
			return;
		}
	}
}


//Function : void requestSignUp(string savedID, string savedPassword, string name, int identityNumber, int userType)
//description : ȸ������ ��û�Լ�
//revision: 
//1.when&who : 2019/06/03 02:29:pm
//what : requestSignUp �Ű����� �߰� �� ����

void MemberManager::requestSignUp(string savedID, string savedPassword, string name, int identityNumber, int userType){
	if (userType == 0) { //Buyer
		bool loginState = false;
		Buyer *newBuyer = new Buyer(userType, name, identityNumber, loginState, savedID, savedPassword);
		members.insert(make_pair(savedID, newBuyer));
	}
	else { //Seller
		bool loginState = false;
		Seller *newSeller = new Seller(userType, name, identityNumber, loginState, savedID, savedPassword);
		members.insert(make_pair(savedID, newSeller));
	}
}


// Function : void changeSession(string targetID);
// description : �Է¹��� ȸ�� id�� ������ ��ü�Ѵ�
//				login���� �ƴ� ȸ��id�� �־����� �ʴ´ٰ� ������
// parameter : string targetID - ������ ������ ID
// Return Value: None
void MemberManager::changeSession(string targetID) {
	currentSessionID = targetID;
}


// Function : string getCurrentSessionID()
// description : ���� ������ ID�� ��ȯ��
// parameter : None
// Return Value: currentSessionID
string MemberManager::getCurrentSessionID() {
	return currentSessionID;
}


// Function : void eraseMember(string ID)
// description : �ش� ID�� ����� ��� ��Ͽ��� ������
// parameter : string ID
// Return Value: None
void MemberManager::eraseMember(string ID) {
	members.erase(ID);
}


// Function : void reserveTicket(int ticketID, string buyerID)
// description : buyerID�� Ƽ�� ������ �޾� �ش� ���̾ ������ Ƽ�� ��Ͽ� Ƽ���� �߰�
// parameter : int ticketID - ������ Ƽ�� id
//				string buyerID - ������ id
// Return Value: None
void MemberManager::reserveTicket(int ticketID, string buyerID) {
	Member *member = members[buyerID];
	((Buyer*)member)->addBuyersTicketList(ticketID);
}

// Function : Member * MemberManager::getCurrentMemberPtr()
// description : ���� Ȱ��ȭ�� ������ ��� ������ ��ȯ
// parameter : None
// Return Value: Member * members[currentSessionID]
Member * MemberManager::getCurrentMemberPtr() {
	return members[currentSessionID];
}


// Function : deleteMembersTicket(int ticketID, string memberID)
// description : ���ڷ� ���� member�� Ƽ�� ��� �� ticketID�� �ش��ϴ� Ƽ���� ����
// parameter : int ticketID, string memberID
// Return Value: None
void MemberManager::deleteMembersTicket(int ticketID, string memberID) {
	Member* mem = members[memberID];
	mem->deleteTicket(ticketID);
}
