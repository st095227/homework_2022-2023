#include "Sort.h"

template<typename T>
void Sort<T>::qsort(int posi0, int posj0)
{
	int d = this->mas[posj0];
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
		qsort(posi0, posj);
	}
	if (posi < posj0)
	{
		qsort(posi, posj0);
	}
}

template<typename T>
void Sort<T>::Qsort(int size)
{
	qsort(0, size-1);
}
