#include<iostream>
#include "Array.h"

using namespace std;

int main()
{
	Array A;
	for (int i = 0; i < 12; ++i)
	{
		A.set(i, i);
	}
	A.set(127, 12);
	for (int i = 0; i < 17; ++i)
	{
		cout << A.get(i) << ' ';
	}
	cout << endl;
	Array b;
	b = A;
	for (int i = 0; i < 17; ++i)
	{
		cout << b.get(i) << ' ';
	}

	return EXIT_SUCCESS;
}