#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	string str;
	cout << "������� ����� �����:";
	cin >> str;
	cout << endl;
	ifstream file;
	file.open(str); // 1.���������� �� ����?
	int n;
	file >> n;// 2. ����������� �� n? 
	cout << n << endl;
	ofstream out_file;
	string str2;

	double a = 0;
	double b = 0;
	char oper;
	double *arr = new double[n];
	string s;

	for (int i = 0; i < n; ++i)
	{
		file >> a >> oper >> b;  //������ �� ������ �����?
		cout << a << oper << b << endl;
		switch (oper)
		{
		case  '+':
			arr[i] = a + b;
			break;
		case '-':
			arr[i] = a - b;
			break;
		case '*':
			arr[i] = a * b;
			break;
		case '/': //3. ������� �� 0
			arr[i] = a / b;
			break;
		}
	}
	file.close();
	cout << "����� ���������� ����������:";
	cin >> str2; //4. ����� ������ ��������� � ������ ������� �����
	out_file.open(str2);
	cout << "C������ ������� ���������� �����?:";
	int n1;
	cin >> n1; //5. ����� �� ������� �������;
	for (int i = 0; i < n1; ++i)
	{
		out_file << arr[i] << endl;
	}
	out_file.close();
	return 0;
}