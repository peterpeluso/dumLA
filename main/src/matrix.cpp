#ifndef matrix_cpp
#define matrix_cpp
#include "matrix.hpp"
#include "excpt.cpp"
#include <memory>

Matrix::Matrix():
 n_col(0) 
,n_row(0)
{

}
Matrix::Matrix(int m, int n) :
 n_col(n) 
,n_row(m)
{
	arr = std::unique_ptr<Complex []>(new Complex [n_row * n_col]);
}
Matrix::Matrix (const Matrix& A) :
 n_col(A.numCol())
,n_row(A.numRow()) 
{
	arr = std::unique_ptr<Complex []>(new Complex [n_row * n_col]);

	for(int i = 0; i < n_row * n_col; i++)
	{
		arr[i] = A.getArrVal(i);

	}

}

Matrix::Matrix(Matrix&& other)
: arr(std::move(other.arr))
{
    n_row = other.numRow();
    n_col  = other.numCol();
}
Matrix::~Matrix()
{
   
}



Complex Matrix::getArrVal(int i) const 
{
	return arr[i];
}
Complex& Matrix::setArrVal(int i)
{
	return arr[i];
}
int Matrix::numRow() const
{
	return n_row;
}


int Matrix::numCol() const
{
	return n_col;
}

Complex Matrix::operator()(int m, int n)  const 
{
	return arr[(m * numRow()) + n];
}
Complex& Matrix::operator()(int m, int n)
{

	return arr[(m * numRow()) + n];
}

void Matrix::fill()
{
	for(int i = 0; i < (numRow() * numCol()); i++)
	{
		arr[i] = Complex(0);
	}
}


std::ostream& operator<<(std::ostream& os,  const Matrix& A)
{

	for(int i = 0; i < A.numRow(); i++)
	{
		for(int j = 0; j < A.numCol(); j++)
		{
			 os << A(i,j) << " ";
		}
		os << std::endl;
	}

	return os;
}


Matrix Matrix::operator+( const Matrix& A)
{

	    if( n_row != A.numRow() || n_col != A.numCol() )
        {
			 //throw dim_err;
	    }

	Matrix tmp(A.numRow(), A.numCol()); 

	Complex val; 

	for(int i = 0; i < (tmp.numCol() * tmp.numCol()); i++)
	{
		val = arr[i] + A.getArrVal(i);
		tmp.arr[i] = val;
	}

	return tmp; 
}

Matrix operator*( const Matrix& A, const Matrix & B)
{
	
	    if( A.numCol() != B.numRow() )
        {
			//throw dim_error;
	    }
    

	Matrix tmp(A.numRow(), B.numCol()); 
	Complex val; 

	for(int i = 0; i < A.numRow(); i++)
	{
		for(int j = 0; j < B.numCol(); j++)
		{
			for(int k = 0; k < A.numCol(); k++)
			 val = val + (A(i,k) * B(k,j));

			 tmp(i, j) = val; 
			 val = 0;
		}
		
	}

	return tmp; 
}

Matrix& Matrix::operator=(const Matrix & A)
{
if( this != &A)	
{
	arr.reset();

	n_col = A.numCol();
	n_row = A.numRow();

	arr = std::unique_ptr<Complex []>(new Complex [n_row * n_col]);

	for(int i = 0; i < n_row * n_col; i++)
	{
		 arr[i] = A.getArrVal(i);
	}
}

	return *this;
}

Matrix& Matrix::operator = (Matrix && other)
{
if( this != &other)	
{
	arr = std::move(other.arr);
	n_row = other.numRow();
	n_col = other.numCol();
}

	return *this;
}

Matrix Matrix::operator *(const double & scal) const 
{
	

   
	Matrix tmp(n_row, n_col); 
	Complex val; 

	for(int i = 0; i < (n_row * n_col); i++)
	{

			 val = arr[i] * scal;

			 tmp.setArrVal(i) = val; 
			 val = 0;

	}

	return tmp; 
}

Matrix operator *(const double & scal, const Matrix& A)
{
	return A * scal; 
}

bool Matrix::operator== (const Matrix& A) 
{
	if( n_col != A.n_col || n_row != A.n_row)
	{
		return false;
	}

	for(int i = 0; i < n_col * n_row; i++)
	{
		if(arr[i] != A.arr[i])
		{
			return false;
		}
	}

	return true;
}

Matrix Matrix::row(int m)
{
	Matrix tmp(1, n_col);
	int j =0;
	for(int i = m* n_col; i < (n_col*m) + n_col; i++)
	{
		tmp(0,j) = arr[i];
		j++;
	}

	return tmp;

}


#endif