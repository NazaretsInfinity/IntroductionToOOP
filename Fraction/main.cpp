#include<iostream>
#include"Fraction.h"
using namespace std; 
#define delimeter "\n-----------------------------------\n"
#define dbldelimeter "\n==================================\n"
void main()
{
#define ConstructorCheck
#define OperatorCheck
#define StreamCheck
#define conversion_from_other_to_class
#define conversion_from_class_to_other
#define conversionTask

#ifdef ConstructorCheck1
	setlocale(LC_ALL, "");
	Fraction A;
	A.print();
	Fraction B(5);
	B.print();
	Fraction C = (1, 2);
	C.print();
	Fraction D(2, 3, 4);
	D.print();
	Fraction F(2, 5);
	F.print();
#endif
#ifdef OperatorCheck1
	Fraction A(-1, 2, 3);
	Fraction B(1, 3);
	A.print();
	B.print();
	A *= B;
	A /= B;
	A.reduce();
	A.print();
#endif
#ifdef StreamCheck1
	Fraction A(2, 3, 4);
	cout << "Enter your fraction: "; cin >> A;
	cout << "Fraction: " << A << endl;
#endif
#ifdef conversion_from_other_to_class1
	Fraction A = (Fraction)5;
	cout << A;
	cout << delimeter;
	Fraction B;
	B = Fraction(8);
	cout << dbldelimeter;
	cout << B;
#endif 
#ifdef conversionTask1
	Fraction A(2,3,4);
	cout << A << endl;
	double a = A;
	cout << a << endl;
#endif 
#ifdef conversionTask2
	Fraction B = 3.10001;
	cout << B << endl;
#endif
}