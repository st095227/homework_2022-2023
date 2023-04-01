#include<deque>
#include<mutex>
#include<future>
#include<thread>
#include<utility>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
std::mutex m;
std::deque<std::packaged_task<std::vector<int>()>> create_tasks;
std::deque<std::packaged_task<vector<int>()>> sort_tasks;
std::deque <std::packaged_task<int()>> foo_tasks;

std::vector<int> createV(int a)
{
	std::vector<int> b(a);
	return b;
}

vector<int> sorting(vector<int> a)
{
	sort(a.begin(), a.end());
	return a;
}

int summ(vector<int> b)
{
	return 2;
}

void create_thread()
{
	while (1)
	{
		std::packaged_task<std::vector<int>()> task;
		{
			std::lock_guard<std::mutex> lk(m);
			if (create_tasks.empty())
				continue;
			task = std::move(create_tasks.front());
			create_tasks.pop_front();
		}
		task();
	}
}
void sort_thread()
{
	while (1)
	{
		std::packaged_task<std::vector<int>()> task;
		{
			std::lock_guard<std::mutex> lk(m);
			if (sort_tasks.empty())
				continue;
			task = std::move(sort_tasks.front());
			sort_tasks.pop_front();
		}
		task();
	}
}
void foo_thread()
{
	while (1)
	{
		std::packaged_task<int()> task;
		{
			std::lock_guard<std::mutex> lk(m);
			if (foo_tasks.empty())
				continue;
			task = std::move(foo_tasks.front());
			foo_tasks.pop_front();
		}
		task();
	}
}

//std::thread th1(create_thread);

//template<typename Func>
int create_task_for_thread(int a)
{
	std::packaged_task<vector<int>()> task(bind(createV,a));
	std::future<vector<int>> res = task.get_future();
	{
		std::lock_guard<std::mutex> lk(m);
		create_tasks.push_back(std::move(task));
	}
	
	
	std::packaged_task<vector<int>()> task2(bind(sorting, res.get()));

	std::future<vector<int>> res2 = task2.get_future();
	{
		std::lock_guard<std::mutex> lk(m);
		sort_tasks.push_back(std::move(task2));
	}
	std::packaged_task<int()> task3(bind(summ, res2.get()));

	std::future<int> res3 = task3.get_future();
	{
		std::lock_guard<std::mutex> lk(m);
		foo_tasks.push_back(std::move(task3));
	}
	return res3.get();
	
}

int main()
{
	std::thread th1(create_thread);
	std::thread th2(sort_thread);
	std::thread th3(foo_thread);
	
	cout << create_task_for_thread(12);
	return 0;
}