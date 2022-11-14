#include <iostream>
#include "Matrix/Matrix.h"

int main()
{
	Matrix _matrix = Matrix::IdentityM;

	std::cout << _matrix.CreateTranslation(10,25,45).ToString() << std::endl;
}
