#include<fstream>
#include<iostream>
#include <algorithm>

using namespace std;

int main()
{
	ifstream file("in3.txt");
	int* arr = new int[1000];

	for (int i = 0; i < 1000;++i)
	{
		file >> arr[i];
	}
	sort(arr, arr + 1000);
	ofstream out("res3.txt");
	for (int i = 0; i < 1000;++i)
	{
		out << arr[i] << ' ';
	}
	delete[] arr;
	file.close();
	out.close();
	return 0;
}