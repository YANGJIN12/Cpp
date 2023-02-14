#include <iostream>
#include <functional>
#include <chrono> 
using namespace std;

// 생성자 > 변수를 생성할 떄 '무조건' 자동을 호출되는 함수
// 아무런 생성자도 안만들면 > 디폴트 생성자
//class A {
//public:
//	int x, y;
//	A(){}
//	A(int x, int y = 0) 
//	{
//		cout << "생성자 호출" << endl;
//		this->x = x; this->y = y; 
//	}
//};
//
//void main() {
//	A a(2, 3), b(3, 4), c(5, 5);
//}

//class Stack {
//public:
//	class Node {
//	public:
//		Node* next;
//		Node() { next = nullptr; }
//	};
//public:
//	Node* root;
//	Stack() { root = nullptr; }
//};
//
//class A {
//public:
//	A() { cout << "생성자" << endl; }
//};
//
//void main() {
//	//A a;
//	A* p = new A[4];
//	delete[] p;
//}

// 생성자의 특징
// 1. 생성자는 아무것도 안만들어도 최소 3개의 생성자가 생성됨
//class A {
//public:
//	// A(){}
//	// A(const A&) {} > 복사 생성자
//	// A(const A&&) {}
//};
// 2. 함수의 호출이 자동으로 '무조건' 호출되나 자료형이 일치해야만 가능함
// 3. 함수의 재 호출이 불가능함

// 책 클래스를 만들고 책정보(책이름, 작가명)을 저장한 후 출력

//class Book {
//public:
//	char book[32];
//	char author[32];
//	Book(const char* bookname, const char* name = "Unknown") {
//		strcpy_s(this->book, 32, book);
//		strcpy_s(this->author, 32, author);
//	}
//	void Show() {
//		cout << book << endl;
//		cout << author << endl;
//	}
//};
//
//void main() {
//	Book A("이기적 유전자", "리처드 도킨스");
//	A.Show();
//}

//class Objerve {
//public:
//	int& data;
//	Objerve(int a)
//		: data(a)
//	{}
//};

// 소멸자 > 클래스 변수가 소멸(삭제)될 때 자동으로 호출되는 함수
// 소멸자 > 생성자와 아주 많은 부분이 동일함
// 함수 이름 - ~클래스 이름, 인자값 여부
//class Stack {
//public:
//	class Node {
//	public:
//		Node* next;
//		Node() :next(nullptr){}
//		~Node(){}
//	};
//	Node* root;
//	Stack() :root(nullptr){}
//	~Stack(){}
//};

// Array[배열]
//class Array {
//public:
//	int* datas;
//	int size;
//	int& Get(int index) { return datas[index % size]; }
//	Array(int size = 2):size(size), datas(new int[size]){}
//	~Array() { delete[] datas; }
//};
//
//void main() {
//	Array a(30);
//	a.Get(0) = 5;
//}

// 생성자와 소멸자를 이용하여 리스트를 구성하시오

//class List {
//public:
//	class Node {
//	public:
//		int data;
//		Node* next;
//		Node* prev;
//		Node(const int& data) :data(data), next(nullptr), prev(nullptr){}
//		~Node() {
//			if (next) delete next;
//		}
//	};
//public:
//	void Action(function<void(int&)> act) {
//		Node* now = root;
//		while (now != 0) {
//			
//
//		}
//	}
//public:
//	void Insert(const int& data) {
//		Node* node = new Node(data);
//		if (end) end->next = node;
//		else root = node;
//		node->prev = end;
//		end = node;
//	}
//public:
//	Node* root;
//	Node* end;
//public:
//	List() :root(nullptr), end(nullptr){}
//	~List() {
//		if (root) delete root;
//	}
//};
//
//void main() {
//	List a;
//	a.Insert(3);
//	a.Insert(4);
//	a.Insert(5);
//
//	a.Action([](int& data)->void {
//		data = data * 2;
//		});
//	a.Action([](int& data)->void {
//		cout << data << " > ";
//		});
//
//}
//class A{};
////void B(int& p, int& pp) {
////	p = pp;
////}
//void B() {};
//
//void main() {
//	int a;
//	chrono::system_clock::time_point before, after;
//	before = chrono::system_clock::now();
//	for (int i = 0; i < 100000000; ++i)
//		a = i;
//	after = chrono::system_clock::now();
//	chrono::nanoseconds timer;
//	timer = after - before;
//	cout << "C Language : " << timer.count() << endl;
//	before = chrono::system_clock::now();
//	for (int i = 0; i < 100000000; ++i)
//		//B(a, i);
//		B();
//	after = chrono::system_clock::now();
//	timer = after - before;
//	cout << "C++ Language : " << timer.count() << endl;
//
//
//
//}

class FileWriter {
public:
	FILE* fp;
	FileWriter& Write(const int& data) {
		if (fp) fprintf(fp, "%d", data);
		return *this;
	}
	FileWriter& Write(const float& data) {
		if (fp) fprintf(fp, "%f", data);
		return *this;
	}
	FileWriter& Write(const long long& data) {
		if (fp) fprintf(fp, "%IId", data);
		return *this;
	}
	FileWriter& Write(const double& data) {
		if (fp) fprintf(fp, "%If", data);
		return *this;
	}
	FileWriter& Write(const char* data) {
		if (fp) fprintf(fp, "%s", data);
		return *this;
	}
	FileWriter& Write(const char& data) {
		if (fp) fprintf(fp, "%c", data);
		return *this;
	}
	FileWriter(const char* path): fp(nullptr) {
		fopen_s(&fp, path, "wt");
	}
	~FileWriter() {
		if (fp) fclose(fp);
	}
};
// 지금 만든 파일 출력 클래스를 이용하여 구구단을 출력
// 입력 이벤트를 작성

void main() {
	FileWriter A("./main.txt");
	auto lambda = [&](int data)->void {
		cout << "출력에 성공" << endl;
		A.Write(data);
	};
	for (auto i = 2; i <= 9; ++i) {
		for (auto j = 2; j <= 9; ++j) {
			lambda(i * j);
		}
	}
}

