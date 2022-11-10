#include <iostream>
#include "Matrix/Matrix.h"

int main()
{
	Matrix _matrix = Matrix::IdentityM;

	 _matrix.CreateTranslation(5.0f,9.0f,10);
	std::cout << _matrix.CreateScale(10,20,30).ToString() << std::endl;

}
