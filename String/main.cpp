#include<iostream>
using namespace std;
#define delimeter "\n===================================\n"

class String
{
	int size; //size of string in Bytes
	char* str; //address of string in dynamic memory
public:
	//INCAPSULATION
	const char* get_()const;
	char* get_();
	int get_s()const;
	explicit String(int size = 80);
	String(const char arr[]);
	//COPY CONSTRUCTOR
	String(const String& other);
	~String();
	//METHODS
	void print()const;
	// OPERATORS
	String& operator=(const String& other);
};
//INCAPSULATION
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
	//this->size = size; defined upper
	//this->str = new char[size] {};
	cout << "DefaultConstructor:\t" << this << endl;
}
String::String(const char arr[]) : String(strlen(arr) + 1)
{
	//this->size = strlen(arr) + 1;
	//this->str = new char[size] {};
	for (int i = 0; arr[i]; i++)str[i] = arr[i];
	cout << "Constructor:\t\t" << this << endl;
}
//COPY CONSTRUCTOR
String::String(const String& other) : String(other.str) // we have this so we don't need code lower(except cout, oc)
{
	//this->size = other.size;
	//this->str = new char[size] {};
	//for (int i = 0; i<size; i++)str[i] = other.str[i];
	cout << "CopyConstructor:\t\t" << this << endl;
}
String::~String()
{
	delete[] this->str;
	cout << "Destructor:\t\t" << this << endl;
}
//METHODS
void String:: print()const
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


String operator+(const String& str1, const String& str2);
std::ostream& operator << (std::ostream& os, const String& obj);

#define cat_check
#define constructorCheck
void main()
{
#ifdef constructorCheck
	String str1; //default constructor
	str1.print();

	String str2(8); // single argument constructor( default actually for this code)
	str2.print();

	String str3 = "Hello";// single argument constructor(take array as prmtr)
	str3.print();

	String str4(); // function , not object because of (). Takes no prmtrs, yet return object of type String
	

	String str5{}; // explicit call of default constructor
	str5.print();

	String str6{ str3 }; // Copy constructor

#endif

#ifdef cat_check1
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
