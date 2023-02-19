#include<iostream>
#include"quaternion.h"

using namespace std;
//const quaternion a(1, 2, 3, 4);
int main()
{
	const quaternion a(1, 2, 3, 4);
	
	quaternion b;
	cout << a.abs();
	return 0;
}