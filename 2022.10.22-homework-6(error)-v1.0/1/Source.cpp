#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	string str;
	cout << "¬ведите адрес файла:";
	cin >> str;
	cout << endl;
	ifstream file;
	file.open(str); // 1.существует ли файл?
	int n;
	file >> n;// 2. натуральное ли n? 
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
		file >> a >> oper >> b;  //нужный ли формат файла?
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
		case '/': //3. деление на 0
			arr[i] = a / b;
			break;
		}
	}
	file.close();
	cout << "ћесто сохранени€ результата:";
	cin >> str2; //4. место записи совпадает с местом первого файла
	out_file.open(str2);
	cout << "Cколько строчек результата нужно?:";
	int n1;
	cin >> n1; //5. выход за пределы массива;
	for (int i = 0; i < n1; ++i)
	{
		out_file << arr[i] << endl;
	}
	out_file.close();
	return 0;
}