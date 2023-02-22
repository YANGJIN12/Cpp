#include "XML.h"
#include <iostream>
using std::cout;
using std::endl;

void main() {
	XML Bank;
	Bank["User"]["0000000"]["Name"] = "±è¾çÁø";
	Bank["User"]["0000000"]["Balance"] = 50000;
	cout << Bank.FullStr() << endl;


}