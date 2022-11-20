#include<iostream>
#include<memory>

using namespace std;

void fooF() //неверный вариант функции, если 4, то мы не освободим память.
{
	int* b = new int;
	*b = (rand() % 10) + 1;
	if (*b == 4)
	{
		cout << "HAH";
		return;
	}
	cout << "BD";
	delete b;
}

void foo() //верный вариант функции, если 4, то мы не освободим память.
{
	unique_ptr<int> ptr(new int());
	*ptr = (rand() % 10) + 1;
	if (*ptr == 1)
	{
		cout << "HAH";
		return;
	}
	cout << "BD";
} //Здесь указатель ptr покидает свою область видимости и уничтожается, но перед этим удаляет из памяти объект, на который указывает.

int main()
{
	foo();
	return 0;
}