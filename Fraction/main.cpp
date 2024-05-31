#include<iostream>
using namespace std;
#define delimeter "\n-----------------------------------\n"
class Fraction
{
	int intpart;
	int num;
	int den;
public:
	      // incapsulation stuff
int getNUM()const
{
	return num;
}
int getDEN()const
{
	return den;
}
int getINT()const
{
	return intpart;
}
          // CONSTRUCTOR
Fraction()
{
    	intpart = num = 0;
		den = 1;
		cout << "DefaultConstructor: \t" << this << endl;
}
Fraction(int intpart, int numenator, int denominator)
{
	this->intpart = intpart;
	this->num = numenator;
	if (denominator == 0)
	{
		cout << this <<  ": Can't have 0 as a denominator" << endl;
		this->den = 1;
	}
	else this->den = denominator;
	cout << "Constructor: \t" << this << endl;
}
         //DESTRUCTOR
~Fraction()
{
	cout << "Destructor: " << this << endl;
}
         // METHODS
void simplify()
{
	for (int i = (abs(num) < abs(den) ? abs(num) : abs(den));i>0;i--)
	if(num % i == 0 && den % i == 0)
		{
			num /= i;
			den /= i;
			break;
		}
}
void delint()
{
	num = intpart * den+(intpart >= 0? num:-num);
	intpart = 0;
}
void print()const
{
	if (intpart != 0)cout << intpart << " ";
	cout << num << "/" << den << " " <<  this << endl;
}
};
Fraction operator+(const Fraction& A, const Fraction& B);
void main()
{
	Fraction A(0,-2000, 3000);
	A.simplify();
	A.print();
	A.delint();
	A.print();
}
Fraction operator+(const Fraction& A, const Fraction& B)
{
	return Fraction
	(
		A.getINT() + B.getINT(), 
		B.getDEN()* A.getNUM()+ A.getDEN() * B.getNUM(),
		A.getDEN() * B.getDEN()
	);
}
