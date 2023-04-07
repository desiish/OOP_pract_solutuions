#pragma once
#include <fstream>
class Matrix
{
	int** _matrix;
	size_t _m; // rows
	size_t _n; // cols

	void copyFrom(const Matrix& other);
	void free();
	Matrix getNegativeMatr() const;
	friend int getMultiplicationResCellValue(const Matrix& lhs, const Matrix& rhs, int rowInd, int colInd);
public: 
	Matrix();
	Matrix(size_t m, size_t n);
	Matrix(const Matrix& other);
	~Matrix();
	Matrix& operator=(const Matrix& other);
	Matrix& operator+=(const Matrix& other);
	Matrix& operator-=(const Matrix& other);
	Matrix& operator*=(int num);
	Matrix& operator*=(const Matrix& other);
	int*& operator[](int indexOfRow);
	int* operator[](int indexOfRow) const;
	friend bool operator==(const Matrix& lhs, const Matrix& rhs);
	friend std::istream& operator>>(std::istream& is, Matrix& matrix); //addition
	friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix); //addition
};
Matrix operator+(const Matrix& lhs, const Matrix& rhs);
Matrix operator-(const Matrix& lhs, const Matrix& rhs);
Matrix operator*(const Matrix& lhs, const Matrix& rhs);
Matrix operator*(const Matrix& lhs, int num);
bool operator!=(const Matrix & lhs, const Matrix & rhs);

