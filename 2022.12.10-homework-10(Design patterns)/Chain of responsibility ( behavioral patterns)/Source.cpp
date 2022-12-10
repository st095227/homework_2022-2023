#include<iostream>
//пишу глупый банкомат, выдающий по одной купюре

using namespace std;
class bill 
{

protected:

    int denomination;      // номинал купюры

    bill* next;    // номинал купюры меньше 

    virtual void withdrawal(int balance) {}    // само снятие

public:

    bill(int denomination) : denomination(denomination), next(nullptr) {}

    virtual ~bill() 
    {
        delete next;
    }

    /**
     * Добавляет в цепочку ответственности купюру меньше, если текущая(ие) не может быть выдана
     */
    bill* setNext(bill* bill) 
    {
        next = bill;
        return next;
    }

    /**
     * отдаёт купюру или передает младшей
     */
    void output(int balance) 
    {
        if (denomination > balance) 
        {
            if (next) {
                next->output(balance);
            }
            else {
                std::cout << "Такую сумму не выдать." << std::endl;
            }
        }
        else 
        {
            withdrawal(balance);
        }
    }
};

class Big_bill : public bill 
{

protected:
    void withdrawal(int balance) 
    {
        cout << "выдана купюра " << denomination << endl;
    }
public:
    Big_bill(int den) : bill(den) {}
};

class Medium_bill : public bill 
{

protected:
    void withdrawal(int balance) 
    {
        cout << "выдана купюра " << denomination << endl;
    }
public:
    Medium_bill(int den) : bill(den) {}
};

class Small_bill : public bill 
{

protected:
    void withdrawal(int balance) 
    {
        cout << "выдана купюра " << denomination << endl;
    }
public:
    Small_bill(int den) : bill(den) {}
};

int main() 
{
    setlocale(LC_ALL, "RUS");
    bill* pb = new Big_bill(5000);  // полицейский с наименьшим навыком ведения расследований
    pb->setNext(new Medium_bill(1000))->setNext(new Small_bill(500));
    pb->output(15000);
    pb->output(1500);
    pb->output(150);
    return 0;
}
