#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "matrix.hpp"
#include <iostream>
TEST_CASE( "Testing size", "Prove that one equals 2" ){
	Matrix A(10, 20); 
	REQUIRE(A.maxCol() == 20);
	REQUIRE(A.maxRow() == 11);
}
