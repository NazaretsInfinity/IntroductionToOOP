#include<iostream>
using namespace std;
#define STRUCT_POINT1
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
	double distance(double x, double y)  // meth
	{
		double c1= this->x - x;
		double c2 = this->y - y;
		return (c1 * c1 + c2 * c2);
	}
};
       double distance(Point A, Point B); // func

void main()
{
#ifdef STRUCT_POINT
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
#endif // 
	Point A, B;
	B.set_x(4);
	B.set_y(0);
	A.set_x(4);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;

	cout << A.distance(0,0) << endl; 
	cout << A.distance(B.get_x(), B.get_y()) << endl;

	cout << distance(A,B) << endl;
	}
double distance(Point A, Point B)
{
	double x = A.get_x() - B.get_x();
	double y = A.get_y() - B.get_y();
	return (x * x + y * y);
}
