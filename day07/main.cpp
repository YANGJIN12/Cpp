#include "../../headers/ConsoleSystem.h"

// 함수의 사용법 > 함수이름(인자값)
// 클래스의 함수 사용법 > 클래스변수이름.함수이름(인자값)
// 일반 변수를 연산자로 이용하듯이 사용할 수 없을까?
// a.plus(b) > a + b
// 연산자 오버로딩 > 클래스의 함수를 연산자를 이용하여 호출하도록 만드는 기법

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

// 연산자 종류
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

// 숫자를 저장하는 클래스를 만들고
// 숫자를 + 로 덧셈, -로 뺄셈, *, /로 곱셈 나눗셈을 하고
// =으로 값을 대입하도록 만드시오
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

// [] > 인덱스 > 한개의 데이터를 받아와서 처리하는 구조
//class A {
//public:
//	void operator[](int n){}
//	void operator[](const char* str){}
//};

// () > 호출 > 호출연산자 > 함수 호출을 기반
//class A {
//public:
//	void operator()(){}
//	void operator()(int n){}
//	void operator()(int n, int m){}
//};

// static_cast > 형 변환 연산자
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

//ConsoleSystem 클래스에 ()연산자를 오버로딩하여
// 위치를 넣으면 위치변경을, 색깔을 넣으면 색상 변경을 하는 기능을 동작하로독 만드시오
// ConsoleSystem(3,4), ConsoleSystem(Color::White)

void main() {
	ConsoleSystem sys("ConsoleTitle");
	map<int, string> menu;
	int select = 0;
	menu.insert(pair<int, string>(1, "1. 첫번째 내용"));
	menu.insert(pair<int, string>(1, "2. 첫번째 내용"));
	menu.insert(pair<int, string>(1, "3. 첫번째 내용"));
	menu.insert(pair<int, string>(1, "4. 첫번째 내용"));
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



