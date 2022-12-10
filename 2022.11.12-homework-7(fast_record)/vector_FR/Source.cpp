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
		t m = this->data[ind(posi)];
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
		t m = this->data[0];
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
			t m = this->data[position];
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
		if (&arr == this)
		{
			return *this;
		}
		this->count = arr.count;
		this->capacity = arr.capacity;
		delete[] data;
		data = new t[capacity];
		for (int i = 0; i < this->count; ++i)
		{
			data[i] = arr.data[i];
		}
		return *this;
	}
	
};
template<class T>
void write_in_file(VectorM<T> &s, string st)
{
	ofstream file(st);
	//file.seekg(0);
	int n = (s.count) * (sizeof s.data[0]);
	file << s.count;
	file.write(reinterpret_cast<char*>(s.data), n);
	file.close();
}

template<class T>
VectorM<T> read_from_file(ifstream& file)
{
	file.clear();
	file.seekg(0);
	int b = 0;
	file >> b;
	VectorM<T> v(b);
	char* ch = new char[b*sizeof(T)+1];
	ch[b * sizeof(T)] = 0;
	file.read(ch,b * sizeof(T));
	v.count = b;
	v.data = reinterpret_cast<T*>(ch);
	return v;
	file.close();
}

int main(int argc, char** argv)
{
	VectorM<int> s(5);
	s[0] = 123;
	s[1] = 1221;
	s[2] = 5;
	s[3] = 8;
	s[4] = 99;
	VectorM<char> s1(5);
	s1[0] = 'b';
	s1[1] = 'b';
	s1[2] = 'a';
	s1[3] = 'a';
	s1[4] = 'c';

	//write_in_file(s, "output.txt");
	//write_in_file(s1, "output1.txt");
	ifstream in("output.txt");
	ifstream in1("output1.txt");
	cout << read_from_file<int>(in);
	cout << read_from_file<char>(in1);
	return 0;
}