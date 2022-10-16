#include<iostream>

using namespace std;

template<typename T>
void Bubble(T* a, int n, int(*comparator)(T p3, T p4));

template<typename T>
void universal_sort(T* a, int n, int(*cmp)(T p1, T p2), void (*sort)(T* a, int n, int(*comparator)(T p3, T p4)) = nullptr)
{
	if (sort != nullptr)
	{
		sort(a, n, cmp);
	}
	else
	{
		Bubble(a, n, cmp);
	}
}

int comparator(int p1, int p2)
{
	return p1 - p2;
}
int compSTR(string p1, string p2)
{
	return p1.length() - p2.length();
}

template<typename T>
void print(T* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
template<typename T>
void Bubble(T* a, int n, int(*comparator)(T p3, T p4))
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (comparator(a[i], a[j]) > 0)
			{
				T temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
template<typename T>
void monkeysort(T* a, int n, int(*comparator)(T p3, T p4))
{
	bool isSorted = false;
	while (!isSorted)
	{
		for (int i = 0; i < n; i++)
		{
			int randInd1 = rand() % n;
			int randInd2 = rand() % n;
			T temp = a[randInd2];
			a[randInd2] = a[randInd1];
			a[randInd1] = temp;

		}
		for (int i = 0; i < n - 1; i++)
		{
			if (comparator(a[i], a[i + 1]) < 0)
			{
				isSorted = false;
				break;
			}
			isSorted = true;
		}
	}


}

template<typename T>
void qsort(T* mas, int size, int(*comparator)(T p3, T p4)) {
	int i = 0;
	int j = size - 1;

	T mid = mas[size / 2];

	do {
		while (comparator(mas[i], mid) < 0) {
			i++;
		}
		while (comparator(mas[j], mid) > 0) {
			j--;
		}
		if (i <= j) {
			T tmp = mas[i];
			mas[i] = mas[j];
			mas[j] = tmp;

			i++;
			j--;
		}
	} while (i <= j);

	if (j > 0) {
		qsort(mas, j + 1, comparator);
	}
	if (i < size) {
		qsort(&mas[i], size - i, comparator);
	}
}

int main()
{
	int a[4];
	for (int i = 0; i<4; ++i)
	{
		a[i] = i * (4-i);
	}
	
	print<int>(a, (sizeof(a) / sizeof(a[0])));
	universal_sort<int>(a, (sizeof(a) / sizeof(a[0])), comparator, Bubble);
	print<int>(a, (sizeof(a) / sizeof(a[0])));

	int c[12];
	for (int i = 0; i < 12; ++i)
	{
		c[i] = i * (12 - i);
	}

	print<int>(c, (sizeof(c) / sizeof(c[0])));
	universal_sort<int>(c, (sizeof(c) / sizeof(c[0])), comparator, qsort);
	print<int>(c, (sizeof(c) / sizeof(c[0])));

	string b[4]{ "wow","super", "programm", "Ha"};
	print<string>(b, 4);
	universal_sort(b, 4, compSTR, qsort);
	print<string>(b, 4);

	return 0;
}