#include"String.h"

/////////////////////////////
///// CLASS DEFINITION /////
const char* String::get_()const
{
	return str;
}
char* String::get_()
{
	return str;
}
int String::get_s()const
{
	return size;
}
String::String(int size) : size(size), str(new char[size] {})
{
	cout << "DefaultConstructor:\t" << this << endl;
}
String::String(const char arr[]) : String(strlen(arr) + 1)
{
	for (int i = 0; arr[i]; i++)str[i] = arr[i];
	cout << "Constructor:\t\t" << this << endl;
}
//COPY CONSTRUCTOR
String::String(const String& other) : String(other.str) // we have this so we don't need code lower(except cout, oc)
{
	cout << "CopyConstructor:\t\t" << this << endl;
}
String::~String()
{
	delete[] this->str;
	cout << "Destructor:\t\t" << this << endl;
}
//METHODS
void String::print()const
{
	cout << "Obj:\t" << this << "\t";
	cout << "Size:\t" << size << "\t";
	cout << "Str:\t" << str << "\t";
	cout << "Addr:\t" << &str << "\t";
	cout << "\n\n";
}
// OPERATORS
String& String::operator=(const String& other)
{
	if (this == &other) return *this;
	delete[] str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; other.str[i]; i++)str[i] = other.str[i];
	cout << "CopyAssignment:\t\t" << this << endl;
	return *this;
}


String operator+(const String& left, const String& right)
{
	String buff(left.get_s() + right.get_s() - 1);
	for (int i = 0; i < left.get_s(); i++)buff.get_()[i] = left.get_()[i];
	for (int i = 0; i < right.get_s(); i++)buff.get_()[i + left.get_s() - 1] = *(right.get_() + i);
	return buff;
}
std::ostream& operator << (std::ostream& os, const String& obj)
{
	return os << obj.get_();
}
/// END OF CLASS DEFINITION ///
//////////////////////////////