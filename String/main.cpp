#include<iostream>
using namespace std;
#define delimeter "\n===================================\n"

class String
{
	int size; //size of string in Bytes
	char* str; //address of string in dynamic memory
public:
	String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefaultConstructor:\t" << this << endl;
	}
	String(const char arr[])
	{
		int i = 0;
		while (arr[i] != '\0')i++;
		size = i;

		this->str = new char[size];
		for (int i = 0; i < size; i++)str[i] = arr[i];
	}
	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t\t" << this << endl;
	}
	//METHODS
	char* get_()const
	{
		return str;
	}
	int get_s()const
	{
		return size;
	}
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
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
	for (int i = 0; i < obj.get_s(); i++)os << *(obj.get_() + i);
	return os;
}
String operator+(const String& str1, const String& str2)
{
	int newsize = str1.get_s() + str2.get_s();
	String str = newsize;
	for (int i = 0; i < str1.get_s(); i++)*(str.get_() + i) = *(str1.get_() + i);
	for (int i = str1.get_s(); i < newsize; i++)*(str.get_() + i) = *(str2.get_() + (i - str1.get_s()));
	return str;
}
