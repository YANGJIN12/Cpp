#include <iostream>
#include <functional>
#include <chrono> 
using namespace std;

// ������ > ������ ������ �� '������' �ڵ��� ȣ��Ǵ� �Լ�
// �ƹ��� �����ڵ� �ȸ���� > ����Ʈ ������
//class A {
//public:
//	int x, y;
//	A(){}
//	A(int x, int y = 0) 
//	{
//		cout << "������ ȣ��" << endl;
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
//	A() { cout << "������" << endl; }
//};
//
//void main() {
//	//A a;
//	A* p = new A[4];
//	delete[] p;
//}

// �������� Ư¡
// 1. �����ڴ� �ƹ��͵� �ȸ��� �ּ� 3���� �����ڰ� ������
//class A {
//public:
//	// A(){}
//	// A(const A&) {} > ���� ������
//	// A(const A&&) {}
//};
// 2. �Լ��� ȣ���� �ڵ����� '������' ȣ��ǳ� �ڷ����� ��ġ�ؾ߸� ������
// 3. �Լ��� �� ȣ���� �Ұ�����

// å Ŭ������ ����� å����(å�̸�, �۰���)�� ������ �� ���

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
//	Book A("�̱��� ������", "��ó�� ��Ų��");
//	A.Show();
//}

//class Objerve {
//public:
//	int& data;
//	Objerve(int a)
//		: data(a)
//	{}
//};

// �Ҹ��� > Ŭ���� ������ �Ҹ�(����)�� �� �ڵ����� ȣ��Ǵ� �Լ�
// �Ҹ��� > �����ڿ� ���� ���� �κ��� ������
// �Լ� �̸� - ~Ŭ���� �̸�, ���ڰ� ����
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

// Array[�迭]
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

// �����ڿ� �Ҹ��ڸ� �̿��Ͽ� ����Ʈ�� �����Ͻÿ�

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
// ���� ���� ���� ��� Ŭ������ �̿��Ͽ� �������� ���
// �Է� �̺�Ʈ�� �ۼ�

void main() {
	FileWriter A("./main.txt");
	auto lambda = [&](int data)->void {
		cout << "��¿� ����" << endl;
		A.Write(data);
	};
	for (auto i = 2; i <= 9; ++i) {
		for (auto j = 2; j <= 9; ++j) {
			lambda(i * j);
		}
	}
}

