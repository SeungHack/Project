#define Admin_PWD "0000"
#include<iostream>
#include<string>
#include"object.h"
#include"Manager.h"
using namespace std;

//�����ڸ��
void AD::adminmode() {
	Admin list;
	Show sh;
	string pwd;
	int num;
	string name;
	int price=0;

	//�����ڸ�� ���Խ� ��й�ȣ Ȯ��
	cout << "��й�ȣ�� �Է� : ";
	cin >> pwd;
	if (pwd != Admin_PWD) {
		cout << "��й�ȣ�� ��ġ���� �ʽ��ϴ�." << endl;
		return;
	}
	//�����ڸ�� �޴�
	while (1) {
		cout << " 0. ���� ȭ��" << endl;
		cout << " 1. ��ǰ �߰�" << endl;
		cout << " 2. ��ǰ ����" << endl;
		cout << " 3. ��ǰ Ȯ��" << endl;
		cout << "��ȣ �Է� : ";
		cin >> num;

		switch (num) {
		case 0:
			return; break;
		case 1:
			cout << "�߰��� ��ǰ�� ���� �Է� : ";
			cin >> name >> price;
			list.AddObject(name,price); //Map �����̳ʿ��� ��ǰ �߰� 
			break;
		case 2:
			cout << "������ ��ǰ �Է� : ";
			cin >> name;
			list.DeleteObject(name); //Map �����̳ʿ��� ��ǰ ����
			cout << name << "�����Ϸ�!!" << endl;
			break;
		case 3:
			sh.ShowObject(); //Map�� �ִ� ��ǰ Ȯ��
			break;
		default :
				cout << "�Է��� �ٸ��� �ʽ��ϴ�." << endl;
				break;
		}

	}
}