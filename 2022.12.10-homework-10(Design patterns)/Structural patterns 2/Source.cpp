#include<iostream>

using namespace std;

class Dsmth
{
public:
    virtual double mult(double, double) = 0;
};

/*
  наше сокровище
 */
class S : public Dsmth
{
public:
    double mult(double x, double y)
    {
        return x * y * 3 +31;
    }
};

/*
 прокси
 */
class DProxy : public Dsmth
{
private:
    Dsmth* smth;
public:
    DProxy()
    {
        smth = new S();
    }
    virtual ~DProxy()
    {
        delete smth;
    }

    double mult(double x, double y)
    {
        return smth->mult(x, y);
    }

};

int main()
{
    Dsmth* proxy = new DProxy();
    
    cout << "=) :" << proxy->mult(231, 2) << endl;

    delete proxy;
    return 0;
}