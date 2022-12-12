#include <iostream>
#include "Fraction.h"
#include <vector>
#include <ctime> 
#include <thread>

using namespace std;
static Fraction B(1, 1);
void x4vec(vector<Fraction> v)
{
	for (long int i = 0; i < 1750000; ++i)
	{
		B = B + v[i];
	}
	cout << "done" << endl;
}
int main()
{
	srand(time(0));
	vector<Fraction> v1(1750000);
	for (long int i = 0; i < 1750000; ++i)
	{
		Fraction r(1 + rand() % 20, 1 + rand() % 20);
		v1[i] = r;
	}
	vector<Fraction> v2(1750000);
	for (long int i = 0; i < 1750000; ++i)
	{
		Fraction r(1 + rand() % 20, 1 + rand() % 20);
		v2[i] = r;
	}
	vector<Fraction> v3(1750000);
	for (long int i = 0; i < 1750000; ++i)
	{
		Fraction r(1 + rand() % 20, 1 + rand() % 20);
		v3[i] = r;
	}
	vector<Fraction> v4(1750000);
	for (long int i = 0; i < 1750000; ++i)
	{
		Fraction r(1 + rand() % 20, 1 + rand() % 20);
		v4[i] = r;
	}
	thread S1(x4vec, v1);
	thread S2(x4vec, v2);
	thread S3(x4vec, v3);
	thread S4(x4vec, v4);
	S1.join();
	S2.join();
	S3.join();
	S4.join();
	cout << "runtime = " << clock() << endl;
	return 0;
}
