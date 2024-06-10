#define _CRT_SECURE_NO_WARNINGS
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
	explicit Fraction(int intpart)
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
	// TYPE CAST OPERATORS
	explicit operator int()
	{
		return intpart;
	}
	operator double()
	{
		return intpart + (double)num / den;
	}
	// METHODS
	Fraction& reduce()
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
	Fraction& to_improper()
	{
		num = intpart * den + (intpart >= 0 ? num : -num);
		intpart = 0;
		return *this;
	}
	Fraction& to_proper()
	{
		intpart = num / den;
		if (intpart >= 0)num %= den;
		else num = -num % den;
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
		return *this = *this + other;
	}
	Fraction& operator-=(Fraction other)
	{
		this->to_improper(); other.to_improper();
		this->num = num * other.den - other.num * den;
		this->den *= other.den;
		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}
};
bool operator==(const Fraction& A, const Fraction& B);
bool operator!=(const Fraction& A, const Fraction& B);
bool operator>(const Fraction& A, const Fraction& B);
bool operator<(const Fraction& A, const Fraction& B);
bool operator>=(const Fraction& A, const Fraction& B);
bool operator<=(const Fraction& A, const Fraction& B);
std::ostream& operator << (std::ostream& cout, const Fraction& obj);
std::istream& operator >> (std::istream& in, Fraction& obj);
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
	F.selint();
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
#ifdef conversionTask
	Fraction A(2,3,4);
	cout << A << endl;
	double a = A;
	cout << a << endl;
#endif 
#ifdef conversionTask2
	Fraction B = 23.7555;
	cout << B << endl;
#endif
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
// COMPRASION buddies
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
