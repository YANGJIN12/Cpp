// ���� �����̶�? > �ӵ��� �߿��
// ��ü �����̶�? > �ӵ��� ���Ǽ��� �Ѵ� �߿��
// ��ü�� ����? > ���Ǽ��� �߿��
// C���� �̹� �������� ������ ���� > Structure
// Ŭ������ �� ����°�? > �ٸ� ������ ���ϼ��� ���ؼ� 
// C++�� ����ü(Structure)�� Ŭ����(Class)�� ������ ������ ������ ��

// ��ü�� �����ΰ�? > �������� �ִ� �������� �ϳ��� ��� �����ϴ� ��
// �׷��ٸ� Ŭ������ �����ΰ�? > ��ü�� �����ϴ� �ڷᱸ��
#include <iostream>
using namespace std;
//class A {
//public:
//	int a;
//	char c;
//	float d;
//	void C(/*A* this*/) {
//		// �Լ��� Ŭ���� �ȿ� ��������� �ڵ������� �߰��ϴ� ���
//		// this�� ������ ����
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
//	A.ChangeData("�����", "�������丮", 5000);
//	// ChangeData(&A, "�����", "�������丮", 5000);
//	A.Show();
//	// Show(&A);
//}

//// ��� ������ ����� ���
//// ������̸� ���̸� ����

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
//	A.PersonData("�����", 23);
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

// ���ڸ� �����ϴ� ����Ʈ

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
//// Ŭ���� ���� �Լ��� �ܺ�����
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

// ���� 1���� �����ϴ� Ŭ������ ����ÿ�
// ���ڸ� ����ִ� �Լ��� ����ÿ�
// ���ڸ� N�����ϴ� �Լ��� ����ÿ�
// ���ڸ� ����ϴ� �Լ��� ����ÿ�
// ������ ���丮���� �ϴ� �Լ��� ����ÿ�
// ���� ������ ������ �ִ�

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

// ĸ��ȭ > ������Ƽ

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

// �ܼ��� ������ ����� ���ÿ� �����͸� �ְų� ���°� ������Ƽ�� �Ҽ� �ְ� ����ÿ�
// ������ ���ڸ� �����Ѵ�

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









