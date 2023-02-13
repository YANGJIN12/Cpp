#include "number.h"


void Number::Insert(int data)
{
	if (data < 1) return;
	this->data = data;	
}
void Number::Show()
{
	std::cout << data << std::endl;
}
void Number::Square(int n)
{
	int r = 1;
	for (int i = 0; i < n; ++i) r *= data;
	data = r;
}
void Number::Fectorial()
{
	int r = 1;
	for (int i = data; i > 0; --i) {
		r *= i;
	}
}
