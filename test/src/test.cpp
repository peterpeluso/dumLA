#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "matrix.hpp"
#include "complex.hpp"
#include <iostream>
// TEST_CASE( "Testing size", "[Matrix]" ){
// 	Matrix A(10, 20); 
// 	REQUIRE(A.maxCol() == 20);
// 	REQUIRE(A.maxRow() == 10);
// }

TEST_CASE("Testing static member ctor", "[Complex]")
{
	Complex a(0,1);
	Complex b = Complex::imaginaryOnly(1);
	Complex c(100,0);
	Complex d = Complex::realOnly(100);
	REQUIRE(a == b);
	REQUIRE(c == d);
}
TEST_CASE("Testing comparison", "[Complex]")
{
	Complex a(10,-20);
	Complex b(10, -20);
	Complex c (10,10);
	REQUIRE(a == b);
	REQUIRE((a == c) == false);
	REQUIRE((c!= a) == true);
	REQUIRE((a != b) == false);
}
TEST_CASE("Copy/Assignment", "[Complex]")
{
	Complex a (10, -20);
	Complex b ;
	Complex c (20, -40);

	b = a;
	c = a;

	REQUIRE( b == a); 
	REQUIRE( c == a);

}
TEST_CASE("addition", "[Complex]")
{
	Complex a(10, 30);
	Complex b (-30, -60);
	Complex c( -20, -30);

	REQUIRE((a+b) == c);
}

TEST_CASE("subtraction", "[Complex]")
{
	Complex a(10, 30);
	Complex b (-30, -60);
	Complex c( 40, 90);
	Complex d(-40, -90);

	REQUIRE((a-b) == c);
	REQUIRE((b-a) == d);
}
TEST_CASE("multiplication", "[Complex]")
{
	Complex a(2,-4);
	Complex b(3,5);
	Complex c(26, -2);
	REQUIRE(a*b == c);
}

TEST_CASE("scalar multiplication", "[Complex]")
{
	Complex a(2,-4);
	double b = -10; 
	Complex c(-20, 40);

	REQUIRE(a*b == c);
	REQUIRE(b*a == c);

}
TEST_CASE("scalar addition/subtraction", "[Complex]")
{
	Complex a(20, 10);
	double b = 40;
	Complex c(60, 10);
	Complex d(20, -10);
	Complex e(-20, 10);

	REQUIRE(a+b == c);
	REQUIRE(b+a == c);
	REQUIRE(b-a == d);
	REQUIRE(a-b == e);
	Complex f(-40,10);
	Complex g(80, -10);
	REQUIRE(b-f == g);

}
TEST_CASE("division", "[Complex]")
{
	Complex A(10, -3);
	Complex B(-2, 4);

	Complex C(-1.6, -1.7);

	REQUIRE(A/B == C);

}

TEST_CASE("scalar divsion", "[Complex]")
{
	Complex A(1, 2);
	double scal = -2; 
	double scal2 = 1;

	Complex ans(-.5,-1);
	Complex ans2(.2,-.4);

	REQUIRE(A/scal == ans);
	REQUIRE(scal2/A == ans2);

}