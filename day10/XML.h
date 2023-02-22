#pragma once
#include "XMLitem.h"
class XML
{
private:
	list<XMLitem*> childs;
public:
	XMLitem& operator[](const char* key);
	XMLitem& operator[](const string& key);
public:
	string FullStr();
	bool Save(const string& path);
	bool Save(const char* path);

public:
	XML();
	~XML();

};

