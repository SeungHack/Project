#include<iostream>
#include<string>
#include"object.h"
#include"Manager.h"
using namespace std;

//Pos�� ����
void Start::Run() {
	int menu=0;
	Order ord;
	AD ad;
	Calculator cal;
	string name;
	int count=0;

	while (1) { //���� �޴�ȭ�� 
		cout << "===================" << endl;
		cout << "0. ������ ���" << endl;
		cout << "1. �ֹ� �Է�" << endl;
		cout << "2. ���� ��Ȳ" << endl;
		cout << "3. ���α׷� ����" << endl;
		cout << "===================" << endl;

		cout << "�޴� ��ȣ : ";
		cin >> menu;

		switch (menu) {
		case 0:
			ad.adminmode(); //�����ڸ�� ȣ�� 
			break;
		case 1:
			ord.getOrder(name,count); //�ֹ��Է� ȣ��
			break;
		case 2:
			ord.sum->getMoney(); //������Ȳ ȣ�� 
			break;
		case 3:
			return; break;
		default:
			cout << "�Է��� �ٸ��� �ʽ��ϴ�." << endl;
			break;
		}
	}
	delete ord.sum;
}