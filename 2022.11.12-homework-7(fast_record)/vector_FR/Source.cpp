#include<iostream>
#include<fstream>
using namespace std;

template<typename t>
class VectorM
{
public:
	t* data;
	int capacity;
	int count;
	VectorM<t>(int capacity)
	{
		this->capacity = capacity;
		this->count = 0;
		data = new t[capacity];
	}
	void expand(int count = 1)
	{
		t* newdata = new t[count + this->capacity];
		for (int i = 0; i < this->capacity; ++i)
		{
			newdata[i] = this->data[i];
		}
		delete[] this->data;
		this->data = newdata;
		this->capacity += count;
	}
	void swap(int posi, int posj)
	{
		int m = this->data[ind(posi)];
		this->data[ind(posi)] = this->data[ind(posj)];
		this->data[ind(posj)] = m;
	}
	int ind(int index)
	{
		if (index < 0)
		{
			pushbegin(0);
			return 0;
		}
		if (index >= this->count)
		{
			pushend(0);
			return this->count - 1;
		}
		return index;
	}

	VectorM<t>(const VectorM<t>& list)
	{
		this->capacity = list.count;
		this->count = list.count;
		this->data = new t[list.count];
		for (int i = 0; i < list.count; ++i)
		{
			this->data[i] = list.data[i];
		}
	}
	~VectorM<t>()
	{
		this->count = 0;
		this->capacity = 0;
		delete[] this->data;
	}

	void pushend(t element)
	{
		if (this->count == this->capacity)
		{
			expand(this->capacity);
		}
		this->data[this->count] = element;
		this->count++;
	}
	void pushbegin(t element)
	{
		if (this->count == this->capacity)
		{
			expand(this->capacity);
		}
		pushend(0);
		for (int i = count - 1; i > 0; --i)
		{
			this->data[i] = this->data[i - 1];
		}
		this->data[0] = element;
	}

	void insert(t element, int position)
	{
		if (position <= 0)
		{
			pushbegin(element);
		}
		else if (position >= (count - 1))
		{
			pushend(element);
		}
		else
		{
			pushend(0);
			for (int i = count - 1; i > position; --i)
			{
				this->data[i] = this->data[i - 1];
			}
			this->data[position] = element;
		}
	}
	t extractbegin()
	{
		int m = this->data[0];
		for (int i = 0; i < (count - 1); ++i)
		{
			this->data[i] = this->data[i + 1];
		}
		this->count--;
		return m;
	}
	t extractend()
	{
		this->count--;
		return this->data[this->count];
	}
	t extract(int position)
	{
		if (position <= 0)
		{
			return extractbegin();
		}
		else if (position >= (count - 1))
		{
			return extractend();
		}
		else
		{
			int m = this->data[position];
			for (int i = position; i < (count - 1); ++i)
			{
				this->data[i] = this->data[i + 1];
			}
			this->count--;
			return m;
		}
	}

	t& operator[](int pos)
	{
		return data[ind(pos)];
	}


	friend std::ostream& operator<<(std::ostream& stream, const VectorM<t>& list)
	{
		stream << "[" << list.count << "/" << list.capacity << "] {";
		if (list.count == 0)
		{
			stream << "EMPTY";
		}
		else
		{
			for (int i = 0; i < list.count - 1; ++i)
			{
				stream << list.data[i] << ", ";
			}
			stream << list.data[list.count - 1];
		}
		stream << "}";
		return stream;
	}
	friend std::istream& operator>>(std::istream& stream, const VectorM<t>& list)
	{
		for (int i = 0; i < list.capacity; ++i)
		{
			stream >> list.data[i];
		}
		return stream;
	}

	VectorM operator=(const VectorM<t>& arr)
	{
		this->count = arr.count;
		this->capacity = arr.capacity;
		delete[] data;
		data = new int[capacity];
		for (int i = 0; i < this->count; ++i)
		{
			data[i] = arr.data[i];
		}
		return *this;
	}
	
};
template<class T>
void write_in_file(VectorM<T> &s)
{
	ofstream file("output.txt");
	//file.seekg(0);
	int n = (s.count) * (sizeof s.data[0]) + 8;
	char* ch1 = new char[n];
	ch1 = reinterpret_cast<char*>(&s);
	file.write(ch1, n);
	file.close();
}

template<class T>
VectorM<T>* read_from_file(ifstream &file)
{
	file.clear();
	file.seekg(0);
	int b = 0;
	char a;
	while (file >> a)
	{
		++b;
	}
	cout << b;
	file.clear();
	file.seekg(0);
	char* ch = new char[b];
	file.read(ch, b);
	VectorM<T>* ps;
	ps = reinterpret_cast<VectorM<T>*>(ch);
	return ps;
	delete[] ch;
	//file.close();
}

int main(int argc, char** argv)
{
	VectorM<int> s(5);
	s[0] = 1;
	s[1] = 2;
	s[2] = 3;
	s[3] = 4;
	s[4] = 5;


	write_in_file(s);
	ifstream in("output.txt", ios::binary);

	cout << *read_from_file<int>(in);
	in.close();
	return 0;
}