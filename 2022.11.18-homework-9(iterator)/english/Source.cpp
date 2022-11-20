#include<iostream>
#include<fstream>
#include<map>
#include<string>

using namespace std;

class dictionary
{
	map<string, string> dict;
public:
	void add(string we, string wi)
	{
		dict[we] = wi;
	}
	void read(string file_name)
	{
		ifstream file(file_name);
		while (!file.eof())
		{
			string we, wi;
			getline(file, we, ' ');
			getline(file, wi);
			dict[we] = wi;
		}
		file.close();
	}
	void f_symbolB(char n)
	{
		cout << "British words starting with a letter: " << n << endl;
		map<string, string>::iterator it = dict.begin();
		while (it != dict.end())
		{
			if (it->first[0] == n)
				cout << it->first << " " << it->second << endl;
			else if (it->first[0] > n)
			{
				return;
			}
			++it;
		}
	}
	void f_symbolI(char n)
	{
		cout << "Indian words starting with a letter: " << n << endl;
		map<string, string>::iterator it = dict.begin();
		while (it != dict.end())
		{
			if (it->second[0] == n)
				cout << it->first << " " << it->second << endl;
			++it;
		}
	}
	void searchB(string we)
	{
		map<string, string>::iterator it = dict.begin();
		while (it != dict.end())
		{
			if (it->first == we)
			{
				cout << it->first << " " << it->second << endl;
				return;
			}
			++it;
		}
	}
	void searchI(string wi)
	{
		map<string, string>::iterator it = dict.begin();
		while (it != dict.end())
		{
			if (it->second == wi)
				cout << it->first << " " << it->second << endl;
			++it;
		}
	}
	void translate_in_fileB(string in_name, string out_name)
	{
		ifstream in(in_name);
		ofstream out(out_name);
		while (!in.eof())
		{
			string word;
			getline(in, word, ' ');
			out << dict[word] << " ";
		}
		in.close();
		out.close();
	}
	void translate_in_fileI(string in_name, string out_name)
	{
		ifstream in(in_name);
		ofstream out(out_name);
		map<string, string>::iterator it = dict.begin();
		while (!in.eof())
		{
			string word;
			getline(in, word, ' ');
			while ((it != dict.end())&&(it->second != word))
			{
				++it;
			}
			out << it->first << " ";
			it = dict.begin();
		}
		in.close();
		out.close();
	}
	void print()
	{
		map<string, string>::iterator it = dict.begin();
		while (it != dict.end())
		{
			cout << it->first << " " << it->second << endl;
			++it;
		}
	}
};

int main()
{
	dictionary eng;
	eng.read("words.txt");
	eng.translate_in_fileB("original.txt", "copy.txt");
	return 0;
}