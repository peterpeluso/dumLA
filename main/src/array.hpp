#ifndef ARRAY_H
#define ARRAY_H
#include "matrix.hpp"
class Array: public Matrix 
{
public: 
	Array(int n); 
	Complex operator()(int n) const ;
 	Complex& operator()(int n) ;
};

#endif