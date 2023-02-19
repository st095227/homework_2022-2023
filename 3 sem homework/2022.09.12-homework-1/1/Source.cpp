#include <iostream>

using namespace std;

struct A
{
	char a;
	double g;
	short b[15];
	int d;
	int e[17];
	short c;
	float f;
	double h[5];
};

int main()
{
	A N;
	cout << "size of class:" << sizeof(N) << endl;
	int r = sizeof(N.a) + sizeof(N.b) + sizeof(N.c) + sizeof(N.d) + sizeof(N.e) + sizeof(N.f) + sizeof(N.g) + sizeof(N.h);
	cout << "sum of sizes:" << r << endl << endl;
	cout << "a:" << (int*)&N.a << endl;
	cout << "b:" << (int*)&N.b << endl;
	cout << "c:" << (int*)&N.c << endl;
	cout << "d:" << (int*)&N.d << endl;
	cout << "e:" << (int*)&N.e << endl;
	cout << "f:" << (int*)&N.f << endl;
	cout << "g:" << (int*)&N.g << endl;
	cout << "h:" << (int*)&N.h << endl;

	return 0;
}