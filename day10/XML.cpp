#include "XML.h"

XMLitem& XML::operator[](const char* key)
{
	return this->operator[](string(key));
}

XMLitem& XML::operator[](const string& key)
{
	for (auto& child : childs) {
		if (*child == key)	return *child;
	}
	childs.push_back(new XMLitem(key.c_str()));
	return **childs.rbegin();
}

string XML::FullStr()
{
	string result;
	result += "< ? xml version = \"1.0\" encoding = \"utf-8\"? >";
	for (auto& item : childs) {
		result += item->FullStr() + "\n";
	}
	return result;
}

bool XML::Save(const string& path)
{
	return Save(path.c_str());
}

bool XML::Save(const char* path)
{
	FILE* fp;
	fopen_s(&fp, path, "wt");
	if(!fp) return false;
	fprintf(fp, FullStr().c_str());
	fclose(fp);
	return true;
}

XML::XML()
{
}

XML::~XML()
{
	for (auto& child : childs) {
		delete child;
	}
}
