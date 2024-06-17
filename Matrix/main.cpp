#include<iostream>
using namespace std;

class Matrix
{
	int rows;
	int cols;
	int** arr;
public: 
	//INCAPSULATION
int get_rows()const
{
		return rows;
}
int get_cols()const
{
		return cols;
}
int** get_arr()const
{
		return arr;
}
	//CONSTRUCTORS;
	Matrix(int rows = 1, int cols = 1)
{
    this->rows = rows; this->cols = cols;
    arr = new int*[rows];
    for (int i = 0; i < rows; i++)arr[i] = new int[cols] {};
    cout << "DefaultConstructor:\t" << this << endl;
}
	//COPY CONSTRUCTOR
	Matrix(const Matrix& other)
{
	this->rows = other.rows;
	this->cols = other.cols;
	arr = new int* [rows];
	for (int i = 0; i < rows; i++)arr[i] = new int[cols];
	for (int i = 0; i < rows; i++)
	for (int j = 0; j < cols; j++)arr[i][j] = other.arr[i][j];
}
    // DESTRUCTOR
	~Matrix()
{
	for (int i = 0; i < rows; i++)delete[] arr[i];
	delete[] arr;
	cout << "Destructor:\t" << this << endl;
}
	//METHODS
	void print()const
	{
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++)
				cout << arr[i][j] << "  ";
			cout << endl;
		}
	}
	void fillrand()
	{
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)arr[i][j] = rand()%100;
	}
	void transpose()
	{
		int buff = rows; 
		rows = cols;
		cols = buff;
		int** res = new int* [rows];
		for (int i = 0; i < rows; i++)res[i] = new int[cols];

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)res[i][j] = arr[j][i];

        for (int i = 0; i < cols; i++)delete[] arr[i];
		delete[] arr;
		arr = res;
	}
	//OPERATORS
	Matrix& operator =(const Matrix& B)
	{
		if (this == &B) return *this;
		for (int i = 0; i < rows; i++)delete[] arr[i];
		delete[] arr;
		this->rows  = B.rows;
		this->cols = B.cols;
		arr = new int* [rows];
		for (int i = 0; i < rows; i++)arr[i] = new int[cols];
		for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)arr[i][j] = B.arr[i][j];
		cout << "CopyAssignment:\t" << this << endl;
	return *this;
	}
};
Matrix operator+(const Matrix& A, const Matrix& B);
Matrix operator-(const Matrix& A, const Matrix& B);
Matrix operator*(const Matrix& A, const Matrix& B);
std::ostream& operator << (std::ostream& os, const Matrix& obj)
{
	for (int i = 0; i < obj.get_rows(); i++) 
	{
		for (int j = 0; j < obj.get_cols(); j++)
			os << obj.get_arr()[i][j] << "  ";
		os << endl;
	}
		return os;
}
std::istream& operator >>(std::istream& is, Matrix& obj)
{
	for (int i = 0; i < obj.get_rows(); i++)
		for (int j = 0; j < obj.get_cols(); j++)
			is >> obj.get_arr()[i][j];
	return is;
}
void main()
{
#define checking
#ifdef checking
	Matrix A(2,3); Matrix B(2,2); 
	cout << "Enter Matrix A: "; cin >> A;
	cout << "Enter Matrix B: "; cin >> B;
	Matrix C = A*B;
	cout << C << endl;
#endif
}
Matrix operator+(const Matrix& A, const Matrix& B)
{
	if (A.get_rows() != B.get_rows() || A.get_cols()!=B.get_cols()) return Matrix();
	Matrix res(A.get_rows(), A.get_cols());
	for (int i = 0; i < A.get_rows(); i++)
		for (int j = 0; j < A.get_cols(); j++)res.get_arr()[i][j] = A.get_arr()[i][j] + B.get_arr()[i][j];
	return res;
}
Matrix operator-(const Matrix& A, const Matrix& B)
{
	if (A.get_rows() != B.get_rows() || A.get_cols() != B.get_cols()) return Matrix();
	Matrix res(A.get_rows(), A.get_cols());
	for (int i = 0; i < A.get_rows(); i++)
		for (int j = 0; j < A.get_cols(); j++)res.get_arr()[i][j] = A.get_arr()[i][j] - B.get_arr()[i][j];
	return res;
}
Matrix operator*(const Matrix& A, const Matrix& B)
{
	if (A.get_cols() != B.get_rows())return Matrix();
	Matrix res(A.get_rows(), B.get_cols());
	for (int j = 0; j < A.get_rows(); j++)
	{
		for (int k = 0; k < B.get_cols(); k++)
		{
			int buff = 0;
			for (int i = 0; i < A.get_cols(); i++)buff += A.get_arr()[j][i] * B.get_arr()[i][k];
			res.get_arr()[j][k] = buff;
		}
	}
	return res;
}
