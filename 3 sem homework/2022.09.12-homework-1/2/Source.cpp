#include <iostream>


using namespace std;

class Obj
{
	int x;
	char y;
	double z;
	void printx()
	{
		cout << x << endl;
	};
	void printy()
	{
		cout << y << endl;
	};
	void printz()
	{
		cout << z << endl;
	};
};
class Obj2
{
public:
	int x;
	char y;
	double z;
	void printx()
	{
		cout << x << endl;
	};
	void printy()
	{
		cout << y << endl;
	};
	void printz()
	{
		cout << z << endl;
	};
};
void hx(Obj& obj, int b) {

	reinterpret_cast<Obj2*>(&obj)->x = b;
}
void hy(Obj& obj, char b) {

	reinterpret_cast<Obj2*>(&obj)->y = b;
}
void hz(Obj& obj, double b) {

	reinterpret_cast<Obj2*>(&obj)->z = b;
}
void hpx(Obj& obj) {

	reinterpret_cast<Obj2*>(&obj)->printx();
}
void hpy(Obj& obj) {

	reinterpret_cast<Obj2*>(&obj)->printy();
}
void hpz(Obj& obj) {

	reinterpret_cast<Obj2*>(&obj)->printz();
}

int main()
{
	Obj n;
	Obj2 n2;
	hx(n, 12);
	hy(n, 'a');
	hz(n, 2.32);
	hpx(n);
	hpy(n);
	hpz(n);

	return 0;
}