#include "XML.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

void InsertNewUser(XMLitem& user, string name) {
	user[(const char*)user("Count")]["Name"] = name;
	user[(const char*)user("Count")]["Balance"] = 0;
	user("Count") = (int)user("Count") + 1;
}

void Deposit(XMLitem& user, int data) {
	user["Balance"] = (int)user["Balance"] + data;
}

void Withdraw(XMLitem& user, int data) {
	if((int)user["Balance"] < data) return false;
	user["Balance"] = (int)user["Balance"] - data;
	return true;
}
void main() {
	XML Bank;
	int select = 0;
	Bank["��������"]["User"]("Count") = 0;
	while (1) {
		cout << "1. ����� �߰� 2. �Ա� 3. ��� 0. ���� >>> ";
		cin >> select; 
		if (select == 0) break;
		else if (select == 1) {
			string name;
			cout << "�̸� >>> ";
			cin >> name;
			InsertNewUser(Bank["��������"]["User"], name);
		}
		else if (select == 2) {
			string key;
			int salary;
			cout << "����� ��ȣ >>> ";
			cin >> key;
			cout << "�Ա� �ݾ� >>> ";
			cin >> salary;
			Deposit(Bank["��������"]["User"][key], salary);
		}
		else if(select == 3) {
			string key;
			int salary;
			cout << "����� ��ȣ >>> ";
			cin >> key;
			cout << "��� �ݾ� >>> ";
			cin >> salary;
			Withdraw(Bank["��������"]["User"][key], salary);
		}
	}
	Bank["�������"]["User"]("Count") = 0;
	while (1) {
		cout << "1. ����� �߰� 2. �Ա� 3. ��� 0. ���� >>> ";
		cin >> select;
		if (select == 0) break;
		else if (select == 1) {
			string name;
			cout << "�̸� >>> ";
			cin >> name;
			InsertNewUser(Bank["�������"]["User"], name);
		}
		else if (select == 2) {
			string key;
			int salary;
			cout << "����� ��ȣ >>> ";
			cin >> key;
			cout << "�Ա� �ݾ� >>> ";
			cin >> salary;
			Deposit(Bank["�������"]["User"][key], salary);
		}
		else if (select == 3) {
			string key;
			int salary;
			cout << "����� ��ȣ >>> ";
			cin >> key;
			cout << "��� �ݾ� >>> ";
			cin >> salary;
			Withdraw(Bank["�������"]["User"][key], salary);
		}
	}
	cout << Bank.FullStr() << endl;


}