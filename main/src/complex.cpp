#include "complex.hpp"

Complex::Complex(float re, float im)
{
	real = re; 
	imaginary = im;
}
Complex Complex::realOnly(float re)
{
	 Complex a = Complex(re,0);
	 return a;
}
Complex Complex::imaginaryOnly(float img)
{
	Complex a = Complex(0,img);
	return a;
}
Complex::Complex(double re)
{
	real = re;
	imaginary =0;
}
std::ostream& operator<<(std::ostream& os, const Complex &num)
{
	if( num.real != 0)
	{


	    if( num.imaginary < 0)
	    {
		    os << num.real << num.imaginary << "i";
	    }
	    else if(num.imaginary == 0)
	    {
	    	os << num.real; 
	    }
	    else
	    {
		os << num.real << "+" << num.imaginary << "i"; 
	    }
	}
	else
	{

	    if( num.imaginary < 0)
	    {
		    os << num.imaginary << "i";
	    }
	    else if(num.imaginary == 0)
	    {
	    	os << 0; 
	    }
	    else
	    {
		os << num.imaginary << "i"; 
	    }

	}


}

bool operator==(const Complex& A, const Complex& B)
{
	if (A.real == B.real && A.imaginary == B.imaginary)
	{
		return true; 
	}
	else
	{
		return false;
	}
}

Complex operator+( const Complex& A, const Complex& B)
{
	double re = A.real + B.real;
	double im = A.imaginary + B.imaginary;
	
	Complex tmp(re, im); 

	return tmp;

}

bool operator!=(const Complex &A, const Complex& B)
{
	if (!(A == B))
	{
		return true;
	}
	else
	{
		return false;
	}
}

Complex operator-( const Complex& A, const Complex& B)
{
	double re = A.real - B.real;
	double im = A.imaginary - B.imaginary;
	
	Complex tmp(re, im); 

	return tmp;

}
Complex operator*(const Complex& A, const Complex& B)
{
	double re = (A.real* B.real) - (A.imaginary * B.imaginary);
	double img = (A.imaginary * B.real) + (A.real * B.imaginary);
	Complex tmp(re, img);

	return tmp;
}

Complex operator*(const Complex& A, const double& b )
{
	Complex scalar = Complex::realOnly(b);
	Complex tmp = A * scalar;
	return tmp;
}
Complex operator*(const double& b ,const Complex& A)
{
	Complex scalar = Complex::realOnly(b);
	Complex tmp = scalar * A;
	return tmp;

}
Complex operator+(const Complex& A, const double& b )
{
	Complex scalar = Complex::realOnly(b);
	Complex tmp = A + scalar;
	return tmp;
}
Complex operator+(const double& b ,const Complex& A )
{
	Complex scalar = Complex::realOnly(b);
	Complex tmp = scalar + A;
	return tmp;
}
Complex operator-(const Complex& A, const double& b )
{
	Complex scalar = Complex::realOnly(b);
	Complex tmp = A - scalar;
	return tmp;	
}
Complex operator-(const double& b ,const Complex& A )
{
	Complex scalar = Complex::realOnly(b);
	Complex tmp = 
	scalar - A;
	return tmp;
}
Complex operator/ (const Complex& A, const Complex& B)
{
	double real; 
	double img; 

	real = ((A.real * B.real) + (A.imaginary *B.imaginary))/((B.real * B.real) + (B.imaginary * B.imaginary));
	img = ((A.imaginary * B.real) - (A.real * B.imaginary))/ ((B.real * B.real) + (B.imaginary * B.imaginary));

	Complex tmp(real, img); 
	return tmp; 
}

Complex operator/ (const Complex& A, const double& b)
{
	Complex scal(b,0);

	return A/scal;

}

Complex operator/ (const double& b, const Complex& A)
{
	Complex scal(b,0);

	return scal/A;

}
