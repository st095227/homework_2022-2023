#include<iostream>
#include"quaternion.h"

using namespace std;

int main()
{
	quaternion a(1, 2, 3, 4);
	quaternion b(2, 3, 4, 5);
	cout << a << endl;
	quaternion c(12, 21, 21, 12);
	b -= a;
	cout << b << endl;
	cout << a * b << endl;
	cin >> a;
	cout << a;
	return 0;
}