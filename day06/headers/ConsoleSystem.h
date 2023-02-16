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
enum Color {
	Black = 0, Blue, Green, Aqua, Purple, Yellow, White, Gray, LightBlue, LightGreen, LightAqua, LightPurple, LightYellow, LightWhite 
};

class ConsoleSystem {
private:
	HANDLE Screen[2];
	BOOL ScreenCurrent;
	chrono::system_clock::time_point before, after;
public:
	void Print(int x, int y, string text) {
		COORD pos = { x,y };
		DWORD dw;
		SetConsoleCursorPosition(Screen[ScreenCurrent], pos);
		WriteFile(Screen[ScreenCurrent], text.c_str(), text.length(), &dw, NULL);
	}
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