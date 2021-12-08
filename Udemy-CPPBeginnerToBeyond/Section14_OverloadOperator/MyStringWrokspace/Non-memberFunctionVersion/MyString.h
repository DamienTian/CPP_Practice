/*
	MyString class (Non-member function version)
	Writen by Hao Tian
	Note: 
		1) Include lecture contents and challenge content
		2) Overloaded all possible operator as non-member functions, except:
			- string index operator
*/

#ifndef MYSTRING_H
#define MYSTRING_H
#pragma once

#include <iostream>
#include <cstring>

/* 
Challenge TODO-list:
【X】!= (MyString): return true if two MyString are not equal
【X】* (int): copy string and concatenate them together
【X】*= (int): copy current string and concatenate them together
【X】+= (MyString): concatenate
【X】> and < (MyString): compare if lhs string is lexically greater or less than the rhs string
【X】[] (MyString): index MyString char in string
【X】++ (pre and post): change string to upper case
【X】-- (pre and post): change string to lower case
*/

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

	// To lower case (overload operator - as friend globally)
	friend MyString operator-(const MyString& myString);
	// Concatenate MyString (overload operator + as friend globally)
	friend MyString operator+(const MyString& lhs, const MyString& rhs);
	// Concatenate MyString (overload operator += as friend globally)
	friend MyString& operator+=(MyString& lhs, const MyString& rhs);
	// Duplicate MyString and concatenate them together (overload operator * as friend globally)
	friend MyString operator*(const MyString& lhs, int time);
	// Duplicate this MyString and concatenate them together (overload operator *= as friend globally)
	friend MyString& operator*=(MyString& lhs, int time);
	// Compare two MyString are equal (overload operator == as friend globally)
	friend bool operator==(const MyString& lhs, const MyString& rhs);
	// Compare two MyString are not equal (overload operator != as friend globally)
	friend bool operator!=(const MyString& lhs, const MyString& rhs);
	// Compare if lhs string is lexically less than the rhs string (overload operator < as friend globally)
	friend bool operator<(const MyString& lhs, const MyString& rhs);
	// Compare if lhs string is lexically greater than the rhs string (overload operator > as friend globally)
	friend bool operator>(const MyString& lhs, const MyString& rhs);
	// Stream insertion (overload operator << as friend globally)
	friend std::ostream& operator<<(std::ostream& os, const MyString& myString); 
	// Stream extraction (overload operator >> as friend globally)
	friend std::istream& operator>>(std::istream& is, MyString& myString); 
	// Change Stream to uppercase (pre-increment, overload operator ++ as friend globally)
	friend MyString& operator++(MyString& myString);
	// Change Stream to uppercase (post-increment, overload operator ++ as friend globally)
	friend MyString operator++(MyString& myString, int);
	// Change Stream to lowercase (pre-increment, overload operator -- as friend globally)
	friend MyString& operator--(MyString& myString);
	// Change Stream to lowercase (post-increment, overload operator -- as friend globally)
	friend MyString operator--(MyString& myString, int);
};
#endif