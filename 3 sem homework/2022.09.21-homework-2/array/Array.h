#pragma once

class Array
{
	int* data;
	int capacity;
	int count;
	void expand(int count = 10);
public:
	Array(int capacity = 10);
	Array(const Array& arr);
	~Array();
	Array operator=(const Array& arr);

	int get(int position);
	void set(int position, int element);
};