#pragma once
#include<iostream>
using namespace std;
#define delimeter "\n-----------------------------------\n"
#define dbldelimeter "\n==================================\n"
class Fraction;
Fraction operator*(Fraction A, Fraction B);
Fraction operator+(const Fraction& A, const Fraction& B);
Fraction operator/(const Fraction& A, Fraction B);
class Fraction
{
	int intpart;
	int num;
	int den;
public:
	// INCAPSULATION
	int getNUM()const;
	int getDEN()const;
	int getINT()const;
	void setNUM(int num);
	void setDEN(int den);
	void setINT(int intpart);
	// CONSTRUCTOR
	Fraction();
	Fraction(int numenator, int denominator);
	explicit Fraction(int intpart);
	Fraction(double decimal);
	Fraction(int intpart, int numenator, int denominator);
	Fraction(const Fraction& other);
	//DESTRUCTOR
	~Fraction();
	// TYPE CAST OPERATORS
	explicit operator int();
	operator double();
	// METHODS
	Fraction& reduce();
	Fraction& to_improper();
	Fraction& to_proper();
	Fraction inverted();
	void print()const;
	//OPERTORS
	Fraction& operator=(const Fraction& other);
	Fraction& operator++();
	Fraction operator++(int);

	Fraction& operator--();
	Fraction& operator--(int);
	Fraction& operator+=(const Fraction& other);
	Fraction& operator-=(Fraction other);
	Fraction& operator*=(const Fraction& other);
	Fraction& operator/=(const Fraction& other);
};
bool operator==(const Fraction& A, const Fraction& B);
bool operator!=(const Fraction& A, const Fraction& B);
bool operator>(const Fraction& A, const Fraction& B);
bool operator<(const Fraction& A, const Fraction& B);
bool operator>=(const Fraction& A, const Fraction& B);
bool operator<=(const Fraction& A, const Fraction& B);
std::ostream& operator << (std::ostream& cout, const Fraction& obj);
std::istream& operator >> (std::istream& in, Fraction& obj);
