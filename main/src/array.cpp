#include "array.hpp"
Array::Array(int n) : Matrix(1,n)
{
}

Complex Array::operator()(int n)  const 
{
	return arr[n];
}
Complex& Array::operator()(int n)
{
	return arr[n];
}
