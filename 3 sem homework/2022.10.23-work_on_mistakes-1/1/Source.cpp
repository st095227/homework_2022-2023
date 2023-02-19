#include<iostream>

using namespace std;
//when does the destructor work?
//1.A local(automatic) object with block scope goes out of scope.
//2.An object allocated using the new operator is explicitly deallocated using delete.
//3.The lifetime of a temporary object ends.
//4.A program endsand global or static objects exist.
//5.The destructor is explicitly called using the destructor function's fully qualified name.

struct some_struct
{
	int b;
	some_struct(int b)
	{
		this->b = b;
	}
	some_struct()
	{
		this->b = 0;
	}

	~some_struct()
	{
		cout << "number:" << this->b << " " << "destructor worked" << endl;
		b = 0;
	}
	some_struct operator+(some_struct &b)
	{
		return some_struct(this->b + b.b);
	}
};

int main()
{
	//1
	int c = 1;
	cout << "1.";
	if (c)
	{
		some_struct d; 
	}
	//2
	cout << "2.";
	some_struct* a = new some_struct; 
	delete a;
	//3
	cout << "3.";
	some_struct f(7);
	some_struct b(12);
	some_struct e(3);
	cout << endl;
	e = f + b;
	//5
	some_struct j(58);
	cout << "5." << endl;
	j.~some_struct();
	//4
	cout << "4." << endl;
	return 0;
}