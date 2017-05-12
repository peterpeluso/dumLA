#include "matrix.hpp"
#include "catch.hpp"
#include <iostream>
int main()
{

	Matrix x(2,2);
	x.accept();

	 
	std::cout << x << std::endl;
	std::cout<< x * 2 << std::endl;
	std::cout<< 3 * x  << std::endl;

}