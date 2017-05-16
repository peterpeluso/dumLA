#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include "complex.hpp"

 class Matrix 
 {
 	int n_col, n_row;
 	Complex *arr; 
 	Complex& setArrVal(int i);
 public:
 	Matrix( int m, int n);
 	Matrix (const Matrix& A);
 	Matrix (Matrix&& other); 
 	~Matrix();
 	Complex getArrVal(int i) const;
// 	void accept();
 	int numRow() const;
 	int numCol() const;
 	Complex operator()(int m, int n) const ;
 	Complex& operator()(int m, int n) ; 
 	void fill();

 	friend std::ostream& operator<<(std::ostream& os,  const Matrix& A);
 	friend Matrix operator+( const Matrix& A, const Matrix& B); 
     Matrix& operator =( const Matrix &A);
     Matrix &operator = (Matrix && other);



 };


//Matrix operator+( const Matrix& A, const Matrix& B); 
// Matrix operator *( const Matrix& A, const Matrix& B);
// Matrix operator *( const Matrix& A, const double & scal);
// Matrix operator *(const double & scal, const Matrix& A);



#endif