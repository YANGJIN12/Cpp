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

// Ŭ������ Ȯ�� > ���

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
//		cout << "Animal ������" << endl;
//	}
//	~Animal() {
//		cout << "Animal �Ҹ���" << endl;
//	}
//};
//
//class Human : public Animal {
//public:
//	string location;
//	string phone;
//	Human(string name, double weight, string location, string phone) :location(location), phone(phone), Animal(name,weight) {
//		cout << "Human ������" << endl;
//	}
//	~Human() {
//		cout << "Human �Ҹ���" << endl;
//	}
//};
//
//class Student : public Human {
//public:
//	int score;
//	Student(string name, double weight, string location, string phone, int score) :Human(name, weight, location, phone),score(score) {
//		cout << "Student ������" << endl;
//	}
//	~Student() {
//		this->location;
//		cout << "Student �Ҹ���" << endl;
//	}
//};
//
//void main() {
//	Student A("ȫ�浿",67.5,"�ּ�","��ȣ",50);
//}

// åŬ������ ����ÿ�
// å�� å�̸��� �۰����� ������ ������
// å�� ����� �����ϴ�
// å�� ����� ����Ʈ������ ����ÿ�
// å�� ��°� ������ ����Ʈ���� ��±���� �߰�

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
//	BestSeller A("�̱���������","��ó�� ��Ų��");
//	A.ShowBook(); // ShowBook(&A);
//	A.Book::ShowBook();
//}

// Ŭ������ ���������� �̿��ϴ� ��� > 3����
// 1. Ŭ���� ������ �̿��� �ܺ� ���� - 3����
// 3. Ŭ������ �ڽ� Ŭ������ ���� �Լ������� ��� ���� - 2����
// 2. Ŭ���� ���� �Լ������� ���� ���� - 1����

// ���������� > private, protected, public
// private > 1������ ���� ����
// protected > 2���� ���ϸ� ���� ����
// public > 3���� ���ϸ� ���� ����



// Ŭ���� ��� �� > �Լ� �������̵�

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

// public ��� > ����� ��� ���� �ִ� ������ public�̴�. > ��� ������ �״�� �����ض�
// protected  ��� > ����� ��� ���� �ִ� ������ protected�̴� > public�� protected�� �ٲ��
// private ��� > ����� ��� ���� �ִ� ������ private�̴� > ��� ������  private�� �ٲ��

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
//// ���� 3���� �ڷᱸ�� Ŭ������ �������ִ� ��� �����͸� ��ȸ�ϴ� ������ �����Լ��� �޾Ƽ� 
//// �����ϴ� �Լ��� �߰��Ͻÿ�
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
//	//p->PopFront; �� ĳ���ý� �ڽ��� �������ִ� �����͸� ����� �� ����
//	// �ٿ� ĳ���� > �θ� Ŭ������ �ڽ� Ŭ������ ����ȯ
//	//dynamic_cast<Stack*>(p);
//
//}

// Java ���������� �ſ� �����ִ� ��� > ���߻��
// implements, extends
// �ڽ� 1 �θ�N
//class A {
//public: A() { cout << "A ������" << endl; }
//};
//class B : public A{
//public: B() { cout << "B ������" << endl; }
//};
//class C : public A{
//public: C() { cout << "C ������" << endl; }
//};
//class D : public B, public C {
//public: D() { cout << "D ������" << endl; }
//};
//
//void main() {
//	D a;
//}