#ifndef matrix_cpp
#define matrix_cpp
#include "matrix.hpp"
#include "excpt.cpp"


Matrix::Matrix(int m, int n)
{
	n_col = n;
	n_row = m; 
	arr = new Complex [n_row * n_col];

	arr[0] = Complex(1,1);
	arr[1] = Complex(2,2);
	arr[2] = Complex(-1,-1);
	arr[3] = Complex(-2,-2);

}
Matrix::Matrix (const Matrix& A)
{
	n_col = A.numCol();
	n_row = A.numRow(); 
	arr = new Complex [n_row * n_col];

	for(int i = 0; i < n_row * n_col; i++)
	{
		arr[i] = A.getArrVal(i);

	}

}

Matrix::Matrix(Matrix&& other)
{
	arr = other.arr;
    n_row = other.numRow();
    n_col  = other.numCol();
	other.arr = nullptr;


}
Matrix::~Matrix()
{
   delete [] arr; 
}


// void Matrix::accept()
// {
// 	for(int i = 0; i < n_row; i++)
// 	{
// 		std:: cout << "row " << i + 1 << " :" << std::endl;
// 		for(int j = 0; j <  n_col; j++)
// 		{	
// 			std::cin >> p[i][j];
// 		}
// 	}
	
// }






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
	m = m-1;
	n = n-1;
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


Matrix operator+( const Matrix& A, const Matrix& B)
{

	    if( A.numRow() != B.numRow() || A.numCol() != B.numCol() )
        {
			 //throw dim_err;
	    }

	Matrix tmp(A.numRow(), A.numCol()); 

	Complex val; 

	for(int i = 0; i < (tmp.numCol() * tmp.numCol()); i++)
	{
		val = A.getArrVal(i) + B.getArrVal(i);
		tmp.arr[i] = val;
	}

	return tmp; 
}

// Matrix operator*( const Matrix& A, const Matrix & B)
// {
	
// 	    if( A.maxCol() != B.maxRow() )
//         {
// 			//throw dim_error;
// 	    }
    

// 	Matrix tmp(A.maxRow(), B.maxCol()); 
// 	double val; 

// 	for(int i = 0; i < A.maxRow(); i++)
// 	{
// 		for(int j = 0; j < B.maxCol(); j++)
// 		{
// 			for(int k = 0; k < A.maxCol(); k++)
// 			 val += A.getValue(i,k) * B.getValue(k,j);

// 			 tmp.setValue(i, j, val); 
// 			 val = 0;
// 		}
		
// 	}

// 	return tmp; 
// }

Matrix& Matrix::operator=(const Matrix & A)
{
if( this != &A)	
{

	delete [] arr; 

	n_col = A.numCol();
	n_row = A.numRow();

	arr = new Complex  [n_row * n_col];

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
	arr = other.arr;
	n_row = other.numRow();
	n_col = other.numCol();

	 other.arr = nullptr;



}

	return *this;
}

// Matrix operator *( const Matrix& A, const double & scal)
// {
	

   
// 	Matrix tmp(A.maxRow(), A.maxCol()); 
// 	double val; 

// 	for(int i = 0; i < tmp.maxRow(); i++)
// 	{
// 		for(int j = 0; j < tmp.maxCol(); j++)
// 		{

// 			 val += A.getValue(i,j) * scal; 

// 			 tmp.setValue(i, j, val); 
// 			 val = 0;
// 		}
		
// 	}

// 	return tmp; 
// }

// Matrix operator *(const double & scal, const Matrix& A)
// {
// 	return A * scal; 
// }



#endif