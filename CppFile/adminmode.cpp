#define Admin_PWD "0000"
#include<iostream>
#include<string>
#include"object.h"
#include"Manager.h"
using namespace std;

//관리자모드
void AD::adminmode() {
	Admin list;
	Show sh;
	string pwd;
	int num;
	string name;
	int price=0;

	//관리자모드 진입시 비밀번호 확인
	cout << "비밀번호를 입력 : ";
	cin >> pwd;
	if (pwd != Admin_PWD) {
		cout << "비밀번호가 일치하지 않습니다." << endl;
		return;
	}
	//관리자모드 메뉴
	while (1) {
		cout << " 0. 이전 화면" << endl;
		cout << " 1. 물품 추가" << endl;
		cout << " 2. 물품 삭제" << endl;
		cout << " 3. 물품 확인" << endl;
		cout << "번호 입력 : ";
		cin >> num;

		switch (num) {
		case 0:
			return; break;
		case 1:
			cout << "추가할 물품과 가격 입력 : ";
			cin >> name >> price;
			list.AddObject(name,price); //Map 컨테이너에서 물품 추가 
			break;
		case 2:
			cout << "제거할 물품 입력 : ";
			cin >> name;
			list.DeleteObject(name); //Map 컨테이너에서 물품 삭제
			cout << name << "삭제완료!!" << endl;
			break;
		case 3:
			sh.ShowObject(); //Map에 있는 물품 확인
			break;
		default :
				cout << "입력이 바르지 않습니다." << endl;
				break;
		}

	}
}