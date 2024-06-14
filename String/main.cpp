#include<iostream>
using namespace std;
#define delimeter "\n===================================\n"

class String
{
	int size; //size of string in Bytes
	char* str; //address of string in dynamic memory
public:
	//INCAPSULATION
	char* get_()const
	{
		return str;
	}
	int get_s()const
	{
		return size;
	}
	String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefaultConstructor:\t" << this << endl;
	}
	String(const char arr[])
	{
		this->size = strlen(arr) + 1;
		this->str = new char[size] {};
		for (int i = 0; arr[i]; i++)str[i] = arr[i];
		cout << "Constructor:\t\t" << this << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; other.str[i]; i++)str[i] = other.str[i];
		cout << "CopyConstructor:\t\t" << this << endl;
	}
	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t\t" << this << endl;
	}
	//METHODS
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
	// OPERATORS
	String& operator=(const String& other)
	{
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; other.str[i]; i++)str[i] = other.str[i];
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
};
String operator+(const String& str1, const String& str2);
std::ostream& operator << (std::ostream& os, const String& obj);
void main()
{
	setlocale(LC_ALL, "Russian");
	String str1 = "Hello";
	String str2 = "World";
	cout << str1 << endl;
	cout << str2 << endl;

	String str = str1 + str2;
	cout << str << endl;
}
std::ostream& operator << (std::ostream& os, const String& obj)
{
	return os << obj.get_();
}
String operator+(const String& str1, const String& str2)
{
	int newsize = str1.get_s() + str2.get_s();
	String str = newsize-1;
	for (int i = 0; i < str1.get_s(); i++) *(str.get_() + i) = *(str1.get_() + i);
	for (int i = str1.get_s()-1, d=0 ; i < newsize; i++,d++) *(str.get_() + i) = *(str2.get_()+d); 
	return str;
}
