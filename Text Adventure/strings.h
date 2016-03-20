#pragma once
#include <iostream>
class  String
{
	char* m_string;
	int m_size;
	int m_capacity;
public:

	String();
	String(char string[]);

	String(int size);
	~String();
	operator const char* () { return m_string; }
	int Length();
	bool operator == (const char *other);
	bool operator == (String & other);
	void operator = (String & other);
	void operator=(char string[]);
	char* operator [] (const int location);
	void resize(int newSize);
	String toLower();
	String toUpper();
	void operator += (const String &  other);
	void operator += (const char*  other);
	String operator + (const char*  other);
	String operator + (const String &  other);
	char* subStringFind(const char* subString);
	char* subStringFind(const char* subString, int location);
	void subStringReplace(const char * subString, char* replacement);
	const char* get();
	String(String &string);
	friend String operator +(char lhs[], String rhs);
	void getline() {
		char temp[256];
		std::cin.getline(temp, 256);
		*this = temp;
	}
	String Returnline() {
		char temp[40];
		std::cin.getline(temp, 40);
		*this = temp;
		return *this;
	}
};
