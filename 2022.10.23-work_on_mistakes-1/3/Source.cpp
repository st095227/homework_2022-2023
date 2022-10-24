#include <iostream>

using namespace std;

struct A1 
{
	int c;
	A1()
	{
		this->c = 56;
	}
	~A1() 
	{ 
		cout << "dest A1" << endl;
	} 
};
struct A2 : A1 
{
	~A2() 
	{
		cout << "result:" << this->c << endl; //если первый деструктор выполнится раньше второго, то мы потеряем результат
		c = 0;
		cout << "dest A2" << endl;
	} 
};

int main() 
{
	A2* b = new A2;
	delete b;
	return 0;
}