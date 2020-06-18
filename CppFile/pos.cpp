#include<iostream>
#include<string>
#include"object.h"
#include"Manager.h"
using namespace std;

//Pos기 실행
void Start::Run() {
	int menu=0;
	Order ord;
	AD ad;
	Calculator cal;
	string name;
	int count=0;

	while (1) { //시작 메뉴화면 
		cout << "===================" << endl;
		cout << "0. 관리자 모드" << endl;
		cout << "1. 주문 입력" << endl;
		cout << "2. 매출 현황" << endl;
		cout << "3. 프로그램 종료" << endl;
		cout << "===================" << endl;

		cout << "메뉴 번호 : ";
		cin >> menu;

		switch (menu) {
		case 0:
			ad.adminmode(); //관리자모드 호출 
			break;
		case 1:
			ord.getOrder(name,count); //주문입력 호출
			break;
		case 2:
			ord.sum->getMoney(); //매출현황 호출 
			break;
		case 3:
			return; break;
		default:
			cout << "입력이 바르지 않습니다." << endl;
			break;
		}
	}
	delete ord.sum;
}