#pragma once
#include <string>
using std::string;
class XMLitemOption
{
private:
	string key, data;
public:
	operator int() {return std::stoi(data);}
	operator float() {return std::stof(data);}
	operator const char* () { return data.c_str(); }
	operator string() { return data; }
public:
	XMLitemOption& operator=(const int& data);
	XMLitemOption& operator=(const float& data);
	XMLitemOption& operator=(const char*& data);
	XMLitemOption& operator=(const string& data);
public:
	bool operator==(const string& data);

public:
	string FullStr(int tab = 0);
public:
	XMLitemOption(const char* key);
	XMLitemOption(const char* key, const char* data);
	XMLitemOption(const char* key, const int& data);
	XMLitemOption(const char* key, const float& data);
};

