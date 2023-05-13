#include<iostream>
#include <queue>
#include <memory>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

template<typename T>
class threadsafe_queue
	{
private:
	mutable mutex mut;
	std::queue<T> data_queue;
	condition_variable data_cond;
public:
	threadsafe_queue()
	{}
	threadsafe_queue(threadsafe_queue const& other)
	{
		lock_guard<mutex> lk(other.mut);
		data_queue = other.data_queue;
	}
	void push(T new_value)
	{
		lock_guard<mutex> lk(mut);
		data_queue.push(new_value);
		data_cond.notify_all();
	}
	void wait_and_pop(T& value)
	{
		unique_lock<mutex> lk(mut);
		data_cond.wait(lk,[this]{return !data_queue.empty();});
		value = data_queue.front();
		data_queue.pop();
	}
	shared_ptr<T> wait_and_pop()
	{
		unique_lock<mutex> lk(mut);
		data_cond.wait(lk,[this]{return !data_queue.empty();});
		shared_ptr<T> res(make_shared<T>(data_queue.front()));
		data_queue.pop();
		return res;
	}
	bool try_pop(T& value)
	{
		lock_guard<mutex> lk(mut);
		if (data_queue.empty())
			return false;
		value = data_queue.front();
		data_queue.pop();
		return true;
	}
	shared_ptr<T> try_pop()
	{
	lock_guard<mutex> lk(mut);
	if (data_queue.empty())
		return shared_ptr<T>();
	shared_ptr<T> res(std::make_shared<T>(data_queue.front()));
	data_queue.pop();
	return	res;
	}
	bool empty() const
	{
		lock_guard<mutex> lk(mut);
		return data_queue.empty();
	}
};
threadsafe_queue<short> a;

void generator(int k)
{
	for (int i = 0; i < k; ++i)
	{
		Sleep(600);
		//srand(time(NULL));
		//int num =	rand() % (9);
		a.push(1);
	}
}

void processing(int k)
{
	for (int i = 0; i < k; ++i)
	{
		short c;
		a.wait_and_pop(c);
		Sleep(200);
	}
	
}

int main()
{
	thread S1(generator, 75);
	thread S2(generator,  75);
	thread S3(processing, 75);
	thread S4(processing, 75);
	S1.join();
	S2.join();
	S3.join();
	S4.join();
	if (a.empty()) cout << 'y' << endl;
	cout << "runtime = " << clock() << endl;
	return 0;
}