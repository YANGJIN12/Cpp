// 1. �����Ҵ��� ��ȭ 
// malloc(sizeof)
// delete[] a;
// }

// 2. ���ӽ����̽�
// ���ӽ����̽� > �̸� ����

// Begin - ����
// A
// B
// C
// End

namespace A {
	int a;
	void A() {}
}
namespace B {
	int b;
	void B() {}
}

#include <iostream>
// using > namespace�� ��ɰ� �� �ݴ�
// using std::cout;
// using A::A;
// void cout(){}
//using namespace std;
//using namespace aaa;
//void main() {
	// cout << 1;
//	A::A();
//	cout << 1;
//}

//namespace std {
//	void A() {
//																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																											
//	}
//}

// std �̸� ���� �ȿ� ���� 3���� ���� ū���� ���ϴ� �Լ��� �߰��Ͻÿ�
// std �̸� ���� �ȿ� A �̸������� �߰��Ͻÿ�
//namespace std {

	//int big2(int a, int b) {
	//	return (a > b) ? a : b;
	//}

	//int big(int a, int b, int c) {
	//	return big2(big2(a, b), c);

	//}
	//namespace A {

	//}
//}
#include <iostream>
using namespace std;

// 3. �����ε� - ����Ʈ �Ű�����
// �����ε� > ������ �̸��� �Լ��� ������ Ÿ��, ������ �����ؼ� �̿��ϴ� ���
//int big(int a, int b) { return a > b ? a : b; }
//int big(int a, int b, int c) { return big(big(a, b), c); }
//float big(float a, float b) { return a > b ? a : b; }
//void main() {
//	cout << big(3.5f, 4.5f) << endl;
//	cout << big(3, 4, 5) << endl;
//	cout << big(5, 7) << endl;
//}

//int sum(int n, int m) {
//	return n + m;
//}
//int sum(int n, int m, int k) {
//	return n + m + k;
//}

//int square(int n) {
//	int r = 1;
//	for (int i = 0; i < 2; ++i) {
//		r *= n;
//	}
//	return r;
//}

//int square(int n, int m = 2) {
//	int r = 1;
//	for (int i = 0; i < m; ++i) {
//		r *= n;
//	}
//	return r;
//}
//void main() {
//	cout << square(2);
//}

// standard call
//int __stdcall sum(int q, int w, int e = 0, int r = 0, int t = 0, int y = 0, int u = 0, int i = 0) {
//	return q + w + e + r + t + y + u + i;
//}
//int __cdecl hap(int q, int w, int e = 0, int r = 0, int t = 0, int y = 0, int u = 0, int i = 0) {
//	return q + w + e + r + t + y + u + i;
//}
//
//void main() {
//	sum(1, 2, 3, 4, 5, 6);
//}

// ���� N���� �Է¹޾� ���� ū���� ���ϴ� �Լ�
// ���� N���� �Է¹޾� ���� �������� ���ϴ� �Լ�
// ���� N���� �Է¹޾� ����� ���ϴ� �Լ�
// �� �Լ��� ����Ʈ �Ű�����, �����ε��� �̿��Ͽ� ����ÿ�
// N�� �ִ� 4

//int big(int a, int b, int c = INT_MAX, int d = INT_MAX) {
//	if (a > b && a > c && a > d) return a;
//	if (b > c && b > d) return b;
//	if (c > d) return c;
//	return d;
//}
//int tiny(int a, int b, int c = INT_MIN, int d = INT_MIN) {
//	if (a < b && a < c && a < d) return a;
//	if (b < c && b < d) return b;
//	if (c < d) return c;
//	return d;
//}
//
//int avg(int n, int m, int a, int b) { return (n + m + a + b) / 4; }

// 4. ���� �Լ�
// �ʿ��Ҷ� �Լ��� ��� �����ؼ� ����ϴ� ���
// �Լ��� �̸� �������� �ʰ� �ʿ��� �������� ����Ҽ� �ִ� ���

