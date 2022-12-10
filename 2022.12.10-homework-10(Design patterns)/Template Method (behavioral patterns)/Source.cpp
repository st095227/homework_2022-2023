#include <iostream>
using namespace std;

class Base
{
    void a()
    {
        cout << "Я ";
    }
    void b()
    {
        cout << "пришёл ";
    }
    void c()
    {
        cout << ", там ";
    }
    //    "замещающие" методы.
    virtual void ph1() = 0;
    virtual void ph2() = 0;
public:
   // задаём стандартный алгоритм
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
    // 3. Производные классы реализуют "замещающие" методы.
    void ph1()
    {
        cout << "домой";
    }
    void ph2()
    {
        cout << "собака ";
    }
};

class Two : public Base
{
    void ph1()
    {
        cout << "в школу";
    }
    void ph2()
    {
        cout << "люди ";
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