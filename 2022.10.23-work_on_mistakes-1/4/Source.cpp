#include<iostream>

using namespace std;
template<class word, int I>
class cell 
{
	int key;
	word * box;
	int size;
	
	void print()
	{
		cout << '(' << key;
		for (int i = 0; i < size; ++i)
		{
			cout << ',' << box[i];
		}
		cout << ')' << endl;
	}
public:
	cell(int key, word* box)
	{
		this->key = key;
		size = I;
		this->box = new  word[size];
		for (int i = 0; i < size; ++i)
		{
			this->box[i] = box[i];
		}
	}
	~cell()
	{
		key = 0;
		delete[] box;
	}
	cell(const cell& A)
	{
		size = A.size;
		box = new word[size];
		for (int i = 0; i < size; ++i)
		{
			box[i] = A.box[i];
		}
	}
	void access(int key)
	{
		if (this->key == key)
		{
			print();
		}
	}
};             // основной шаблон

template<class word>
class cell<word,1> 
{
	int key;
	word box;
	void print()
	{
		cout << '(' << key << ", " << box << ')' << endl;
	}
public:
	cell(int key, word box)
	{
		this->key = key;
		this->box = box;
	}
	~cell()
	{
		key = 0;
	}
	cell(const cell& A)
	{
		this->key = A.key;
		this->box = A.box;
	}
	void access(int key)
	{
		if (this->key == key)
		{
			print();
		}
	}
};   //частичная специализация

int main()
{
	cell<char, 1> b(123, 'h');
	char* a = new char[15];
	for (int i = 0; i < 15; ++i)
	{
		a[i] = i + 47;
	}
	cell<char, 15> v(122, a);
	b.access(123);
	cout << endl;
	v.access(122);
	return 0;
}
