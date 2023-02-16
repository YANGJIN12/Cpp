//#include <iostream>
//#include <functional>
//#include <windows.h>
//#include <vector>
//#include <list>
//using namespace std;


// ���� �Լ� > ��Ӱ��迡�� �������̵��� �Լ��� 
//			   �θ� Ŭ������ ���۷���(������)���� ȣ��� ������ ������� �θ��� �����Ͱ� ȣ��
//			   �װ��� �ڽ��� ������ ȣ��ǵ��� ����� ���

//class A {
//public:
//	virtual void Act() {
//		cout << " A Act " << endl;
//	}
//};
//
//class B : public A {
//public:
//	virtual void Act() {
//		cout << " B Act " << endl;
//	}
//};
//
//class C : public A {
//public:
//	virtual void Act() {
//		cout << " C Act " << endl;
//	}
//};
//
//void main() {
//	A a; B b; C c;
//	a.Act(); b.Act(); c.Act();
//	A* p;
//	p = &a;
//	p->Act();
//	p = &b;
//	p->Act();
//	p = &c;
//	p->Act();
//
//}

//class Obj {
//public: virtual void Act() = 0; // ���� ���� �Լ� > �ش��ϴ� �Լ��� '������' �ڽ� Ŭ�������� �������̵� �ؾ���
//};
//
//class A : public Obj{
//public: void Act() { cout << "A" << endl; }
//};
//
//class B : public Obj {
//public: void Act() { cout << "B" << endl; }
//};
//
//class C : public Obj {
//public: void Act() { cout << "C" << endl; }
//};
//
//class D : public Obj {
//public: void Act() { cout << "D" << endl; }
//};
//
//void main() {
//	list<Obj*> a;
//	a.push_back(new A);
//	a.push_back(new B);
//	a.push_back(new C);
//	for (auto& iter : a) {
//		iter->Act();
//		delete iter;
//	}
//
//}

//class A {
//public:
//	 A() {}
//	 virtual ~A() { cout << "A Closer " << endl; }
//};
//class B : public A {
//public:
//	 B(){}
//	 virtual ~B(){ cout << " B Closer " << endl; }
//};
//
//void main() {
//	A a; B b; // a,b
//	A* p = new B;
//	delete p; // p
//}

// Game
// ������

//class Unit { // Interface
//public:
//	virtual void AI() = 0;
//	virtual void Render() = 0;
//	virtual void Droprate() = 0;
//};

// Book Ŭ������ �θ�� ����ÿ�
// BestSeller Ŭ������ �ڽ����� ����ÿ�
// StadySeller Ŭ������ �ڽ����� ����ÿ�
// BookŬ���� ������ �迭�� BestSeller 2��, StadySeller 2��, Book 2���� �־ �����Ͻÿ�

//class Book {
//public:
//	virtual void Show() { cout << "Book" << endl; }
//};
//
//class BestSeller : public Book {
//public:
//	virtual void Show() { cout << "BestSeller Book" << endl; }
//};
//
//class StadySeller : public Book {
//public:
//	virtual void Show() { cout << "StadySeller Book" << endl; }
//};
//
//void main() {
//	Book* arr[6] = { new Book, new Book, new BestSeller, new BestSeller, new StadySeller, new StadySeller };
//	for (Book* data : arr) {
//		data->Show();
//		delete data;
//	}
//}

#include "../../headers/ConsoleSystem.h"

class Object {
protected: 
	double x, y;
	string body;
	ConsoleSystem& sys;
public:
	virtual void Render() {
		SetConsoleTextAttribute(sys.Screen[sys.ScreenCurrent], 15);
		SetConsoleTextAttribute(sys.Screen[sys.ScreenCurrent], 15);
		SetConsoleTextAttribute(sys.Screen[sys.ScreenCurrent], 15);
		sys.Print(x,y,body);
	};
	virtual void AI() = 0;
public:
	Object(ConsoleSystem& sys, double x, double y, string body) :sys(sys), x(x), y(y), body(body){}
};

