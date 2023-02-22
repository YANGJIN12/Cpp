#include "XMLitem.h"

bool XMLitem::operator==(const string& key)
{
	return this->key == key;
}

XMLitemOption& XMLitem::operator()(const char* key)
{
	return this->operator()(string(key));
}

XMLitemOption& XMLitem::operator()(const string& key)
{
	for (auto& option : options) {
		if (*option == key)	return *option;
	}
	options.push_back(new XMLitemOption(key.c_str()));
	return **options.rbegin();
}

XMLitem& XMLitem::operator[](const char* key)
{
	return this->operator[](string(key));
}

XMLitem& XMLitem::operator[](const string& key)
{
	for (auto& child : childs) {
		if (*child == key)	return *child;
	}
	options.push_back(new XMLitemOption(key.c_str()));
	return **childs.rbegin();
}

XMLitem::operator int()
{
	return std::stoi(data);
}

XMLitem::operator float()
{
	return std::stof(data);
}

XMLitem::operator const char* ()
{
	return data.c_str();
}

XMLitem::operator string()
{
	return data;
}

XMLitem& XMLitem::operator=(const int& data)
{
	char temp[64];
	sprintf_s(temp, 64, "%d", data);
	this->data = temp;
	return *this;
}

XMLitem& XMLitem::operator=(const float& data)
{
	char temp[64];
	sprintf_s(temp, 64, "%f", data);
	this->data = temp;
	return *this;
}

XMLitem& XMLitem::operator=(const char* data)
{
	this->data = data;
	return *this;
}

XMLitem& XMLitem::operator=(const string& data)
{
	this->data = data;
	return *this;
}

string XMLitem::FullStr(int tab)
{
	string result;
	for (int i = 0; i < tab; ++i) result += "\t";
	result += "<" + key;
	for (auto& option : options) {
		result += " " + option->FullStr();
	}
	if (childs.size() < 1 && data.length() < 1) {
		result += "/>";
		return result;
	}
	result += ">";
	if (childs.size() > 0) result += "\n";
	for (auto& child : childs) {
		result += child->FullStr(tab + 1) + "\n";
	}
	if (childs.size() > 0) for (int i = 0; i < tab; ++i) result += "\t";
	result += data + "</" + key + ">";
	return result;
}

XMLitem::XMLitem(const char* key)
	:key(key)
{}

XMLitem::XMLitem(const char* key, const char*& data)
	:key(key), data(data)
{}

XMLitem::XMLitem(const char* key, const int& data)
{
	char temp[64];
	sprintf_s(temp, 64, "%d", data);
	this->data = temp;
}

XMLitem::XMLitem(const char* key, const float&)
	:key(key)
{
	char temp[64];
	sprintf_s(temp, 64, "%f", data);
	this->data = temp;
}



XMLitem::~XMLitem()
{
	for (auto& option : options) {
		delete option;
	}
	for (auto& child : childs) {
		delete child;
	}
}
