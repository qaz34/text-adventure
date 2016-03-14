#include "strings.h"
#include <cstring>
#include <ctype.h>

String::String() {
	m_string = nullptr;
	m_string = new char[0];
	m_size = 0;
	m_capacity = 0;
}

String::String(char input[]) {
	int length = strlen(input);
	m_string = nullptr;
	m_string = new char[length + 1];
	strcpy(m_string, input);
	m_capacity = length + 1;
	m_size = length;

}
String::String(int size)
{
	m_string = new char[size + 1];
	m_capacity = size + 1;
	m_size = size;
	m_string[0] = '\0';
}

String::String(String & other)
{
	m_string = nullptr;
	*this = other;
}


String::~String()
{
	m_string = nullptr;
	delete[]m_string;
}


int String::Length() {
	return std::strlen(m_string);
}

bool String::operator==(String & other)
{

	if (strcmp(m_string, other.m_string) == 0)
		return true;
	else
		return false;

}

bool String::operator==(const char * other)
{
	if (strcmp(m_string, other) == 0)
		return true;
	else
		return false;

}

char* String::operator[](const int location) {

	if (this->Length() >= location && location >= 0)
		return &m_string[location];
	else
		return nullptr;


}

String String::toLower()
{
	String temp = m_string;
	for (int i = 0; i < m_size; i++)
	{
		temp.m_string[i] = tolower(*temp[i]);
	}
	return temp;
}

String String::toUpper()
{
	String temp = m_string;
	for (int i = 0; i < m_size; i++)
	{
		temp.m_string[i] = toupper(*temp[i]);
	}

	return temp;
}
void String::resize(int newSize)
{
	String temp(newSize);
	strcpy(temp.m_string, m_string);
	*this = temp;
}

void String::operator=(char string[])
{
	int length = strlen(string);
	if (length >= m_capacity) {
		resize(length);
		strcpy(m_string, string);
	}
	else {
		m_size = length;
		strcpy(m_string, string);
	}
}
void String::operator=(String & other)
{
	if (m_string != nullptr) {
		delete[]m_string;
	}
	m_string = new char[other.m_capacity];
	m_size = other.m_size;
	m_capacity = other.m_capacity;
	strcpy(m_string, other.m_string);

}

void String::operator+=(const String & other)
{
	if (!(m_capacity > (int)(strlen(m_string) + strlen(other.m_string))))
	{
		resize(m_size + other.m_size);
	}
		strcat(m_string, other.m_string);

}
void String::operator+=(const char* other)
{
	if (!(m_capacity > (int)(strlen(m_string) + strlen(other))))
	{
		resize(m_size + strlen(other));
	}
	strcat(m_string, other);
}

String String::operator+(const String & other)
{
	String temp(*this);
	temp += other;
	return temp;
}

String String::operator+(const char * other)
{
	String temp(m_string);
	temp += other;
	return temp;
}

char* String::subStringFind(const char * subString)
{
	return strstr(m_string, subString);
}
char* String::subStringFind(const char * subString, int location)
{
	return strstr(m_string + location, subString);
}

void String::subStringReplace(const char * subString, char* replacement)
{
	char * temp = this->subStringFind(subString);
	if (temp != nullptr) {
		int subLen, repLen;
		subLen = strlen(subString);
		repLen = strlen(replacement);
		if (subLen == repLen)
			strncpy(temp, replacement, repLen);
		else {
			String temp3p[3];
			int tempNum;
			int counter = 0;
			for (int i = 0; i < m_size; i++)
			{
				if (m_string[i] == subString[0])
				{

					for (int k = 0; k < subLen; k++)
					{
						if (m_string[i + k] == subString[k]) {
							counter++;
						}
					}
					if (counter = subLen)
					{
						tempNum = i;
						break;
					}

				}
			}
			temp3p[0].resize(m_size + repLen - subLen);
			temp3p[0] = m_string;
			temp3p[0].m_string[tempNum] = '\0';
			temp3p[0].m_size = tempNum;
			temp3p[1] = replacement;
			temp3p[2].resize(m_size + 1);
			temp3p[2].m_size = 0;
			temp3p[2].m_string = temp + subLen;
			temp3p[2].m_size = temp3p[2].Length();
			temp3p[0] += replacement;
			temp3p[0].m_string[tempNum + repLen] = '\0';
			temp3p[0].m_size = tempNum + repLen;
			temp3p[0] += temp3p[2];
			temp3p[0].m_size = temp3p[0].Length();
			*this = temp3p[0];
		}

	}
}

const char * String::get()
{
	return m_string;
}

String operator + (char lhs[], String rhs) {
	String temp(lhs);
	temp += rhs;
	return temp;
	
}
