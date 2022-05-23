#define _CRT_SECURE_NO_WARNINGS

#include <exception>
using std::bad_alloc;

#include <iostream>
using std::cout;
using std::endl;

#include <fstream>
using std::ofstream;
using std::ifstream;
using std::fstream;

#include "String.h"

/***********DEFAULT CTOR******
This member function will initialize a string to
nullptr*/
String::String() : m_str(nullptr)//this is the default ctor (colon init list)
{

}

/***********1 ARG CTOR (CHAR)******
This member function will accept a char and
initialize it to nullptr */
String::String(char ch) : m_str(nullptr)
{
}

/***********1 ARG CTOR (STRING)******
This member function will accept a const char *
and initialize m_str to nullptr. Then, if the str
pased in is not "empty," the function will copy the
contents of str into m_str*/
String::String(const char* str) : m_str(nullptr)//one arg ctor
{

	if (str != nullptr)
	{
		try
		{
			m_str = new char[strlen(str) + 1];//create memory for str
			strcpy(m_str, str);//copy str into your pointer string
		}

		catch (bad_alloc err)
		{
			cout << "Error during memory allocation: " << err.what() << endl;
			delete[] m_str;
			m_str = nullptr;

			
			abort(); 
		}
	}

}

/***********COPY CTOR**********
This member function will initialize m_str to
nullptr and copy the contents of a string passed in
over to m_str, as long as the string passed in is
not nullptr (empty)*/
String::String(const String& copy) : m_str(nullptr)
{

	if (copy.m_str != nullptr)
	{
		try
		{
			m_str = new char[strlen(copy.m_str) + 1];//deep copy
			strcpy(m_str, copy.m_str);
		}

		catch (bad_alloc err)
		{
			cout << "An error occurred during duplication: " << err.what() << endl;
			delete[] m_str;
			m_str = nullptr;

			abort();
			
		}


	}


}

/**********DTOR ************
This member function will deallocate any memory
created for the String object, and then set the
m_str to a known value of nullptr*/
String::~String()//dtor
{
	delete[] m_str;
	m_str = nullptr;//set to known value!!
}

/***********OPERATOR EQUALS******
This member function will copy the contents of
one string's m_str into the left-hand (this)
string's m_str. It will ensure that no self-
assignment occurs by checking the address of the
string to copy, and if there is no self-assignment
it will perform a deep copy*/
String& String::operator=(const String& rhs)
{

	if (this != &rhs)//if this (left hand side) address is NOT equal to the right hand side (rhs), it means you haven't self-copied (same address on two objects)
	{
		//2. delete left hand side

		delete[] m_str;

		//3. perform deep copy

		if (rhs.m_str != nullptr)//ensure not equal to null
		{
			m_str = new char[strlen(rhs.m_str) + 1];//if not equal to null, do the deep copy
			strcpy(m_str, rhs.m_str);
		}
		else
		{
			m_str = nullptr;//otherwise, set it to null
		}
	}


	//4. return the object as reference

	return *this;
}

/***********MY_STRING******
This member function will return a const char
pointer to m_str, to serve as a version of
the .c_str() member function of the built-in
string class*/
const char* String::my_str()
{

	return m_str;
}

/***********GET STRING******
This member function will return the m_str
string*/
String String::getString() const
{
	return m_str;
}

/***********SET STRING******
This member function will accept a const
char pointer and will use the str provided
as m_str's new string*/
void String::setString(const char* str)
{

	delete[] m_str;
	m_str = nullptr;
	if (str != nullptr)
	{
		m_str = new char[strlen(str) + 1];
		strcpy(m_str, str);

	}

}

/***********STRING UPPER******
This member function will accept a pointer
to the string and iterate over that string,
checking to see if the current character is
a lowercase char. If it's lowercase, the
function will subtract 32 to convert the char to
an uppercase character.*/
char* String::StringUpper(char* str)
{
	int pos = 0;
	//check for already upper  
	while (*(str + pos) != '\0') //....
	{
		if (*(str + pos) > 96 && *(str + pos) < 123)
		{
			*(str + pos) -= 32;
		}
		++pos; //move to the next letter
	}

	return str;

}

/***********STRING LOWER******
This member function will accept a pointer to
the string, and iterate over the string checking
each character and converting it to a lowercase
character if necessary.*/
char* String::StringLower(char* str)
{
	int pos = 0;

	while (*(str + pos) != '\0')
	{
		if (*(str + pos) > 64 && *(str + pos) < 91)
		{
			*(str + pos) += 32;//convert to lower
		}

		++pos;
	}

	return str;
}

/*********** DISPLAY ******
This member function will display the string
in m_str*/
void String::Display() const
{
	cout << m_str;

	//print the current string

}



