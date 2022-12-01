#include <iostream>
#include <fstream>
#include <string>
//#include <cmath>

using namespace std;

int main()
{
	try{
	setlocale(LC_ALL, "rus");
	string str;
	cout << "������� ����� �����:";
	cin >> str;
	//cout << endl;
	ifstream file;
	file.open(str);// 1.���������� �� ����?
	if (!file.is_open()) throw ("File not found");
	int n;
	string k;
	file >> k;// 2. ����������� �� n?
	if (k[0] >= 48 && k[0] <= 57) n = k[0] - '0';
	else throw ("Wrong file format");
	ofstream out_file;
	string str2;

	double a = 0;
	double b = 0;
	char oper;
	double* arr = new double[n];
	string s;
	for (int i = 0; i < n; ++i)
	{
		if (file.eof()) throw ("Fewer transactions than stated"); //������ �� ������ �����?
		file >> s;
		int j = 0;
		string chr;
		while (s[j] >= 48 && s[j] <= 57)
		{
			chr += s[j];
			++j;
		}
		if (chr != "") a = stoi(chr);
		else throw ("Wrong file format");
		oper = s[j];
		if (oper != '+' && oper != '-' && oper != '*' && oper != '/')
		{
			throw ("Wrong file format");
		}
		++j;
		chr = "";
		while (s[j] >= 48 && s[j] <= 57)
		{
			chr += s[j];
			++j;
		}
		if (chr != "") b = stoi(chr);
		else throw ("Wrong file format");

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
		case '/'://3. ������� �� 0
			if (b == 0) throw ("division by zero");
			arr[i] = a / b;
			break;
		default:
			throw "Wrong operation";
			break;
		}
	}
	file.close();
	cout << "����� ���������� ����������:";
	cin >> str2; //4. ����� ������ ��������� � ������ ������� �����
	if (str == str2) throw ("Record address is the same as file address");
	out_file.open(str2);
	cout << "C������ ������� ���������� �����?:";
	int n1;
	cin >> n1; //5. ����� �� ������� �������;
	if (n1 > n) throw ("there are not so many lines of result");
	for (int i = 0; i < n1; ++i)
	{
		out_file << arr[i] << endl;
	}
	out_file.close();
}
	catch(const char* error)
	{
		cout << error;
	}
	return 0;
}