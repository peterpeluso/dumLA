
#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>

class Complex
{
public:
	double real; 
	double imaginary; 

	Complex(float re, float im); // if class will be derived from complex make sure this is in private;
	Complex(double re);
	Complex() = default;
	virtual ~Complex() = default;
	Complex(const Complex&) = default;
	Complex& operator=(const Complex&) = default; 
	static Complex realOnly(float re);
	static Complex imaginaryOnly(float img);
};

std::ostream& operator<<(std::ostream& os, const Complex& num);
bool operator==(const Complex& A, const Complex& B);
bool operator!=(const Complex &A, const Complex& B);
Complex operator+( const Complex& A, const Complex& B);
Complex operator-( const Complex& A, const Complex& B);
Complex operator*( const Complex& A, const Complex& B);
Complex operator*(const Complex& A, const double& b );
Complex operator*(const double& b ,const Complex& B );
Complex operator+(const Complex& A, const double& b );
Complex operator+(const double& b ,const Complex& B );
Complex operator-(const Complex& A, const double& b );
Complex operator-(const double& b ,const Complex& B );
Complex operator/ (const Complex& A, const Complex& B);
Complex operator/ (const Complex& A, const double& b);
Complex operator/ (const double& b, const Complex& A);
#endif