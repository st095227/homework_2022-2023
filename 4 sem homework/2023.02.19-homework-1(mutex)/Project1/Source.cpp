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
public:
	void shell(Foo<void, long long int> f, long long int n, long long int m)
	{
		lock_guard<mutex> lock(mut);
		f(n, m);
	}
};

void PowPrint_S(Shell &sh, long long int n, long long int m)
{
	sh.shell(PowPrint,n,m);
}
void PowPrint_Ss(Shell& sh, Foo<void, long long int> f, long long int n, long long int m) // второй вариант
{
	sh.shell(f, n, m);
}

int main()
{
	Shell sh;
	//PowPrint_S(sh, func, 2, 2);
	thread S1(PowPrint_S, ref(sh), 6, 3);
	thread S2(PowPrint_S, ref(sh), 5, 2);
	thread S3(PowPrint_S, ref(sh), 4, 11);
	thread S4(PowPrint_S, ref(sh), 3, 1);
	thread S5(PowPrint_Ss, ref(sh), PowPrint, 3, 7); // второй вариант
	S1.join();
	S2.join();
	S3.join();
	S4.join();
	S5.join();
	return 0;
}