//#include<exception>
#include<memory>
#include<mutex>
#include<stack>
#include <atomic>
#include <iostream>
#include <thread>
#include <vector>
using namespace std;

/*struct empty_stack : std::exception
{
	const char* what() const throw();
};*/

template<typename T>
class threadsafe_stack
{
private:
	std::stack<T> data;
	mutable std::mutex m;
public:
	threadsafe_stack() {}
	threadsafe_stack(const threadsafe_stack& other)
	{
		std::lock_guard<std::mutex> lock(other.m);
		data = other.data; //Копирование производится в теле конструктора
	}

	threadsafe_stack& operator=(const threadsafe_stack&) = delete;

	void push(T new_value)
	{
		std::lock_guard<std::mutex> lock(m);
		data.push(new_value);
	}
	std::shared_ptr<T>pop() //Перед тем как выталкивать значение, проверяем,не пуст ли стек
	{
		std::lock_guard<std::mutex> lock(m);
		//if (data.empty()) throw empty_stack();
		std::shared_ptr<T> const res(std::make_shared<T>(data.top()));
		data.pop();//Перед тем как модифицировать стек в функции рор(), выделяем память для возвращаемого значения
		return res;
	}
	void рор(T& value)
	{
		std::lock_guard<std::mutex> lock(m);
		//if (data.empty()) throw empty_stack();
		value = data.top();
		data.pop();
	}
	bool empty() const
	{
		std::lock_guard<std::mutex> lock(m);
		return data.empty();
	}

};

template<typename T>
class lock_free_stack
{
private:
	struct node
	{
		std::shared_ptr<T> data;
		node* next;
		node(T const& data_) :
			data(std::make_shared<T>(data_))
		{}
	};
	std::atomic<node*> head;
public:
	void push(T const& data)
	{
		node* const new_node = new node(data);
		new_node->next = head.load();
		while (!head.compare_exchange_weak(new_node->next, new_node));
	}
	std::shared_ptr<T> pop()
	{
		node* old_head = head.load();
		while (old_head && !head.compare_exchange_weak(old_head, old_head->next));
		return old_head ? old_head->data : std::shared_ptr<T>();
	}
};
long long int foo1(threadsafe_stack<long long>& a, long long int n)
{
	long long int c = 0;
	for (long long int i = 0; i < n; ++i)
		c = *a.pop();
	return c;
}
long long int foo2(lock_free_stack<long long>& a, long long int n)
{
	long long int c = 0;
	for (long long int i = 0; i < n; ++i)
		c = *a.pop();
	return c;
}



int main()
{
	threadsafe_stack<long long> st1;
	//lock_free_stack<long long> st2;
	for (long long int i = 0; i < 10000000; ++i)
		st1.push(i);
	//for (long long i = 0; i < 10000000; ++i)
		//st2.push(i);

	srand(time(0));
	thread s1(foo1, ref(st1), 2500000);
	thread s2(foo1, ref(st1), 2500000);
	thread s3(foo1, ref(st1), 2500000);
	thread s4(foo1, ref(st1), 2500000);
	s1.join();
	s2.join(); // в первом случае время выполнения программы 7.3 сек
	s3.join();
	s4.join();

	/*thread s1(foo2, ref(st2), 2500000);
	thread s2(foo2, ref(st2), 2500000);
	thread s3(foo2, ref(st2), 2500000);
	thread s4(foo2, ref(st2), 2500000);
	s1.join();
	s2.join(); // во втором случае время выполнения программы 13.232 сек
	s3.join();
	s4.join();*/
	cout << "runtime = " << clock() << endl;
	return 0;
}