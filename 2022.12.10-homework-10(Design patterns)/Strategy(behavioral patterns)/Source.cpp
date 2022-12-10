#include <iostream>

using namespace std;

class Pizza
{
public:
    virtual ~Pizza() {}
    virtual void cut() = 0;
};

class rectangle_pizza : public Pizza
{
public:
    void cut() 
    {
        cout << "rectangle pieces" << endl;
    }
};

class round_pizza : public Pizza
{
public:
    void cut() 
    {
        cout << "triangle pieces" << endl;
    }
};



// Класс для использования
class pizza_maker
{
private:
    Pizza* p;
public:
    pizza_maker(Pizza* piz) : p(piz) {}
    ~pizza_maker() { delete p; }
    void cutting() 
    {
        p->cut();
    }
};


int main()
{
    pizza_maker* p = new pizza_maker(new round_pizza); //создаём нового повора, который готовит круглую пиццу
    p->cutting();
    delete p;
    return 0;
}