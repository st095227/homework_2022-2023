#include "Array.h"

void Array::expand(int count)
{
	int* newdata = new int[count + this->capacity];
	for (int i = 0; i < this->capacity; ++i)
	{
		newdata[i] = this->data[i];
	}
	delete[] this->data;
	this->data = newdata;
	this->capacity += count;
}
Array::Array(int capacity)
{
	this->capacity = capacity;
	this->count = 0;
	this->data = new int[capacity];
}
Array::Array(const Array& arr)
{
	this->capacity = arr.capacity;
	this->count = arr.count;
	this->data = new int[arr.count];
	for (int i = 0; i < arr.count; ++i)
	{
		this->data[i] = arr.data[i];
	}
}
Array::~Array()
{
	this->count = 0;
	this->capacity = 0;
	delete[] this->data;
}

int Array::get(int position)
{
	if (position >= count)
	{
		return this->data[count-1];
	}
	else
	{
		return this->data[position];
	}
}
void Array::set(int position, int element)
{
	if (position > (count-1))
	{
		expand();
		this->data[count] = element;
		++this->count;
	}
	else
	{
		this->data[position] = element;
		++this->count;
	}
}



Array Array::operator=(const Array& arr)
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