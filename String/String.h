#pragma once
#include<iostream>
using namespace std;
// CLASS DECLARATION //
class String
{
	int size; //size of string in Bytes
	char* str; //address of string in dynamic memory
public:
	//INCAPSULATION
	const char* get_()const;
	char* get_();
	int get_s()const;
	//Default constructor
	explicit String(int size = 80);
	//SnglArgConstructor
	String(const char arr[]);
	//CopyConstructor
	String(const String& other);
	// Destructor
	~String();
	//METHODS
	void print()const;
	// OPERATORS
	String& operator=(const String& other);
};
String operator+(const String& left, const String& right);
std::ostream& operator << (std::ostream& os, const String& obj);

