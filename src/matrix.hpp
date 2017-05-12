#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

class Matrix 
{
	int n_col, n_row;
	double **p; 
public:
	Matrix( int m, int n);
	Matrix (const Matrix& A); 
	~Matrix();
	void accept();
	void pprint();
	double getValue(int m, int n) const; 
	int maxRow() const;
	int maxCol() const;
    void setValue(int m, int n, double val);

	friend std::ostream& operator<<(std::ostream& os, const Matrix& A);


	 Matrix& operator =( const Matrix &A);


};


Matrix operator+( const Matrix& A, const Matrix& B); 
Matrix operator *( const Matrix& A, const Matrix& B);
Matrix operator *( const Matrix& A, const double & scal);
Matrix operator *(const double & scal, const Matrix& A);
//#include "matrix.cpp"
#endif