#include<iostream>

using namespace std;

template<typename T>
void qsort(T *mas, int posi0, int posj0)
{
	int d = mas[posj0];
	int posi = posi0;
	int posj = posj0;
	do
	{
		while (mas[posi] < d)
		{
			++posi;
		}
		while (mas[posj] > d)
		{
			--posj;
		}
		if (posj >= posi)
		{
			std::swap(posi, posj);
			--posj;
			++posi;
		}
	} while (posi <= posj);
	if (posj > posi0)
	{
		qsort(mas,posi0, posj);
	}
	if (posi < posj0)
	{
		qsort(mas, posi, posj0);
	}
}

template<typename T>
void Qsort(T *mas,int size)
{
	qsort(mas, 0, size - 1);
}
template<typename T>
//void usort(void (*tsort)(T* arr, int size))
//{
	//tsort(arr, size);
//}

int main()
{
	int *a = new int[31];
	for (int i = 0; i < 31; ++i)
	{
		a[i] = 31 - i;
	}
	for (int i = 0; i < 31; ++i)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	Qsort(a,31);
	for (int i = 0; i < 31; ++i)
	{
		cout << a[i] << ' ';
	}
	return 0; 
}