#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include "complex.hpp"


 class Matrix 
 {
 	int n_col, n_row;
 protected:
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
 	virtual Complex operator()(int m, int n) const ;
 	virtual Complex& operator()(int m, int n) ; 
 	void fill();

 	friend std::ostream& operator<<(std::ostream& os,  const Matrix& A);
 	Matrix operator+( const Matrix& A); 
     Matrix& operator =( const Matrix &A);
     Matrix &operator= (Matrix && other);
     Matrix operator *(const double & scal) const ; // added const so that can overload other way
     bool operator== (const Matrix& A) ; 
     Matrix row(int m);


 };

Matrix operator *( const Matrix& A, const Matrix& B);
Matrix operator *(const double & scal, const Matrix& A);



#endif