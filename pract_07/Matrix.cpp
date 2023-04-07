#include "Matrix.h"
#include <iostream>
void Matrix::copyFrom(const Matrix& other)
{
	_m = other._m;
	_n = other._n;
	_matrix = new int* [_m];
	for (int i = 0; i < _m; i++)
	{
		_matrix[i] = new int[_n];
		for (int j = 0; j < _n; j++)
			_matrix[i][j] = other._matrix[i][j];
	}
}
void Matrix::free()
{
	for (int i = 0; i < _m; i++)
	{
		delete[] _matrix[i];
		_matrix[i] = nullptr;
	}
	delete[] _matrix;
	_matrix = nullptr;
	_n = _m = 0;
}
Matrix Matrix::getNegativeMatr() const
{
	for (int i = 0; i < _m; i++)
	{
		for (int j = 0; j < _n; j++)
			_matrix[i][j] *= -1;
	}
	return *this;
}
Matrix::Matrix() : Matrix(2, 2){}
Matrix::Matrix(size_t m, size_t n)
{
	_m = m;
	_n = n;
	_matrix = new int* [_m];
	for (int i = 0; i < _m; i++)
	{
		_matrix[i] = new int[_n];
		for (int j = 0; j < _n; j++)
			_matrix[i][j] = 0;
	}
}
Matrix::Matrix(const Matrix& other)
{
	copyFrom(other);
}
Matrix::~Matrix()
{
	free();
}
Matrix& Matrix::operator=(const Matrix& other)
{
	if (&other != this)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
Matrix& Matrix::operator+=(const Matrix& other)
{
	if (_m != other._m || _n != other._n)
		throw "Error!";
	for (int i = 0; i < _m; i++)
	{
		for (int j = 0; j < _n; j++)
			_matrix[i][j] += other._matrix[i][j];
	}
	return *this;
}
Matrix& Matrix::operator-=(const Matrix& other)
{
	if (_m != other._m || _n != other._n)
		throw "Error!";
	Matrix NegativeOther = other.getNegativeMatr();
	*this += NegativeOther;
	return *this;
}
int getMultiplicationResCellValue(const Matrix& lhs, const Matrix& rhs, int rowInd, int colInd)
{
	int res = 0;
	for (int i = 0; i < lhs._n; i++)
		res += lhs._matrix[rowInd][i] * rhs._matrix[i][colInd];
	return res;
}
Matrix& Matrix::operator*=(const Matrix& other)
{
	if (_n != other._m)
		throw "Error!";
	Matrix result(_m, other._n);
	for (int i = 0; i < _m; i++)
	{
		for (int j = 0; j < other._n; j++)
			result._matrix[i][j] = getMultiplicationResCellValue(*this, other, i, j);
	}
	*this = result; 
	return *this;
}
Matrix& Matrix::operator*=(int num)
{
	for (int i = 0; i < _m; i++)
	{
		for (int j = 0; j < _n; j++)
			_matrix[i][j] *= num;
	}
	return *this;
}
int*& Matrix::operator[](int indexOfRow)
{
	return _matrix[indexOfRow];
}
int* Matrix::operator[](int indexOfRow) const
{
	return _matrix[indexOfRow];
}
Matrix operator+(const Matrix& lhs, const Matrix& rhs)
{
	Matrix copyOfLhs(lhs);
	copyOfLhs += rhs;
	return copyOfLhs;
}
Matrix operator-(const Matrix& lhs, const Matrix& rhs)
{
	Matrix copyOfLhs(lhs);
	copyOfLhs -= rhs;
	return copyOfLhs;
}
Matrix operator*(const Matrix& lhs, const Matrix& rhs)
{
	Matrix copyOfLhs(lhs);
	copyOfLhs *= rhs;
	return copyOfLhs;
}
Matrix operator*(const Matrix& lhs, int num)
{
	Matrix copyOfLhs(lhs);
	copyOfLhs *= num;
	return copyOfLhs;
}
bool operator==(const Matrix& lhs, const Matrix& rhs)
{
	if (lhs._m != rhs._m || lhs._n != rhs._n)
		throw "Error!";
	for (int i = 0; i < lhs._m; i++)
	{
		for (int j = 0; j < lhs._n; j++)
			if (lhs._matrix[i][j] != rhs._matrix[i][j])
				return false;
	}
	return true;
}
bool operator!=(const Matrix& lhs, const Matrix& rhs)
{
	return !(lhs == rhs);
}
std::istream& operator>>(std::istream& is, Matrix& matrix)
{
	for (int i = 0; i < matrix._m; i++)
	{
		for (int j = 0; j < matrix._n; j++)
			is >> matrix[i][j];
	}
	return is;
}
std::ostream& operator<<(std::ostream& os, const Matrix& matrix)
{
	for (int i = 0; i < matrix._m; i++)
	{
		for (int j = 0; j < matrix._n; j++)
			os << '[' << matrix[i][j] << ']';
		os << std::endl;
	}
	return os;
}