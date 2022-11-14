#include <iostream>
#include "Matrix/Matrix.h"

int main()
{
	Matrix _matrix = Matrix::IdentityM;

	std::cout << _matrix.GetDeterminant() << std::endl;
}
