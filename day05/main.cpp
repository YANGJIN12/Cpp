#include <iostream>
#include <functional>
using namespace std;

//class Object {
//public:
//	string name;
//	double weight;
//	Object(string name, double weight) : name(name), weight(weight) {}
//};
//
//class Matter {
//public:
//	Object obj;
//	Matter(string name, double weight): obj(name, weight){}
//
//};
//
//class Fluid {
//public:
//	Object obj;
//	Fluid(string name, double weight): obj(name, weight){}
//};

// 클래스의 확장 > 상속

//class A {
//public:
//	int a;
//};
//
//class B : public A {
//public:
//	int b;
//	void E() {
//		a = 5;
//	}
//};
//
//
//void main() {
//	B a;
//
//}

//class Animal {
//public:
//	string name;
//	double weight;
//	Animal(string name, double weight) :name(name), weight(weight){
//		cout << "Animal 생성자" << endl;
//	}
//	~Animal() {
//		cout << "Animal 소멸자" << endl;
//	}
//};
//
//class Human : public Animal {
//public:
//	string location;
//	string phone;
//	Human(string name, double weight, string location, string phone) :location(location), phone(phone), Animal(name,weight) {
//		cout << "Human 생성자" << endl;
//	}
//	~Human() {
//		cout << "Human 소멸자" << endl;
//	}
//};
//
//class Student : public Human {
//public:
//	int score;
//	Student(string name, double weight, string location, string phone, int score) :Human(name, weight, location, phone),score(score) {
//		cout << "Student 생성자" << endl;
//	}
//	~Student() {
//		this->location;
//		cout << "Student 소멸자" << endl;
//	}
//};
//
//void main() {
//	Student A("홍길동",67.5,"주소","번호",50);
//}

// 책클래스를 만드시오
// 책은 책이름과 작가명을 정보로 가진다
// 책은 출력이 가능하다
// 책을 상속한 베스트셀러를 만드시오
// 책의 출력과 별개로 베스트셀러 출력기능을 추가

//class Book {
//public:
//	string book;
//	string author;
//	void ShowBook(/*Book* this*/) {
//		cout << book << " [ " << author << " ] " << endl;
//	}
//	Book(string book, string author) :book(book), author(author){}
//};
//
//class BestSeller : public Book {
//public:
//	void ShowBook(/*BestSeller* this*/) {
//		cout << "BestSeller - "; Book::ShowBook();
//	}
//	BestSeller(string book, string author) :Book(book,author){}
//};
//
//void main() {
//	BestSeller A("이기적유전자","리처드 도킨스");
//	A.ShowBook(); // ShowBook(&A);
//	A.Book::ShowBook();
//}

// 클래스의 내부정보를 이용하는 경로 > 3가지
// 1. 클래스 변수를 이용한 외부 접근 - 3레벨
// 3. 클래스의 자식 클래스의 내부 함수에서의 상속 접근 - 2레벨
// 2. 클래스 내부 함수에서의 내부 접근 - 1레벨

// 접근제어자 > private, protected, public
// private > 1레벨만 접근 가능
// protected > 2레벨 이하만 접근 가능
// public > 3레벨 이하만 접근 가능



// 클래스 상속 간 > 함수 오버라이딩

//class List {
//public:
//	class Node {
//	public:
//		int data;
//		Node* next;
//		Node* prev;
//		Node(int data) :data(data), next(nullptr), prev(nullptr) {};
//	};
//public:
//	void Insert(int data) {
//		Node* node = new Node(data);
//		if (end) end->next = node;
//		else root = node;
//		node->prev = end;
//		end = node;
//	}
//	int Pop() {
//		if (root == 0) return 0;
//		Node* node = root;
//		root = root->next;
//		if (root) root->prev = 0;
//		int result = node->data;
//		delete node;
//		return result;
//	}
//public:
//	Node* root;
//	Node* end;
//	List() :root(nullptr), end(nullptr) {}
//	~List() {
//		Node* now = root;
//		Node* rem;
//		while (now != 0) {
//			rem = now;
//			now = now->next;
//			delete rem;
//		}
//	}
//};

