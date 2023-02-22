#pragma once
#include "XMLitemOption.h"
#include <list>
using std::list;
class XMLitem
{
private:
	list<XMLitemOption*> options;
	list<XMLitem*> childs;
	string key, data;
public:
	bool operator==(const string& key);
public:
	XMLitemOption& operator()(const char* key);
	XMLitemOption& operator()(const string& key);
	XMLitem& operator[](const char* key);
	XMLitem& operator[](const string& key);


public:
	operator int();
	operator float();
	operator const char*();
	operator string();
public:
	XMLitem& operator=(const int& data);
	XMLitem& operator=(const float& data);
	XMLitem& operator=(const char* data);
	XMLitem& operator=(const string& data);
public:
	string FullStr(int tab = 0);
public:
	XMLitem(const char* key);
	XMLitem(const char* key, const char*& data);
	XMLitem(const char* key, const int& data);
	XMLitem(const char* key, const float&);

	~XMLitem();

};

