#include<iostream>
#include<string>

using namespace std;

class father
{
public:
	int age;
	string name;
	string surname;
	father(int a = 0, string s = "a", string sur = "brown") : age(a), name(s), surname(sur) {}
	virtual void printAge()
	{
		cout << "father age:" << this->age << endl;
	}
	void printName()
	{
		cout << "father name:" << this->name << endl;
	}
	void printSurname()
	{
		cout << surname << endl;
	}
};
class son: public father
{
public:
	int age;
	string name;
	string surnames;
	son(int a = 0, string s = "a", string sur = "chari") : age(a), name(s), surnames(sur) {}
	void printAge()
	{
		cout << "son age:" << this->age << endl;
	}
	void printName()
	{
		cout << "son name:" << this->name << endl;
	}
};
int main()
{
	son s1(12,"bob");
	father f1(45,"Jake");

	s1.printSurname(); // base class function 
	cout << s1.surname << endl; // base field 
	cout << s1.surnames << endl;// heir field
	cout << endl;

	son *pSon = &s1;
	father *pFather = &s1;

	pSon->printAge(); // virtual
	pFather->printAge();
	pSon->printName(); // not virtual
	pFather->printName();
	return 0;
}