#include <iostream>
#include "Matrix/Matrix.h"
#include "quaternion/Quaternion.h"

int main()
{
	Matrix _matrix = Matrix::IdentityM;
	Matrix Sacale = _matrix.CreateScale(5, 10, 15);
	Matrix Translation = _matrix.CreateTranslation(10, 25, 45);

	std::cout << _matrix.CreateOrthographie(100, 80, 250,150).ToString() << "\n" << std::endl;

}
