#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include"Fraction.h"
// INCAPSULATION
int Fraction::getNUM()const
{
	return num;
}
int Fraction::getDEN()const
{
	return den;
}
int Fraction::getINT()const
{
	return intpart;
}
void Fraction::setNUM(int num)
{
	this->num = num;
}
void Fraction::setDEN(int den)
{
	if (den == 0)this->den = 1;
	else this->den = den;
}
void Fraction::setINT(int intpart)
{
	this->intpart = intpart;
}
// CONSTRUCTOR
Fraction::Fraction()
{
	intpart = 0;
	num = 0;
	den = 1;
	cout << "DefaultConstructor: \t" << this << endl;
}
Fraction::Fraction(int numenator, int denominator)
{
	intpart = 0;
	num = numenator;
	this->setDEN(denominator);
	cout << "Constructor(NoInteger): \t" << this << endl;
}
Fraction::Fraction(int intpart)
{
	this->intpart = intpart;
	num = 0;
	den = 1;;
	cout << "Constructor(NoFraction): \t" << this << endl;
}
Fraction::Fraction(double decimal)
{
	decimal += 1e-10;
	intpart = decimal;
	decimal -= intpart;
	den = 1e+9;
	num = decimal * den;
	this->reduce();
	cout << "constructor:\t " << this << endl;
}
Fraction::Fraction(int intpart, int numenator, int denominator)
{
	this->intpart = intpart;
	this->num = numenator;
	setDEN(denominator);
	cout << "Constructor: \t" << this << endl;
}
Fraction::Fraction(const Fraction& other)
{
	this->intpart = other.intpart;
	this->num = other.num;
	this->den = other.den;
	cout << "CopyConstructor: \t" << this << endl;
}
//DESTRUCTOR
Fraction::~Fraction()
{
	cout << "Destructor: " << this << endl;
}
// TYPE CAST OPERATORS
Fraction::operator int()
{
	return intpart;
}
Fraction::operator double()
{
	return intpart + (double)num / den;
}
// METHODS
Fraction& Fraction::reduce()
{
	int more, less, rest;
	if (num < den)more = num, less = den;
	else more = den, less = num;

	do
	{
		rest = more % less;
		more = less;
		less = rest;
	} while (rest);
	int GSD = more; // gsd - greatest common divisor
	num /= GSD;
	den /= GSD;
	return*this;
}
Fraction& Fraction::to_improper()
{
	num = intpart * den + (intpart >= 0 ? num : -num);
	intpart = 0;
	return *this;
}
Fraction& Fraction::to_proper()
{
	intpart = num / den;
	if (intpart >= 0)num %= den;
	else num = -num % den;
	return *this;
}
Fraction Fraction::inverted()
{
	Fraction inverted = *this;
	inverted.to_improper();
	swap(inverted.num, inverted.den);
	return inverted;
}
void Fraction::print()const
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
Fraction& Fraction::operator=(const Fraction& other)
{
	intpart = other.intpart;
	num = other.num;
	den = other.den;
	cout << "CopyAssignment: \t" << this << endl;
	return *this;
}
Fraction& Fraction::operator++()
{
	intpart++;
	return *this;
}
Fraction Fraction::operator++(int)
{
	Fraction old = *this;
	intpart++;
	return old;
}

Fraction& Fraction::operator--()
{
	if (intpart != 0)intpart--;
	else num -= den;
	return *this;
}
Fraction& Fraction::operator--(int)
{
	Fraction old = *this;
	if (intpart != 0)intpart--;
	else num -= den;
	return old;
}
Fraction& Fraction::operator+=(const Fraction& other)
{
	return *this = *this + other;
}
Fraction& Fraction::operator-=(Fraction other)
{
	this->to_improper(); other.to_improper();
	this->num = num * other.den - other.num * den;
	this->den *= other.den;
	return *this;
}
Fraction& Fraction::operator*=(const Fraction& other)
{
	return *this = *this * other;
}
Fraction& Fraction::operator/=(const Fraction& other)
{
	return *this = *this / other;
}
std::ostream& operator << (std::ostream& os, const Fraction& obj)
{
	if (obj.getINT())os << obj.getINT();
	if (obj.getNUM())
	{
		if (obj.getINT())os << "(";
		os << obj.getNUM() << "/" << obj.getDEN();
		if (obj.getINT())os << ")";
	}
	return os;
}
std::istream& operator >> (std::istream& is, Fraction& obj)
{
	const int SIZE = 64;
	char buffer[SIZE]{};
	//is >> buffer; instead the line lower.
	is.getline(buffer, SIZE); // this one
	int number[3];
	int n = 0;
	const char delimiters[] = "(/)+ ";
	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
		number[n++] = atoi(pch);
	for (int i = 0; i < n; i++)cout << number[i] << " "; cout << endl;
	switch (n)
	{
	case 1: obj = Fraction(number[0]); break;
	case 2: obj = Fraction(number[0], number[1]); break;
	case 3: obj = Fraction(number[0], number[1], number[2]); break;
	}
	return is;
}
Fraction operator+(const Fraction& A, const Fraction& B)
{
	return Fraction
	(
		A.getINT() + B.getINT(),
		B.getDEN() * A.getNUM() + A.getDEN() * B.getNUM(),
		A.getDEN() * B.getDEN()
	);
}
Fraction operator*(Fraction A, Fraction B)
{
	A.to_improper(); B.to_improper();
	return Fraction(A.getNUM() * B.getNUM(), A.getDEN() * B.getDEN()).to_proper();
}
Fraction operator/(const Fraction& A, Fraction B)
{
	return A * B.inverted();
}
bool operator==(const Fraction& A, const Fraction& B)
{
	return A.getINT() == B.getINT() &&
		B.getDEN() * A.getNUM() == A.getDEN() * B.getNUM();
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
	return !(A > B);
}
bool operator<=(const Fraction& A, const Fraction& B)
{
	return !(A < B);
}