//물품관련 파일

#include<iostream>
#include<string>
#include"object.h"
#include"Manager.h"

maplist a;


//주문받은 물품 입력받기 
void Order::getOrder(string name, int count) {
	int num;
	int getcash;
	string cardnum;
	string answer;

	while (1) {

		cout << "주문받은 메뉴 이름과 수량입력 : ";
		cin >> name;
		cin >> count;
		if (a.menu.find(name) == a.menu.end()) {
			cout << "-------- Error --------" << endl;
			cout << "해당 품목이 존재하지 않습니다." << endl;
			break;
		}
		cout << " " << endl;
		//현금 or 카드 결제방식 선택 
		cout << "결제 방식" << endl;
		cout << "----------" << endl;
		cout << "1. 현금" << endl;
		cout << "2. 카드" << endl;
		cout << "입력 : ";
		cin >> num;

		//현금결제
		if (num == 1) {
			cout << "가격 : " << a.menu[name] * count << endl;
			cout << "받은 금액 : ";
			cin >> getcash;
			if (getcash < (a.menu[name] * count)) { //입력금액이 가격보다 적을 경우
				cout << "입력하신 금액이 가격보다 적습니다." << endl;
				break;
			}
			cout << "거스름돈 : " << getcash - (a.menu[name] * count) << "원" << endl;
			cout << "- - - - 결 제 완 료 - - - -" << endl;
			sum->total += (a.menu[name] * count); //매출현황 확인을 위한 금액저장 
		}
		//카드결제
		else if (num == 2) {
			int money;
			cout << "가격 : " << a.menu[name] * count << endl;
			cout << "카드번호 입력 : ";
			cin >> cardnum;
			cout << "결제 금액 입력 : ";
			cin >> money;
			if (money < (a.menu[name] * count)) { //입력금액이 가격보다 적을 경우
				cout << "입력하신 금액이 가격보다 적습니다." << endl;
				break;
			}
			cout << "카드번호" << cardnum << " " << money << "원" << "승인완료 !!" << endl;
			sum->total += (a.menu[name] * count); //매출현황 확인을 위한 금액저장 
		}
		cout << "추가 주문 여부(y/n) : ";
		cin >> answer;
		if (answer == "n") {
			break;
		}
	}

}

//AdminMode에서의 물품 추가
void Admin::AddObject(string name, int price) {

	a.menu.insert(make_pair(name, price));
}

//AdminMode에서의 물품 제거 
void Admin::DeleteObject(string name) {
	a.menu.erase(name);
}

//현재 등록되어있는 물품 확인 
void Show::ShowObject() {
	cout << "========Menu List============" << endl;
	for (a.it = a.menu.begin(); a.it != a.menu.end(); a.it++) {
		cout << a.it->first << " " << a.it->second << endl;
	}
	cout << "=============================" << endl;
}