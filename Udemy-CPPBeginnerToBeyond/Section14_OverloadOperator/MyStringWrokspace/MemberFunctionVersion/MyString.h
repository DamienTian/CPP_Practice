/*
	MyString class (Member function version)
	Writen by Hao Tian
	Note: 
		1) Include lecture contents and challenge content
		2) Overloaded all possible operators as Member functions, except:
			- insertion and extraction operation
			- string index operator
*/

#ifndef MYSTRING_H
#define MYSTRING_H
#pragma once

#include <iostream>
#include <cstring>

class MyString  
{
private:
	char* str;
public:
	// No Overloading constructor
	MyString();
	// Overloading constructor
	MyString(const char* str);
	// Copy Constructor
	MyString(const MyString& mystring);
	// Move Constructor
	MyString(MyString&& mystring);
	// Destructor
	~MyString();

	// Copy assignment
	MyString& operator=(const MyString& rhs);
	// Move assignment
	MyString& operator=(MyString&& rhs);
	// Index str (overload operator [])
	char& operator[](int index);

	int getLength();
	const char* getString();

	// To lower case (overload operator -)
	MyString operator-();
	// Concatenate MyString (overload operator +)
	MyString operator+(const MyString& rhs);
	// Concatenate MyString (overload operator +=)
	MyString& operator+=(const MyString& rhs);
	// Duplicate MyString and concatenate them together (overload operator *)
	MyString operator*(int time);
	// Duplicate this MyString and concatenate them together (overload operator *=)
	MyString& operator*=(int time);
	// Compare two MyString are equal (overload operator ==)
	bool operator==(const MyString& rhs);
	// Compare two MyString are not equal (overload operator !=)
	bool operator!=(const MyString& rhs);
	// Compare if lhs string is lexically less than the rhs string (overload operator <)
	bool operator<(const MyString& rhs);
	// Compare if lhs string is lexically greater than the rhs string (overload operator >)
	bool operator>(const MyString& rhs);
	// Change Stream to uppercase (pre-increment, overload operator ++)
	MyString& operator++();
	// Change Stream to uppercase (post-increment, overload operator ++)
	MyString operator++(int);
	// Change Stream to lowercase (pre-increment, overload operator --)
	MyString& operator--();
	// Change Stream to lowercase (post-increment, overload operator --)
	MyString operator--(int);

	// Stream insertion (overload operator << as friend globally)
	friend std::ostream& operator<<(std::ostream& os, const MyString& myString); 
	// Stream extraction (overload operator >> as friend globally)
	friend std::istream& operator>>(std::istream& is, MyString& myString); 
};
#endif