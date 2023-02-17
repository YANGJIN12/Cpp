#pragma once

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <list>
#include <vector>
#include <map>
#include <functional>
#include <algorithm>
#include <string>
#include <windows.h>
#include <chrono>
using namespace std;

enum Key {
	LBUTTON = 1,
	RBUTTON,
	CANCEL,
	MBUTTON,
	BACK = 8,
	TAB,
	CLEAR = 12,
	RETURN,
	SHIFT = 16,
	CONTROL,
	MENU,
	PAUSE,
	CAPSLOOK,
	ESCAPE = 27,
	SPACE = 32,
	PAGEUP,
	PAGEDOWN,
	END,
	HOME,
	LEFT,
	UP,
	RIGHT,
	DOWN,
	SELECT,
	PRINT,
	EXECUTE,
	SNAPSHOT,
	INS,
	DEL,
	NUM0 = 48,
	NUM1,
	NUM2,
	NUM3,
	NUM4,
	NUM5,
	NUM6,
	NUM7,
	NUM8,
	NUM9,
	A = 65,
	B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
	PADO = 96,
	PAD1, PAD2, PAD3, PAD4, PAD5, PAD6, PAD7, PAD8, PAD9P, MULTIPLY, ADD, SEPARATOR,
	SUBTRACT, DEC, DIVIDE,
	F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
	NUMLOCK = 143,
	SCROLLLOCK,
	LSHIFT = 160,
	RSHIFT,
	LCONTROL,
	RCONTROL,
	LMENU,
	RMENU

};
enum Color {
	None = -1, Black, Blue, Green, Aqua, Purple, Yellow, White, Gray, Red, LightRed, LightBlue, LightGreen, LightAqua, LightPurple, LightYellow, LightWhite 
};
enum TextColor {
	None = -1, Black, Blue, Green, Aqua, Purple, Yellow, White, Gray, Red, LightRed, LightBlue, LightGreen, LightAqua, LightPurple, LightYellow, LightWhite
};
enum BackColor {
	None = -1, Black, Blue, Green, Aqua, Purple, Yellow, White, Gray, Red, LightRed, LightBlue, LightGreen, LightAqua, LightPurple, LightYellow, LightWhite
};


class ConsolePosition {
public:
	int x, y;
	ConsolePosition(int x = 0, int y = 0) :x(x), y(y) {}
};

class ConsoleColor {
public:
	Color textcolor, backcolor;
	ConsoleColor(Color textcolor = Color::None, Color backColor = Color::None) :textcolor(textcolor), backcolor(backcolor) {}
};

class ConsoleSystem {
private:
	HANDLE Screen[2];
	BOOL ScreenCurrent;
	Color text, back;
	chrono::system_clock::time_point before, after;
private:
	void PrintText(string text){
		DWORD dw;
		WriteFile(Screen[ScreenCurrent], text.c_str(), text.length(), &dw, NULL);
	}
public:
	BOOL operator[](const Key& key) {
		return GetAsyncKeyState(key) & 0x0001;
	}
	ConsoleSystem& operator()(const int& x = 0, const int& y = 0) {
		return operator<<(ConsolePosition(x, y));
	}
	ConsoleSystem& operator()(const Color& text = Color::None, const Color& back = Color::None) {
		return operator<<(ConsoleColor(text, back));
	}
	ConsoleSystem& operator<<(const ConsolePosition& data) {
		COORD pos = { data.x, data.y };
		SetConsoleCursorPosition(Screen[ScreenCurrent], pos);
		return *this;
	}
	ConsoleSystem& operator<<(const ConsoleColor& data) {
		text = ((data.textcolor == Color::None) ? text : data.textcolor);
		back = ((data.backcolor == Color::None) ? back : data.backcolor);
		SetConsoleTextAttribute(Screen[ScreenCurrent], text | back << 4);
		return *this;
	}
	ConsoleSystem& operator<<(const int& data) {
		char dump[64];
		_itoa_s(data, dump, 10);
		PrintText(dump);
		return *this;
	}
	ConsoleSystem& operator<<(const long long& data) {
		char dump[64];
		_itoa_s(data, dump, 10);
		PrintText(dump);
		return *this;
	}
	ConsoleSystem& operator<<(const float& data) {
		char dump[64];
		sprintf_s(dump, "%f", data);
		PrintText(dump);
		return *this;
	}
	ConsoleSystem& operator<<(const double& data) {
		char dump[64];
		sprintf_s(dump, "%lf", data);
		PrintText(dump);
		return *this;
	}
	ConsoleSystem& operator<<(const char& data) {
		char dump[64];
		sprintf_s(dump, "%c", data);
		PrintText(dump);
		return *this;
	}
	ConsoleSystem& operator<<(const char* data) {
		PrintText(data);
		return *this;
	}
public:
	/*void Print(int x, int y, string text) {
		COORD pos = { x,y };
		DWORD dw;
		SetConsoleCursorPosition(Screen[ScreenCurrent], pos);
		WriteFile(Screen[ScreenCurrent], text.c_str(), text.length(), &dw, NULL);
	}*/
	void Clear() {
		COORD pos = { 0,0 };
		DWORD dw;
		FillConsoleOutputCharacterA(Screen[ScreenCurrent], ' ', 80 * 40, pos, &dw);
	}
	double Delta() {
		chrono::duration<double> delta = after - before;
		return delta.count();
	}
	void Flipping() {
		SetConsoleActiveScreenBuffer(Screen[ScreenCurrent]);
		ScreenCurrent = !ScreenCurrent;
		Clear();
		before = after;
		after = chrono::system_clock::now();
	}
public:
	ConsoleSystem(string title)
		:ScreenCurrent(false)
		, before(chrono::system_clock::now())
		, after(chrono::system_clock::now())
		, text(Color::LightWhite), back(Color::Black)
	{
		Screen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
			0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
		Screen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
			0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
		CONSOLE_CURSOR_INFO info;
		info.dwSize = 1;
		info.bVisible = false;
		SetConsoleCursorInfo(Screen[0], &info);
		SetConsoleCursorInfo(Screen[1], &info);
		SetConsoleTitleA(title.c_str());
	}
	~ConsoleSystem() {
		CloseHandle(Screen[0]);
		CloseHandle(Screen[1]);
	}

};