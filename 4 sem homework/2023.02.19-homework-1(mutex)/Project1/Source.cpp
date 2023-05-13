#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

void PowPrint(long long int n, long long int m)
{
	cout << m << ": ";
	long long int j = m;
	for (int i = 0; i < n;++i)
	{
		cout << m << " ";
		m = m * j;
	}
	cout << endl;
}

template<typename T1, typename T2>
using Foo = T1(*)(T2, T2);

class Shell
{
private:
	mutex mut;
	Foo<void, long long int> foo;
public:
	Shell(Foo<void, long long int> f)
	{
		foo = f;
	}
	void operator()(long long int n, long long int m)
	{
		lock_guard<mutex> lock(mut);
		foo(n, m);
	}
};


int main()
{
	Shell sh(&PowPrint);
	thread S1(ref(sh), 6, 3);
	thread S2(ref(sh), 5, 2);
	thread S3(ref(sh), 4, 11);
	thread S4(ref(sh), 3, 1);
	S1.join();
	S2.join();
	S3.join();
	S4.join();
	return 0;
}