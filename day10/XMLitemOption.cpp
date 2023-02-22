#include "XMLitemOption.h"

XMLitemOption& XMLitemOption::operator=(const int& data)
{
	char temp[64];
	sprintf_s(temp, 64, "%d", 10);
	this->data = temp;
	return *this;
}

XMLitemOption& XMLitemOption::operator=(const float& data)
{
	char temp[64];
	sprintf_s(temp, 64, "%f", data);
	this->data = temp;
	return *this;
}

XMLitemOption& XMLitemOption::operator=(const char*& data)
{
	this->data = data;
	return *this;
}

XMLitemOption& XMLitemOption::operator=(const string& data)
{
	this->data = data;
	return *this;
}

bool XMLitemOption::operator==(const string& data)
{
	return this->key == data;
}

string XMLitemOption::FullStr(int tab)
{
	return key + "=\"" + data + "\"";
}

XMLitemOption::XMLitemOption(const char* key)
	:key(key)
{}

XMLitemOption::XMLitemOption(const char* key, const char* data)
	:key(key), data(data)
{}

XMLitemOption::XMLitemOption(const char* key, const int& data)
	:key(key)
{
	char temp[64];
	sprintf_s(temp, 64, "%d", data);
	this->data = temp;
}

XMLitemOption::XMLitemOption(const char* key, const float& data)
	:key(key)
{
	char temp[64];
	sprintf_s(temp, 64, "%f", data);
	this->data = temp;
}
