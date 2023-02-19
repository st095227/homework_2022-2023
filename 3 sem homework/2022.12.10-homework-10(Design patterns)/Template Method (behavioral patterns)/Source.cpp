#include <iostream>
using namespace std;

class Base
{
    void a()
    {
        cout << "� ";
    }
    void b()
    {
        cout << "������ ";
    }
    void c()
    {
        cout << ", ��� ";
    }
    //    "����������" ������.
    virtual void ph1() = 0;
    virtual void ph2() = 0;
public:
   // ����� ����������� ��������
    void print()
    {
        a();
        b();
        ph1();
        c();
        ph2();
    }
};

class One : public Base
{
    // 3. ����������� ������ ��������� "����������" ������.
    void ph1()
    {
        cout << "�����";
    }
    void ph2()
    {
        cout << "������ ";
    }
};

class Two : public Base
{
    void ph1()
    {
        cout << "� �����";
    }
    void ph2()
    {
        cout << "���� ";
    }
};

int main()
{
    setlocale(LC_ALL, "RUS");
    Base* array[2];
    One o; Two t;
    array[0] = &o;
    array[1] = &t;
    for (int i = 0; i < 2; i++)
    {
        array[i]->print();
        cout << endl;
    }
}