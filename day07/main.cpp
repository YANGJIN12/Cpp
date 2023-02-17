#include "../../headers/ConsoleSystem.h"

// �Լ��� ���� > �Լ��̸�(���ڰ�)
// Ŭ������ �Լ� ���� > Ŭ���������̸�.�Լ��̸�(���ڰ�)
// �Ϲ� ������ �����ڷ� �̿��ϵ��� ����� �� ������?
// a.plus(b) > a + b
// ������ �����ε� > Ŭ������ �Լ��� �����ڸ� �̿��Ͽ� ȣ���ϵ��� ����� ���

//class A {
//private:
//	int number;
//public:
//	void operator=(int n) {
//		number = n;
//	}
//	void operator=(A& n) {
//		number = n.number;
//	}
//	void operator=(const char* n) {
//		number = atoi(n);
//	}
//public:
//	A(int number) :number(number){}
//
//};
//
//void main() {
//	A b(4);
//	b = 4; // b.operator=(4);
//}

//class Vector {
//private:
//	int* datas;
//	int size;
//public:
//	int& operator[](int index) {
//		return datas[index];
//	}
//public:
//	Vector(int size) :datas(new int[size]), size(size){}
//	~Vector() { delete datas; }
//};
//
//void main() {
//	Vector a(5);
//	a[0] = 5; // a.operator[](0) = 5;
//}

// ������ ����
// +,*,-,/,^,&,...
//class A {
//public:
//	void operator+(int n){}
//	void operator-(int n){}
//	void operator=(int n){}
//};
////void operator+(A* this, int n) {}
////void operator-(A* this, int n) {}
////void operator=(A* this, int n) {}
//void operator+(int n, A& data){}
//// 1 + a; > operator(int,A)
//void main() {
//	A a;
//	a + 1; a - 2; a = 3;
//	// a.operator+(1); a.operator-(1); a.operator=(1);
//	// operator+(a,1); operator-(a,2); operator=(a,3);
//	// operator+(A,int);
//}

// ���ڸ� �����ϴ� Ŭ������ �����
// ���ڸ� + �� ����, -�� ����, *, /�� ���� �������� �ϰ�
// =���� ���� �����ϵ��� ����ÿ�
//class Number {
//private:
//	int data;
//public:
//	Number operator+(int n) { return data + n;}
//	Number operator+(const Number& n) { return data + n.data; }
//	Number operator-(int n) { return data - n; }
//	Number operator-(const Number& n) { return data - n.data; }
//	Number operator*(int n) { return data * n; }
//	Number operator*(const Number& n) { return data * n.data; }
//	Number operator/(int n) { return data / n; }
//	Number operator/(const Number& n) { return data / n.data; }
//	Number& operator=(int n) { data = n; return *this; }
//	Number& operator=(const Number& n) { data = n.data; return *this; }
//public:
//	Number(int data) :data(data){}
//};
// !,++,--,~,*,->,...
//class A {
//public:
//	void operator++(){}
//	void operator++(int){}
//	void operator--() {}
//	void operator~() {}
//	void operator!(){}
//	void operator*(){}
//	A* operator->() { return this; }
//};
//void main() {
//	A a;
//	++a; a++; --a; ~a; !a; *a;
//	a->operator!();
//}
//void main() {
//	list<int> a;
//	auto f = a.begin();
//	*f; //iterator
//}

// [] > �ε��� > �Ѱ��� �����͸� �޾ƿͼ� ó���ϴ� ����
//class A {
//public:
//	void operator[](int n){}
//	void operator[](const char* str){}
//};

// () > ȣ�� > ȣ�⿬���� > �Լ� ȣ���� ���
//class A {
//public:
//	void operator()(){}
//	void operator()(int n){}
//	void operator()(int n, int m){}
//};

// static_cast > �� ��ȯ ������
//void main() {
//	cout << static_cast<int>(6.5) << endl;
//}

//class Number {
//private:
//	int number;
//public:
//	operator int() {
//		return number;
//	}
//public:
//	Number(int number) :number(number) {}
//};
//void main() {
//	Number a(5);
//	cout << a << endl;
//	cout.operator<<(a).operator<<(endl);
//}

//ConsoleSystem Ŭ������ ()�����ڸ� �����ε��Ͽ�
// ��ġ�� ������ ��ġ������, ������ ������ ���� ������ �ϴ� ����� �����Ϸε� ����ÿ�
// ConsoleSystem(3,4), ConsoleSystem(Color::White)

void main() {
	ConsoleSystem sys("ConsoleTitle");
	map<int, string> menu;
	int select = 0;
	menu.insert(pair<int, string>(1, "1. ù��° ����"));
	menu.insert(pair<int, string>(1, "2. ù��° ����"));
	menu.insert(pair<int, string>(1, "3. ù��° ����"));
	menu.insert(pair<int, string>(1, "4. ù��° ����"));
	while (!sys[Key::ESCAPE]) {
		for (auto& iter : menu) {
			sys
			(((select == iter.first) ? 2 : 0) + 3, 4)
				((select == iter.first) ? Color::LightRed : Color::LightWhite)
				<< iter.second.c_str();
		}
		if (sys[Key::UP]) select = (select - 1 < 0) ? 0 : (select - 1);
		if (sys[Key::DOWN]) select = (select + 1 > menu.size() - 1) ? menu.size() - 1 : (select + 1);
		sys.Flipping();
	}
}



