#include<iostream>
using namespace std;
#define delimeter "\n===================================\n"

class String
{
	int size; //size of string in Bytes
	char* str; //address of string in dynamic memory
public:
	//INCAPSULATION
	const char* get_()const
	{
		return str;
	}
	char* get_()
	{
		return str;
	}
	int get_s()const
	{
		return size;
	}
	explicit String(int size = 80)
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
	//COPY CONSTRUCTOR
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i<size; i++)str[i] = other.str[i];
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
		cout << "Obj:\t" << size << "\t";
		cout << "Size:\t" << size <<"\t";
		cout << "Str:\t" << str << "\t";
		cout << "Addr:\t" << &str <<"\t";
		cout << endl;
	}
	// OPERATORS
	String& operator=(const String& other)
	{
		if (this == &other) return *this;
		delete[] str;
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
#define checking

#ifdef checking
	setlocale(LC_ALL, "Russian");
	String str1 = "Hello";
	String str2 = "World";
	String str;
	str = str1 + str2;
	cout << str1 << endl;
	cout << str2 << endl;
	cout << str << endl;
#endif 
}
std::ostream& operator << (std::ostream& os, const String& obj)
{
	return os << obj.get_();
}
String operator+(const String& left, const String& right)
{
	String buff(left.get_s() + right.get_s() - 1);
	for (int i = 0; i < left.get_s(); i++)buff.get_()[i] = left.get_()[i];
	for (int i = 0; i < right.get_s(); i++)buff.get_()[i + left.get_s()-1] = *(right.get_() + i);
	return buff;
}
