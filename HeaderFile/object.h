#pragma once
#include<string>
#include<map>
#include"Manager.h"
using namespace std;

//map 구조체 생성
struct maplist {
	map<string, int> menu;
	map<string, int>::iterator it;
};


//물품관리
class Object {
public:
	string name; //물품의 이름
	int price; //물품의 가격
};

//물품주문
class Order : public Object {
public:	
	Calculator* sum = new Calculator;
	int count;
	void getOrder(string name, int count);
};

//물품 추가 및 제거
class Admin : public Object {
public:
	void AddObject(string name, int prcie); //물품추가
	void DeleteObject(string name); //물품제거 

};

//물품 확인
class Show : public Object {
public:
	void ShowObject();
};