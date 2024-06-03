#include<iostream>
using namespace std;
#define delimeter "\n-----------------------------------\n"
class Fraction
{
	int intpart;
	int num;
	int den;
public:
	      // INCAPSULATION
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
void setNUM(int num)
{
	this->num = num;
}
void setDEN(int den)
{
	if (den == 0)this->den = 1;
	else this->den = den;
}
void setINT(int intpart)
{
	this->intpart = intpart;
}
          // CONSTRUCTOR
Fraction()
{
	intpart = 0;
	num = 0;
	den = 1;
	cout << "DefaultConstructor: \t" << this << endl;
}
Fraction(int numenator, int denominator)
{
	intpart = 0;
	num = numenator;
	this->setDEN(denominator);
	cout << "Constructor(NoInteger): \t" << this << endl;
}
Fraction(int intpart)
{
	this->intpart = intpart;
	num = 0;
	den = 1;;
	cout << "Constructor(NoFraction): \t" << this << endl;
}
Fraction(int intpart, int numenator, int denominator)
{
	this->intpart = intpart;
	this->num = numenator;
	setDEN(denominator);
	cout << "Constructor: \t" << this << endl;
}
Fraction(const Fraction& other)
{
	this->intpart = other.intpart;
	this->num = other.num;
	this->den = other.den;
	cout << "CopyConstructor: \t" << this << endl;
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
Fraction& to_improper()
{
	num = intpart * den+(intpart >= 0? num:-num);
	intpart = 0;
	return *this;
}
Fraction& to_proper()
{
	intpart = num / den;
	if (intpart >= 0)num %= den;
	else num = -num%den;
	return *this;
}
Fraction inverted()
{
	Fraction inverted = *this;
	inverted.to_improper();
	swap(inverted.num, inverted.den);
	return inverted;
}
void print()const
{
	if (intpart)cout << intpart;
	if (num)
	{
		if (intpart)cout << "(";
		cout << num << "/" << den;
		if (intpart)cout << ")";
	}
	else if (intpart == 0) cout << 0;
	cout << endl;
}
         //OPERTORS
Fraction& operator=(const Fraction& other)
{
	intpart = other.intpart;
	num = other.num;
	den = other.den;
	cout << "CopyAssignment: \t" << this << endl;
	return *this;
}
Fraction& operator++() 
{
	intpart++;
	return *this;
}
Fraction operator++(int)
{
	Fraction old = *this;
	intpart++;
	return old;
}
Fraction& operator--()
{
	if (intpart != 0)intpart--;
	else num -= den;
	return *this;
}
Fraction& operator--(int)
{
	Fraction old = *this;
	if (intpart != 0)intpart--;
	else num -= den;
	return old;
}
Fraction& operator+=(const Fraction& other)
{
	this->intpart += other.intpart;
	this->num = num * other.den + other.num * den;
	this->den *= other.den;
	return *this;
}
Fraction& operator-=(Fraction other)
{
	this->to_improper(); other.to_improper();
	this->num = num * other.den - other.num * den;
	this->den *= other.den;
	return *this;
}
Fraction& operator*=(Fraction other)
{
	this->to_improper(); other.to_improper();
	num *= other.num;
	den *= other.den;
	return *this;
}
Fraction& operator/=(Fraction other)
{
	*this *= other.inverted();
	return *this;
}
};
#define ConstructorCheck
#define OperatorCheck
Fraction operator+(const Fraction& A, const Fraction& B);
Fraction operator*(Fraction A,Fraction B);
Fraction operator/(const Fraction& A,Fraction B);
bool operator==(const Fraction& A, const Fraction& B);
bool operator!=(const Fraction& A, const Fraction& B);
bool operator>(const Fraction& A, const Fraction& B);
bool operator<(const Fraction& A, const Fraction& B);
bool operator>=(const Fraction& A, const Fraction& B);
bool operator<=(const Fraction& A, const Fraction& B);
void main()
{
#ifdef ConstructorCheck1
	setlocale(LC_ALL, "");
	Fraction A;
	A.print();
	Fraction B(5);
	B.print();
	Fraction C=(1,2);
	C.print();
	Fraction D(2,3,4);
	D.print();
	Fraction F(2, 5);
	F.selint();
	F.print();
#endif
#ifdef OperatorCheck1
	Fraction A(2, 3, 4);
	A.print();
	Fraction B(3, 4, 5);
	B.print();
	Fraction C = A + B;
	C.print();
	A.print();
	B.print();
#endif
	
	Fraction A(1,2,3);
	Fraction B(2,3);
	A.print();
	B.print();
	cout << (A != B) << endl;
	//A.print();
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
Fraction operator*(Fraction A,Fraction B)
{
	A.to_improper(); B.to_improper();
	return Fraction(A.getNUM() * B.getNUM(),A.getDEN() * B.getDEN()).to_proper();
}
Fraction operator/(const Fraction& A, Fraction B)
{
	return A * B.inverted();
}
// COMPRASION buddies
bool operator==(const Fraction& A, const Fraction& B)
{
	return A.getINT() == B.getINT() &&
		B.getDEN()* A.getNUM() == A.getDEN() * B.getNUM();
}
bool operator!=(const Fraction& A, const Fraction& B)
{
	return !(A == B);
}
bool operator>(const Fraction& A, const Fraction& B)
{
	if (A.getINT() > B.getINT()) return true;
	else if (A.getINT() == B.getINT()) return B.getDEN() * A.getNUM() > A.getDEN() * B.getNUM();
	else return false;
}
bool operator<(const Fraction& A, const Fraction& B)
{
	return B > A;
}
bool operator>=(const Fraction& A, const Fraction& B)
{
	return A > B || A == B;
}
bool operator<=(const Fraction& A, const Fraction& B)
{
	return A < B || A == B;
}
