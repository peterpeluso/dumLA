#include <iostream>
class dim_error : public std::exception
{
public: 
	virtual const char* what() throw()
	{
		return "Dimension error";

	}

};  