//��ǰ���� ����

#include<iostream>
#include<string>
#include"object.h"
#include"Manager.h"

maplist a;


//�ֹ����� ��ǰ �Է¹ޱ� 
void Order::getOrder(string name, int count) {
	int num;
	int getcash;
	string cardnum;
	string answer;

	while (1) {

		cout << "�ֹ����� �޴� �̸��� �����Է� : ";
		cin >> name;
		cin >> count;
		if (a.menu.find(name) == a.menu.end()) {
			cout << "-------- Error --------" << endl;
			cout << "�ش� ǰ���� �������� �ʽ��ϴ�." << endl;
			break;
		}
		cout << " " << endl;
		//���� or ī�� ������� ���� 
		cout << "���� ���" << endl;
		cout << "----------" << endl;
		cout << "1. ����" << endl;
		cout << "2. ī��" << endl;
		cout << "�Է� : ";
		cin >> num;

		//���ݰ���
		if (num == 1) {
			cout << "���� : " << a.menu[name] * count << endl;
			cout << "���� �ݾ� : ";
			cin >> getcash;
			if (getcash < (a.menu[name] * count)) { //�Է±ݾ��� ���ݺ��� ���� ���
				cout << "�Է��Ͻ� �ݾ��� ���ݺ��� �����ϴ�." << endl;
				break;
			}
			cout << "�Ž����� : " << getcash - (a.menu[name] * count) << "��" << endl;
			cout << "- - - - �� �� �� �� - - - -" << endl;
			sum->total += (a.menu[name] * count); //������Ȳ Ȯ���� ���� �ݾ����� 
		}
		//ī�����
		else if (num == 2) {
			int money;
			cout << "���� : " << a.menu[name] * count << endl;
			cout << "ī���ȣ �Է� : ";
			cin >> cardnum;
			cout << "���� �ݾ� �Է� : ";
			cin >> money;
			if (money < (a.menu[name] * count)) { //�Է±ݾ��� ���ݺ��� ���� ���
				cout << "�Է��Ͻ� �ݾ��� ���ݺ��� �����ϴ�." << endl;
				break;
			}
			cout << "ī���ȣ" << cardnum << " " << money << "��" << "���οϷ� !!" << endl;
			sum->total += (a.menu[name] * count); //������Ȳ Ȯ���� ���� �ݾ����� 
		}
		cout << "�߰� �ֹ� ����(y/n) : ";
		cin >> answer;
		if (answer == "n") {
			break;
		}
	}

}

//AdminMode������ ��ǰ �߰�
void Admin::AddObject(string name, int price) {

	a.menu.insert(make_pair(name, price));
}

//AdminMode������ ��ǰ ���� 
void Admin::DeleteObject(string name) {
	a.menu.erase(name);
}

//���� ��ϵǾ��ִ� ��ǰ Ȯ�� 
void Show::ShowObject() {
	cout << "========Menu List============" << endl;
	for (a.it = a.menu.begin(); a.it != a.menu.end(); a.it++) {
		cout << a.it->first << " " << a.it->second << endl;
	}
	cout << "=============================" << endl;
}