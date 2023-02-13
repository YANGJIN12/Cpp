// 절차 지향이란? > 속도를 중요시
// 객체 지향이란? > 속도와 편의성을 둘다 중요시
// 객체형 언어란? > 편의성을 중요시
// C언어에는 이미 데이터의 집합이 존재 > Structure
// 클래스는 왜 생겼는가? > 다른 언어와의 통일성을 위해서 
// C++의 구조체(Structure)와 클래스(Class)는 완전히 동일한 동작을 함

// 객체란 무엇인가? > 연관성이 있는 정보들을 하나로 묶어서 관리하는 것
// 그렇다면 클래스란 무엇인가? > 객체를 관리하는 자료구조
#include <iostream>
using namespace std;
//class A {
//public:
//	int a;
//	char c;
//	float d;
//	void C(/*A* this*/) {
//		// 함수를 클래스 안에 만들었을때 자동적으로 추가하는 기능
//		// this는 생략이 가능
//		a = 5; // this->a = 5;
//
//	}
//};
//
//void main() {
//	A a;
//	a.C(); // C(&a);
//	//cout << sizeof(a);
//}

//class Book {
//public:
//	char name[32];
//	int price;
//	char author[32];
//	void ChangeData(/*Book* this*/const char* name, const char* author, int price) {
//		strcpy_s(this->name, 32, name);
//		strcpy_s(this->author, 32, author);
//		this->price = price;
//	}
//	void Show(/*Book* this*/) {
//		cout << "Book Name : " << name << endl;
//		cout << "Book Price : " << price << endl;
//		cout << "Book Author : " << author << endl;
//	}
//};
//
//
//void main() {
//	Book A;
//	A.ChangeData("어린왕자", "생텍쥐페리", 5000);
//	// ChangeData(&A, "어린왕자", "생텍쥐페리", 5000);
//	A.Show();
//	// Show(&A);
//}

//// 사람 정보를 만들고 출력
//// 사람은이름 나이를 가짐

//class Person {
//public:
//	char name[32];
//	int age;
//	void PersonData(const char* name, int age) {
//		strcpy_s(this->name, 32, name);
//		this->age = age;
//	}
//	void Show() {
//		cout << "Person Name: " << name << endl;
//		cout << "Person Age: " << age << endl;
//	}
//
//};
//
//void main() {
//	Person A;
//	A.PersonData("김양진", 23);
//	A.Show();
//}

//class List {
//public:
//	void Insert(){}
//	void Initialize(){}
//	void Release(){}
//};
//
//void main() {
//	List a;
//	a.Initialize();
//	a.Insert();
//	a.Insert();
//	a.Insert();
//	a.Release();
//}

// 숫자를 관리하는 리스트

//class List {
//public:
//	class Node {
//	public:
//		int data;
//		Node* next;
//	};
//	Node* root;
//	void Insert(int data) {
//		Node* node = new Node;
//		node->data = data;
//		node->next = root;
//		root = node;
//	}
//	void Insert(const char* data) {
//		Insert(atoi(data));
//	}
//	void Initialize() {
//		root = 0;
//	}
//	void Release() {}
//	
//};
//
//
//// 클래스 내부 함수의 외부정의
//void List::Release() {
//	Node* now = root;
//	Node* rem;
//	while (now != 0) {
//		rem = now;
//		now = now->next;
//		free(rem);
//	}
//}
//
//void main() {
//	List a;
//	//List::Node d;
//	a.Initialize();
//
//	a.Insert("123");
//	a.Insert(5);
//
//	a.Release();
//}

// 숫자 1개를 관리하는 클래스를 만드시오
// 숫자를 집어넣는 함수를 만드시오
// 숫자를 N제곱하는 함수를 만드시오
// 숫자를 출력하는 함수를 만드시오
// 숫자의 팩토리얼을 하는 함수를 만드시오
// 양의 정수만 받을수 있다

//#include "Number.h"
//void main() {
//	Number a;
//	a.Insert(3);
//	a.Insert(-7);
//	a.Show();
//	a.Square(3);
//	a.Show();
//	a.Fectorial();
//	a.Show();
//}

// 캡슐화 > 프로퍼티

//class A {
//public:
//	int a;
//	void Setter(int n) {
//		a = n;
//	}
//	int Getter() {
//		return a;
//	}
//	__declspec(property(get = Getter, put = Setter)) int A;
//	__declspec(property(get = Getter)) int B;
//	__declspec(property(put = Setter)) int C;
//};
//
//void main() {
//	A f;
//	f.A = 5; // f.Setter(5);
//	cout << f.A; // f.Getter();
//}

//class File {
//public:
//	const char* path;
//	void SetPath(const char* path) {
//		this->path = path;
//	}
//	void WriteText(const char* data) {
//		FILE* fp;
//		fopen_s(&fp, path, "at");
//		if (fp) {
//			fprintf(fp, data);
//			fclose(fp);
//
//		}
//	}
//	__declspec(property(put = SetPath)) const char* Path;
//	__declspec(property(put = Write)) const char* WriteText;
//};
//
//void main() {
//	File a;
//	a.Path = "./a.txt";
//	a.WriteText = "AAA";
//	cout << a.WriteText;
//}

// 단순한 스택을 만들고 스택에 데이터를 넣거나 빼는것 프로퍼티로 할수 있게 만드시오
// 스택은 숫자를 관리한다

class Stack {
public:
	class Node {
	public:
		int data;
		Node* next;
	};
	Node* root;
	void Initialize() {};
	void Release() {
		Node* node = root;
		Node* rem;
		while (node != 0) {
			rem = node;
			node = node->next;
			delete rem;
		}
	}
	void Insert(int data) {
		Node* node = new Node;
		node->data = data;
		node->next = root;
		root = node;
	}
	int Pop() {
		if (!root) return 0;
		Node* node = root;
		root = root->next;
		int result = node->data;
		delete node;
		return result;
	}
	__declspec(property(put = Release, get = Insert)) int Stack;
	
};

void main() {
	Stack a;
	a.Initialize();

	a.Stack = 3;
	a.Stack = 4;

	cout << a.Stack << endl;
	cout << a.Stack << endl;

	a.Release();


}









