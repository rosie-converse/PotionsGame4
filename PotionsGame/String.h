/******************STRING CLASS*****************
This is a custom string class with one data member,
m_str, and various member functions that provide the
functionality normally found in the built-in string
class. These member functions are: default ctor,
1 arg ctor, 2 arg ctor, copy ctor, operator-equals,
dtor, a version of ".c_str()" that returns a const char
pointer, a getter that returns the String, a setter that
receives a const char pointer, string upper/lower,
and a display function */

#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
using std::ofstream;
using std::ifstream;
using std::fstream;


class String
{
public:
	String();
	String(char ch);
	String(const char* str);
	String(const String& copy);
	~String();
	String& operator =(const String& rhs);

	const char* my_str(); //.c_str()
	String getString() const;
	void setString(const char* str);

	char* StringUpper(char* str);
	char* StringLower(char* str);

	void Display() const;


private:

	char* m_str;


};