// public 상속 > 상속한 모든 것의 최대 권한이 public이다. > 모든 권한을 그대로 유지해라
// protected  상속 > 상속한 모든 것의 최대 권한이 protected이다 > public을 protected로 바꿔라
// private 상속 > 상속한 모든 것의 최대 권한이 private이다 > 모든 권한을  private로 바꿔라

//class Stack : public List {
//public:
//	void Insert(int data) {
//		Node* node = new Node(data);
//		if (root) root->prev = node;
//		else end = node;
//		node->next = root;
//		root = node;
//	}
//};
//
//class Que : public List {
//public:
//
//};

//class List {
//protected:
//	class Node {
//	public:
//	//private:
//		int data;
//		Node* next;
//		Node* prev;
//		Node(const int& data) :data(data), next(nullptr), prev(nullptr) {}
//		//friend class List;
//	};
//private:
//	Node* CreateNode(const int& data) {
//		return new Node(data);
//	}
//private:
//	Node* root;
//	Node* end;
//public:
//	void Action(function<void(int&)> act) {
//		Node* now = root;
//		while (now != 0) {
//			act(now->data);
//			now = now->next;
//		}
//	}
//public:
//	void InsertFront(const int& data) {
//		Node* node = CreateNode(data);
//		if (root) root->prev = node;
//		else end = node;
//		node->next = root;
//		root = node;
//	}
//	void InsertBack(const int& data) {
//		Node* node = CreateNode(data);
//		if (end) end->next = node;
//		else root = node;
//		node->prev = end;
//		end = node;
//	}
//	int PopFront() {
//		if (!root) return int();
//		Node* remover = root;
//		root = root->next;
//		if (root) root->prev = nullptr;
//		else end = nullptr;
//		int result = remover->data;
//		delete remover;
//		return result;
//	}
//	int PopBack() {
//		if (!end) return int();
//		Node* remover = end;
//		end = end->prev;
//		if (end) end->next = nullptr;
//		else root = nullptr;
//		int result = remover->data;
//		delete remover;
//		return result;
//	}
//public:
//	List() :root(nullptr), end(nullptr){}
//	~List() {
//		Node* now = root;
//		Node* remover;
//		while (now != 0) {
//			remover = now;
//			now = now->next;
//			delete remover;
//		}
//	}
//};
//
//class Stack : public List {
//public:
//	void Push(const int& data) {
//		InsertFront(data);
//	}
//	int Pop() {
//		return PopFront();
//	}
//	void Action(function<void(int&)> act) {
//		List::Action(act);
//	}
//};
//
//class Que : public List {
//public:
//	void Push(const int& data) {
//		InsertFront(data);
//	}
//	int Pop() {
//		return PopBack();
//	}
//	void Action(function<void(int&)> act) {
//		List::Action(act);
//	}
//};
//
//// 만든 3개의 자료구조 클래스에 가지고있는 모든 데이터를 순회하는 동작을 람다함수로 받아서 
//// 실행하는 함수를 추가하시오
//
//
//void main() {
//	List a;
//	Stack b;
//	Que c;
//	/*a.InsertFront(4); a.InsertFront(3); a.InsertFront(2); a.InsertFront(1);
//	a.Action([](int& data)->void {
//		cout << data << " > ";
//	});
//	cout << endl;
//	b.Push(1); b.Push(2); b.Push(3); b.Push(4);
//	b.Action([](int& data)->void {
//		cout << data << " > ";
//	});
//	cout << endl;
//	c.Push(1); c.Push(2); c.Push(3); c.Push(4);
//	c.Action([](int& data)->void {
//		cout << data << " > ";
//		});*/
//	List* p = &b;
//	//p->PopFront; 업 캐스팅시 자식이 가지고있던 데이터를 사용할 수 없음
//	// 다운 캐스팅 > 부모 클래스를 자식 클래스로 형변환
//	//dynamic_cast<Stack*>(p);
//
//}

// Java 문법에서는 매우 쓸모있는 기능 > 다중상속
// implements, extends
// 자식 1 부모N
//class A {
//public: A() { cout << "A 생성자" << endl; }
//};
//class B : public A{
//public: B() { cout << "B 생성자" << endl; }
//};
//class C : public A{
//public: C() { cout << "C 생성자" << endl; }
//};
//class D : public B, public C {
//public: D() { cout << "D 생성자" << endl; }
//};
//
//void main() {
//	D a;
//}