#ifndef matrix_cpp
#define matrix_cpp
#include "matrix.hpp"
//#include "excpt.cpp"


Matrix::Matrix(int m, int n)
{
	n_col = n;
	n_row = m; 
	p = new double * [n_row];

	for(int i = 0; i < n_row; i++)
	{
		p[i] = new double [n_col]; 

	}
}
Matrix::Matrix (const Matrix& A)
{
	n_col = A.maxCol();
	n_row = A.maxRow(); 
	p = new double * [n_row];

	for(int i = 0; i < n_row; i++)
	{
		p[i] = new double [n_col]; 

		for(int j = 0; j < n_col; j++)
		{
			p[i][j] = A.getValue(i,j);
		}

	}

}
Matrix::~Matrix()
{
	for(int i = 0; i < n_row; i++)
	{
		delete p[i]; 
	}

	delete p; 
}


void Matrix::accept()
{
	for(int i = 0; i < n_row; i++)
	{
		std:: cout << "row " << i + 1 << " :" << std::endl;
		for(int j = 0; j <  n_col; j++)
		{	
			std::cin >> p[i][j];
		}
	}
	
}


void Matrix::pprint()
{

	for(int i = 0; i < n_row; i++)
	{
		for(int j = 0; j < n_col; j++)
		{
			std::cout << p[i][j] << " ";
		}
		std::cout << std::endl;
	}
}


 
double Matrix::getValue(int m, int n) const
{
	return p[m][n]; 
}


void Matrix::setValue(int m, int n, double val)
{
	p[m][n] = val; 
}

int Matrix::maxRow() const
{
	return n_row;
}


int Matrix::maxCol() const
{
	return n_col;
}


std::ostream& operator<<(std::ostream& os,  const Matrix& A)
{

	for(int i = 0; i < A.maxRow(); i++)
	{
		for(int j = 0; j < A.maxCol(); j++)
		{
			 os << A.getValue(i,j) << " ";
		}
		os << std::endl;
	}

	return os;
}


Matrix operator+( const Matrix& A, const Matrix& B)
{

	    if( A.maxRow() != B.maxRow() || A.maxCol() != B.maxCol() )
        {
			throw dim_err;
	    }

	Matrix tmp(A.maxRow(), A.maxCol()); 

	double val; 

	for(int i = 0; i < tmp.maxRow(); i++)
	{
		for(int j = 0; j < tmp.maxCol(); j++)
		{
			 val = A.getValue(i,j) + B.getValue(i,j);

			 tmp.setValue(i, j, val); 
		}
		
	}

	return tmp; 
}

Matrix operator*( const Matrix& A, const Matrix & B)
{
	
	    if( A.maxCol() != B.maxRow() )
        {
			throw dim_err;
	    }
    

	Matrix tmp(A.maxRow(), B.maxCol()); 
	double val; 

	for(int i = 0; i < A.maxRow(); i++)
	{
		for(int j = 0; j < B.maxCol(); j++)
		{
			for(int k = 0; k < A.maxCol(); k++)
			 val += A.getValue(i,k) * B.getValue(k,j);

			 tmp.setValue(i, j, val); 
			 val = 0;
		}
		
	}

	return tmp; 
}

Matrix& Matrix::operator=(const Matrix & A)
{
if( this != &A)	
{
	for(int i = 0; i < n_row; i++)
	{
		delete p[i]; 
	}
	delete p; 

	n_col = A.maxCol();
	n_row = A.maxRow();

	p = new double * [n_row];

	for(int i = 0; i < n_row; i++)
	{
		p[i] = new double [n_col]; 

		for(int j = 0; j < n_col; j++)
		{
			p[i][j] = A.getValue(i,j);
		}

	}
}

	return *this;
}

Matrix operator *( const Matrix& A, const double & scal)
{
	

   
	Matrix tmp(A.maxRow(), A.maxCol()); 
	double val; 

	for(int i = 0; i < tmp.maxRow(); i++)
	{
		for(int j = 0; j < tmp.maxCol(); j++)
		{

			 val += A.getValue(i,j) * scal; 

			 tmp.setValue(i, j, val); 
			 val = 0;
		}
		
	}

	return tmp; 
}

Matrix operator *(const double & scal, const Matrix& A)
{
	return A * scal; 
}
#endif