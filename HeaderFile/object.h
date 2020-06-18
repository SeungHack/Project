#pragma once
#include<string>
#include<map>
#include"Manager.h"
using namespace std;

//map ����ü ����
struct maplist {
	map<string, int> menu;
	map<string, int>::iterator it;
};


//��ǰ����
class Object {
public:
	string name; //��ǰ�� �̸�
	int price; //��ǰ�� ����
};

//��ǰ�ֹ�
class Order : public Object {
public:	
	Calculator* sum = new Calculator;
	int count;
	void getOrder(string name, int count);
};

//��ǰ �߰� �� ����
class Admin : public Object {
public:
	void AddObject(string name, int prcie); //��ǰ�߰�
	void DeleteObject(string name); //��ǰ���� 

};

//��ǰ Ȯ��
class Show : public Object {
public:
	void ShowObject();
};