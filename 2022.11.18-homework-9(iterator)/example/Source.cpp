#include<iostream>
#include<memory>

using namespace std;

void fooF() //�������� ������� �������, ���� 4, �� �� �� ��������� ������.
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

void foo() //������ ������� �������, ���� 4, �� �� �� ��������� ������.
{
	unique_ptr<int> ptr(new int());
	*ptr = (rand() % 10) + 1;
	if (*ptr == 1)
	{
		cout << "HAH";
		return;
	}
	cout << "BD";
} //����� ��������� ptr �������� ���� ������� ��������� � ������������, �� ����� ���� ������� �� ������ ������, �� ������� ���������.

int main()
{
	foo();
	return 0;
}