class MovementA : public Object {
private:
	bool isRight;
	double speed;
public:
	void AI() {
		if (isRight) {
			x += speed * sys.Delta();
			if (x > 80) isRight = false;
		}
		else {
			x -= speed * sys.Delta();
			if (x < 1) isRight = true;
		}
	}
public:
	MovementA(ConsoleSystem& sys, double x, double y, string body, double speed) :isRight(true), Object(sys, x, y, body), speed(speed){}
	
};

class MovementAC : public MovementA {
public:
	void Render() {
		SetConsoleTextAttribute(sys.Screen[sys.ScreenCurrent], 13);
		sys.Print(x, y, body);
	}
	MovementAC(ConsoleSystem& sys, double x, double y, string body, double speed) :MovementA(sys, x, y, body, speed){}
};
class MovementB : public Object {
private:
	bool isRight;
	bool isDown;
	double speed;
public:
	void AI() {
		if (isRight) {
			x += speed * sys.Delta();
			if (x > 40) isRight = false;
		}
		else {
			x -= speed * sys.Delta();
			if (x < 20) isRight = true;
		}
		if (isDown) {
			y += speed * sys.Delta();
			if (y > 40) isRight = false;
		}
		else {
			y -= speed * sys.Delta();
			if (y < 20) isRight = true;
		}
	}
public:
	MovementB(ConsoleSystem& sys, double x, double y, string body, double speed) :isRight(true), isDown(false), Object(sys, x, y, body), speed(speed) {}

};

class MovementBC : public MovementB {
public:
	void Render() {
		SetConsoleTextAttribute(sys.Screen[sys.ScreenCurrent], 14);
		sys.Print(x, y, body);
	}
public:
	MovementBC(ConsoleSystem& sys, double x, double y, string body, double speed) :MovementB(sys, x, y, body, speed) {}
};

class MovementC : public Object {
private:
	bool isDown;
	double speed;
public:
	void AI() {
		if (isDown) {
			y += speed * sys.Delta();
			if (y > 30) isDown = false;
		}
		else {
			y -= speed * sys.Delta();
			if (y < 1) isDown = true;
		}
	}
public:
	MovementC(ConsoleSystem& sys, double x, double y, string body, double speed) :isDown(true), Object(sys, x, y, body), speed(speed) {}

};

class MovementCC : public MovementC {
public:
	void Render() {
		SetConsoleTextAttribute(sys.Screen[sys.ScreenCurrent], 12);
		sys.Print(x, y, body);
	}
	MovementCC(ConsoleSystem& sys, double x, double y, string body, double speed) :MovementC(sys, x, y, body, speed){}
};



// �¿� 3�� �ӵ��� �̵��ϴ� ��ü
// �¿� 4�� �ӵ��� �̵��ϴ� ��ü
// ���� 3�� �ӵ��� �̵��ϴ� ��ü
// ���� 4�� �ӵ��� �̵��ϴ� ��ü
// �����¿� 3�� �ӵ��� �̵��ϴ� ��ü


void main() {
	ConsoleSystem sys("Console Application");
	list<Object*> objs;
	objs.push_back(new MovementA(sys, 10, 3, "��", 3));
	objs.push_back(new MovementAC(sys, 10, 6, "�� ", 4));
	objs.push_back(new MovementB(sys, 10, 5, "��", 3));
	objs.push_back(new MovementBC(sys, 13, 5, "��", 3));
	objs.push_back(new MovementC(sys, 15, 5, "��", 4));
	objs.push_back(new MovementCC(sys, 13, 5, "��", 3));
	


	while (!(GetAsyncKeyState(VK_SPACE) & 0x0001)) {
		for (auto& obj : objs) {
			obj->AI();
			obj->Render();
		}
		sys.Flipping();
	}
	for (auto& obj : objs) {
		delete obj;
	}
}