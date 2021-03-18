#include <iostream>
#include "Matrix.h"

int main()
{
	Matrix A(2), B(2);
	cout << "Enter first matrix" << endl;
	cin >> A;
	cout << A;
	cout << "Enter second matrix" << endl;
	cin >> B;
	cout << B;
	cout << "Second matrix norma:  " << B.MatrixNorm() << endl;
	cout << "A * B:" << endl;
	A* B;
	cout << "Comparison first and second" << endl;
	A.ComparisonMatrix(A, B);

	return 0;
}