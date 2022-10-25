#include <iostream>
using namespace std;

struct foo
{
	int* data;
	int size;

	foo(int n)
	{
		size = n;
		data = new int[2 * n];
	}
	foo(const foo& A)
	{
		cout << "constructor worked" << endl;
		size = A.size;
		data = new int[size * 2];
		for (int i = 0; i / 2 < size; ++i)
		{
			data[i] = A.data[i];
		}
	}
	~foo()
	{
		delete[] this->data;
	}
	const foo& operator=(const foo& A)
	{
		foo tmp(A);
		swap(tmp, *this);
		return *this;
	}
};
foo F(foo A, int k)
{
	if (k > 0) return F(A, k / 4);
	// ...
	return A;
}
void swap(foo& A, foo& B)
{
	foo tmp(A);
	A.size = B.size;
	delete[] A.data;
	A.data = new int[B.size * 2];
	for (int i = 0; i < B.size * 2; ++i)
	{
		A.data[i] = B.data[i];
	}

	B.size = tmp.size;
	delete[] B.data;
	B.data = new int[tmp.size * 2];
	for (int i = 0; i < tmp.size * 2; ++i)
	{
		B.data[i] = tmp.data[i];
	}
}

int main()
{
	foo A(0);
	foo D(0);
	D = A;
	F(A, 11);// constructor worked 4 times
	return 0;
}