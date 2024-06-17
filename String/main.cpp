#include<iostream>
#include"String.h"
using namespace std;
#define delimeter "\n===================================\n"

#define cat_check
#define constructorCheck
void main()
{
#ifdef constructorCheck1
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
	str6.print();

#endif

#ifdef cat_check
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


