#include<iostream>
using namespace std;
#define delimeter "\n-----------------------------------\n"
class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		//x = -2; //must be a modifiable value
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	// CONSTRUCTORS
	Point()
	{
		x = y = 0;
		cout << "DefaultConstructor: \t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "Single argument constructor " << this << endl;
	}
	Point(double x,double y)
	{
		this->x = x;
		this->y = y;
		cout << "constructor " << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "Copy constructor " << this << endl;
	}
	// DESTRUCTOR
	~Point()
	{
		cout << "Destructor: \t" << this << endl;
	}
	// OPERATORS
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	Point& operator++() // prefix increment
	{
		x++;
		y++;
		return *this;
	}
	Point operator++(int) //postfix(suffix) increment
	{
		Point old = *this;
		x++;
		y++;
		return old;
	}
	// METHODS
	double distance(const Point& other)const  // meth
	{
		double c1= this->x - other.x;
		double c2 = this->y - other.y;
		return sqrt(c1 * c1 + c2 * c2);
	}
	void print()const
	{
		cout << this << ": " << "x = " << x << "\ty = " << y << endl;
	}
};
Point operator+(const Point& A, const Point& B);
Point operator-(const Point& A, const Point& B);
Point operator*(const Point& A, const Point& B);
bool operator==(const Point& A, const Point& B);
double distance(const Point& A, const Point& B); 
#define STRUCT_POINT
#define DistanceCheck
#define ConstructorsCheck
#define AssignmentCheck
#define operatorsARIPHMETICALcheck

void main()
{
#ifdef STRUCT_POINT1
	setlocale(LC_ALL, "Russian");
	int a; //  declartion of var 'a' with type 'int'
	Point A; // declaration of var 'A' with type 'Point'
	// creation of object 'A' with structure 'point'
	A.x = 2;
	A.y = 3;
	Point* pA = &A; // pointer to 'A'
	cout << pA->x << "\t" << pA->y << endl;
	cout << sizeof(A) << endl; // 2 doubles  = 16 bytes
	cout << sizeof(Point) << endl; // same with line higher  
#endif 
#ifdef DistanceCheck1
	Point A, B;
	B.set_x(7);
	B.set_y(8);
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	cout << B.get_x() << "\t" << B.get_y() << endl;
	cout << delimeter;
	cout << A.distance(B) << endl;
	cout << delimeter;
	cout << B.distance(A) << endl;

	cout << delimeter;
	cout << distance(A,B) << endl;
	cout << delimeter;
#endif
#ifdef ConstuctorsCheck1
	Point A;
	A.print();
	Point B = 5;
	B.print();
	Point C(2, 3);
	C.print();
	Point D = C; // copy constructor
	D.print();
#endif
	//Point A(2, 3); //construcor
	//Point B; //default constructor
	//B = A; //operator Copy Assignment
	//B.print();
#ifdef AssignmentCheck1
    
	Point A, B, C;
	cout << delimeter;
	A = B = C = Point(2, 3);
	A.print();
	B.print();
	C.print();
	cout << delimeter;
#endif 
#ifdef operatorsARIPHMETICALcheck1
	Point A(2, 3);
	Point B(7, 8);
	Point C = A * B;
	C.print();
	A.print();
	B.print();
	C++;
	C.print();
#endif
	//cout << (2 == 3);
	cout << (Point(2,3) == Point(2,3)) << delimeter;
}
double distance(const Point& A,const Point& B)
{
	double x = A.get_x() - B.get_x();
	double y = A.get_y() - B.get_y();
	return sqrt(x * x + y * y);
}
Point operator+(const Point& A, const Point& B)
{
	Point result;
	result.set_x(A.get_x() + B.get_x());
	result.set_y( A.get_y() + B.get_y());
	return result;
}
Point operator-(const Point& A, const Point& B)
{
	//return Point(A.get_x() - B.get_x(), A.get_y() - B.get_y());
	Point result
	(
		A.get_x() - B.get_x(),
		A.get_y() - B.get_y()
	);
	return result;
}
Point operator*(const Point& A, const Point& B)
{
	return Point(A.get_x() * B.get_x(), A.get_y() * B.get_y());
}
bool operator==(const Point& A, const Point& B)
{
	return A.get_x() == B.get_x() && A.get_y();;
}

