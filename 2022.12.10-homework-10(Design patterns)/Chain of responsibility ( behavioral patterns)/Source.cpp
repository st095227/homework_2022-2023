#include<iostream>
//���� ������ ��������, �������� �� ����� ������

using namespace std;
class bill 
{

protected:

    int denomination;      // ������� ������

    bill* next;    // ������� ������ ������ 

    virtual void withdrawal(int balance) {}    // ���� ������

public:

    bill(int denomination) : denomination(denomination), next(nullptr) {}

    virtual ~bill() 
    {
        delete next;
    }

    /**
     * ��������� � ������� ��������������� ������ ������, ���� �������(��) �� ����� ���� ������
     */
    bill* setNext(bill* bill) 
    {
        next = bill;
        return next;
    }

    /**
     * ����� ������ ��� �������� �������
     */
    void output(int balance) 
    {
        if (denomination > balance) 
        {
            if (next) {
                next->output(balance);
            }
            else {
                std::cout << "����� ����� �� ������." << std::endl;
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
        cout << "������ ������ " << denomination << endl;
    }
public:
    Big_bill(int den) : bill(den) {}
};

class Medium_bill : public bill 
{

protected:
    void withdrawal(int balance) 
    {
        cout << "������ ������ " << denomination << endl;
    }
public:
    Medium_bill(int den) : bill(den) {}
};

class Small_bill : public bill 
{

protected:
    void withdrawal(int balance) 
    {
        cout << "������ ������ " << denomination << endl;
    }
public:
    Small_bill(int den) : bill(den) {}
};

int main() 
{
    setlocale(LC_ALL, "RUS");
    bill* pb = new Big_bill(5000);  // ����������� � ���������� ������� ������� �������������
    pb->setNext(new Medium_bill(1000))->setNext(new Small_bill(500));
    pb->output(15000);
    pb->output(1500);
    pb->output(150);
    return 0;
}
