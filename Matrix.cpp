#include "Matrix.h"

Matrix::Matrix()
{
	a = 1;
	s = new Array[a];
	s[0] = Array(a);
}

Matrix::Matrix(int a = 1)
{
	this->a = a < 1 ? 1 : a;
	s = new Array[this->a];
	for (int j = 0; j < this->a; j++)
		s[j] = Array(this->a);
}

Matrix::Matrix(int a, Array* c)
{
	this->a = a;
	s = c;
}

Matrix::~Matrix()
{
	for (int i = 0; i < a; i++)
		if (s[i].m != nullptr)
			delete[](s[i].m);

	if (s != nullptr)
		delete[] s;
}

void operator * (Matrix& a, Matrix& b)
{
	Matrix result(a.GetA());

	for (int i = 0; i < a.GetA(); i++)
		for (int j = 0; j < b.GetA(); j++) {
			result[i][j] = 0;
			for(int t=0;t<a.GetA();t++)
			result[i][j] += a[i][t] * b[t][j];
		}
	cout << result;
}
bool operator == (Matrix& a, Matrix& b)
{
	int Counter = 0;

	for (int i = 0; i < a.GetA(); i++)
		for (int j = 0; j < a.GetA(); j++)
			if (a[i][j] == b[i][j])
				Counter++;
	return Counter == a.GetA() * a.GetA() ? true : false;
}

ostream& operator << (ostream& out, const Matrix& a)
{
	out << string(a);
	return out;
}
istream& operator >> (istream& in, Matrix& A)
{
	for (int i = 0; i < A.GetA(); i++)
	{
		cout << "Enter two number: " << endl;
		for (int j = 0; j < A.GetA(); j++)
		{
			in >> A.s[i].m[j];
		}
		cout << endl;
	}
	return in;
}

Matrix::operator string() const
{
	stringstream ss;
	for (int i = 0; i < this->GetA(); i++)
	{
		for (int j = 0; j < this->GetA(); j++)
		{
			ss << s[i].m[j] << "  ";
		}
		ss << endl;
	}
	return ss.str();
}

void Matrix::ComparisonMatrix(Matrix& A, Matrix& B)
{
	if (A == B) cout << "First equal Second" << endl;
	else cout << "Are not equal" << endl;
}

double Matrix::MatrixNorm()
{
	int max = s[0][0];
	int min = s[0][0];

	for (int i = 0; i < this->GetA(); i++) {
		for (int j = 0; j < this->GetA(); j++) {
			if (s[i][j] > max)
				max = s[i][j];
			if (s[i][j] < min)
				min = s[i][j];
		}
	}
	return abs(max-min);
}