//struct Unit {
//	int hp;
//	int hpmax;
//	int mp;
//	int mpmax;
//	int atk;
//	int def;
//	void (*Attack)(struct Unit&, struct Unit&);
//	void (*Spell1)(struct Unit&, struct Unit&);
//	void (*Spell2)(struct Unit&, struct Unit&);
//
//};
//
//void SetUnit(struct Unit& data, int hp, int mp, int atk, int def,
//	void(*att)(struct Unit&, struct Unit&),
//	void(*sp1)(struct Unit&, struct Unit&),
//	void(*sp2)(struct Unit&, struct Unit&)) {
//	data.hp = hp; data.hpmax = hp;
//	data.mp = mp; data.mpmax = mp;
//	data.atk = atk; data.def = def;
//	data.Spell1 = sp1;
//	data.Spell2 = sp2;
//}
//
//void PowerAttack(struct Unit& attacker, struct Unit& defender) {
//	cout << " �Ŀ� ����! " << endl;
//	if (attacker.mp >= 10) {
//		defender.hp -= attacker.atk - defender.def;
//		defender.mp -= 10;
//	}
//	else
//		cout << " ������ �����մϴ�. " << endl;
//}
//#include <windows.h>
//void main() {
//	
//	// ������ �ſ� ����
//	// �Լ�  > �ڵ��� ���� > �迭�� ���
//	// [](���ڰ�)->����Ÿ��{ ���� }
//
//	Unit player, monster;
//	SetUnit(player, 100, 100, 10, 5,
//		[](struct Unit& attacker, struct Unit& defender)->void {
//		cout << " ���� ����! " << endl;
//		defender.hp -= attacker.atk - defender.def;
//	}
//	, PowerAttack, 0);
//	SetUnit(monster, 50, 50, 7, 3,
//		[](struct Unit& attacker, struct Unit& defender)->void {
//			cout << " ���� ����! " << endl;
//	defender.hp -= attacker.atk - defender.def;
//		}
//	, PowerAttack, 0);
//	while (1) {
//		system("cls");
//		cout << " Player" << endl;
//		cout << " Hp: "  << player.hp  << " / " << player.hpmax << endl;
//		cout << " Mp: "  << player.mp  << " / " << player.mpmax << endl;
//		cout << " Att: " << player.atk << endl;
//		cout << " Def: " << player.def << endl << endl << endl;
//
//		cout << " Monster" << endl;
//		cout << " Hp: "  << monster.hp  << " / " << monster.hpmax << endl;
//		cout << " Mp: "  << monster.mp  << " / " << monster.mpmax << endl;
//		cout << " Att: " << monster.atk << endl;
//		cout << " Def: " << monster.def << endl << endl << endl;
//
//		int sel;
//		cout << " 1. �Ϲݰ��� 2. ��ų1 3. ��ų2" << endl << "  >>> ";
//		cin >> sel;
//		cout << " Player: ";
//		if (sel == 1) player.Attack(player.monster);
//		else if (sel == 2) player.Spell1(player.monster);
//		cout << " Monster:  ";
//		monster.Attack(monster, player);
//		Sleep(1500);
//		
//
//
//	}
//}

//void main() {
//	int x = 5;
//	// Capture(ĸ��)
//	auto a = [&]()->void {
//		x = 7;
//	};
//	a();
//	x = 6;
//	a();
//}
#include <functional>

//auto CreateLamda(const char* begin = "", const char* end = " \n ") {
//	return [begin, end](function<void()> act)->void {
//		cout << begin;
//		act();
//		cout << end;
//	};
//}
//
//
//void main() {
//	auto out = CreateLamda("------>", "<------\n");
//	for (int i = 0; i < 10; ++i) {
//		out([&]()->void {
//			cout << i;
//			});
//	}
//}

// �����Լ��� �̿��Ͽ� ������ ���
// ���� ���۰� �������� Ư�� ����� ĸ�ĸ� �̿��Ͽ� ����

auto cr(function<void(int)>act, const char* begin, const char* end) {
	return [begin, end, act]()->void {
		for (int i = 1; i <= 9; ++i) {
			cout << begin;
			act(i);
			cout << end;
		}
	};
}

void main() {
	auto dan = [](int n)->void {
		for (int x = 1; x <= 9; ++x) {
			cout << n << " * " << x << " = " << n * x << " ";
		}
	};
	auto gugudan = cr(dan, "----�ܽ���-----\n", "\n------�ܳ�------\n");
	gugudan();
}