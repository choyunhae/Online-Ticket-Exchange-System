# Online-Ticket-Exchange-System


소프트웨어공학 프로젝트
과제3: detailed design & implementation
– 온라인 티켓 매매시스템
3조
1. 팀원 간 역할 분담

이름
역할
박형준
- 코드 작성 : CheckReservedTicket.h, CheckReservedTicket.cpp/ Timer.h, Timer.cpp(TimeSet, 현재 시간 설정, 남은 시간 계산)
- 테스트 : 1년 지난 티켓 자동 삭제
- 다이어그램 : Check Reserved Ticket 시퀀스, 클래스 다이어그램, Timer 클래스 다이어그램, End Auction 시퀀스 다이어그램 작성
정윤석
- 코드 작성 : Ticket 클래스/Auction Manager 클래스/Timer 클래스(endAuction(),  updateAuction(), deleteOneYearTickets())/MemberManager(세션 관련 기능) /SearchAuctionTicketUI, SearchAuctionTicket, ParticipateAuctionUI, ParticipateAuction
헤더, cpp 파일)
- 테스트 : 옥션 관련 기능(여러명의 셀러, 바이어가 있을 때 경매 참여 확인, 시간 설정시 낙찰, 유찰 확인, 시간의 흐름에 따른 티켓 검색과 조회 확인)
- 오류 : 코드 전반적인 버그 해결
- 다이어그램 : Ticket, AuctionManager 클래스 다이어그램 작성, SearchAuctionTicket, ParticipateAuction 시퀀스 다이어그램 작성
조윤해
- 코드 작성 : 로그인/로그아웃/회원탈퇴 .h,.cpp
- 다이어그램회원가입/로그인/로그아웃/회원탈퇴 클래스다이어그램, 시퀀스 다이어그램
- 테스트 : 로그인/로그아웃/세션변경
유지혁
- 코드 작성 : 티켓 매니저/checkEnrolledTicket .h, cpp
- 다이어그램 : checkEnrolledTIcket 클래스 및 시퀀스 다이어그램 
- 테스트 :　withdraw 테스트, 수정 
이지현
- 코드 작성 : Seller, Buyer, SignUp, SignUpUI, RegisterTicket, RegisterTicketUI, SearchTicket, SearchTicketUI 헤더, cpp 파일 작성
- 테스트 : 파일 입출력 예제 테스트, 등록한 티켓 여러 개일 때 조회 잘 되는지 확인, 그 외 오류 수정
- 다이어그램 : register ticket, search ticket, reserve ticket 시퀀스 다이어그램, 클래스 다이어그램 작성, buyer, seller 클래스 다이어그램 작성, 오류 수정
- 보고서 통합 및 정리
공통
- 코드 구현 방안 논의
- use case diagram, description 수정
- entity 클래스들 논의

2. Use case diagram

3. Use case description
3-1. Member Management(회원 관리)

(1) Sign-up

Actor Action
System Response
1. None
2. 가입에 필요한 필수 정보를 출력한다.
3. ID, password, 사용자 유형(판매자 or 구매자), 이름, 주민번호을 입력한다.
4. 회원가입 완료 메시지를 출력한다.


(2) Log-in

Actor Action
System Response
1. None
2. 입력된 ID와 Password 확인, 로그인 완료 메세지 출력한다.


(3) Log-out

Actor Action
System Response
1. None
2. 로그 아웃 메세지가 출력된다.


(4) Withdraw

Actor Action
System Response
1. None
2. 회원탈퇴 메시지를 출력한다.
Alternative Courses
2. (미판매 티켓이 있을 경우,) 탈퇴 처리를 중단하고 미판매 티켓으로 인해 회원 탈퇴 거부 메시지 출력

3-2. Ticket Dealing(티켓 거래)

(1) Register ticket

Actor Action
System Response
1. None
2. 판매 티켓의 필수적인 정보 목록을 출력한다.
3. 판매할 티켓의 희망 판매가격 및 경기정보(야구경기날짜, 시각, 홈팀, 어웨이팀, 좌석위치(1~100행 및 1~100열)), limited-time auction 여부를 입력한다.
4. 티켓 등록을 완료 메시지를 출력한다.
Alternative Courses
4. (티켓의 경기 시작까지 2일 이상 남지 않았을 경우,) 티켓 등록에 실패했다는 메시지를 출력한다.


(2) Search ticket

Actor Action
System Response
1. None
2. 홈팀 목록을 출력한다.
3. 홈팀을 선택한 뒤, 검색을 요청한다.
4. 예약 가능한 티켓을 경기날짜 및 시각이 빠른 순서대로 정렬하여 희망판매가격, 야구경기날짜, 시각, 홈팀, 어웨이팀, 좌석위치를 출력한다.
Extensions
After step 4, 선택한 티켓을 예약한다.


(3) Search auction ticket

Actor Action
System Response
1. None
2. 홈 팀의 리스트를 보여준다.
3. 홈팀을 선택한다.
4. 선택한 홈팀의 경매 중인 티켓 리스트를 경기날짜 및 시각이 빠른 티켓부터 정렬하여 야구경기날짜, 시각, 홈팀, 어웨이팀, 좌석위치, 마감까지 남은 시간을 보여준다.
Extensions
After step 4, 원하는 티켓을 선택하고 입찰 금액을 입력하여 경매에 참여한다(Participate auction)


(4) End Auction

Actor Action
System Response
1. 현재시각을 입력하여 경매 중인 티켓 중 경기 시작 시각이 6시간이하로 남은 티켓을 요청
2. 해당 티켓 목록 출력
3. 티켓의 경매 결과 요청
4. 참여자가 있으면 낙찰시킨다
Alternative Coureses
4. 참여자가 없으면 유찰시킨다

 
3-3. Ticket Management(티켓 관리)

(1) Check enrolled ticket

Actor Action
System Response
1. None
2. 등록한 티켓의 희망판매가격, 야구경기날짜, 시각, 홈팀, 어웨이팀, 좌석위치, limited-time auction선택여부, 판매여부를 경기날짜 및 시각이 빠른 티켓부터 정렬해서 출력


(2) Delete ticket automatically

Actor Action
System Response
1. 현재시각을 입력하고 등록한지 1년이 지난 티켓 목록 요청
2. 해당 티켓의 목록 출력
3. 목록의 티켓 등록 삭제 요청
4. None


(3) Check reserved ticket

Actor Action
System Response
1. None
2. 예매한 티켓목록을 경기날짜 및 시각이 빠른 순서로 정렬해서 구매가격, 경기날짜, 시각, 홈팀, 어웨이팀, 좌석위치를 출력한다.

<class diagram>
![class통합](https://user-images.githubusercontent.com/54641007/78766192-eb362800-79c3-11ea-8f80-1bb49954ae2f.jpg)


