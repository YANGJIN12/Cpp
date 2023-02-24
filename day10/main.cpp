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
	Bank["신한은행"]["User"]("Count") = 0;
	while (1) {
		cout << "1. 사용자 추가 2. 입금 3. 출금 0. 종료 >>> ";
		cin >> select; 
		if (select == 0) break;
		else if (select == 1) {
			string name;
			cout << "이름 >>> ";
			cin >> name;
			InsertNewUser(Bank["신한은행"]["User"], name);
		}
		else if (select == 2) {
			string key;
			int salary;
			cout << "사용자 번호 >>> ";
			cin >> key;
			cout << "입금 금액 >>> ";
			cin >> salary;
			Deposit(Bank["신한은행"]["User"][key], salary);
		}
		else if(select == 3) {
			string key;
			int salary;
			cout << "사용자 번호 >>> ";
			cin >> key;
			cout << "출금 금액 >>> ";
			cin >> salary;
			Withdraw(Bank["신한은행"]["User"][key], salary);
		}
	}
	Bank["기업은행"]["User"]("Count") = 0;
	while (1) {
		cout << "1. 사용자 추가 2. 입금 3. 출금 0. 종료 >>> ";
		cin >> select;
		if (select == 0) break;
		else if (select == 1) {
			string name;
			cout << "이름 >>> ";
			cin >> name;
			InsertNewUser(Bank["기업은행"]["User"], name);
		}
		else if (select == 2) {
			string key;
			int salary;
			cout << "사용자 번호 >>> ";
			cin >> key;
			cout << "입금 금액 >>> ";
			cin >> salary;
			Deposit(Bank["기업은행"]["User"][key], salary);
		}
		else if (select == 3) {
			string key;
			int salary;
			cout << "사용자 번호 >>> ";
			cin >> key;
			cout << "출금 금액 >>> ";
			cin >> salary;
			Withdraw(Bank["기업은행"]["User"][key], salary);
		}
	}
	cout << Bank.FullStr() << endl;


}