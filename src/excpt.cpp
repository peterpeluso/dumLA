#include <iostream>
#include <exception> 

class dim_error : public std::exception
{
	virtual const char* what() const noexcept 
	{
		return "Dimension error";

	}

};
extern dim_error dim_ex; 

//dim_error dim_ex;