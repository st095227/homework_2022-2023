#include<iostream>

using namespace std;

// Уже существующий класс расчета момента силы в СИ
class SIMomentSensor
{
public:
    // Получить показания момента в нормальной системе
    float getSIMoment() 
    {
        double m = 32.0;
        // ... умные сканирования
        return m;
    }
};

class Sensor
{
public:
    virtual ~Sensor() {}
    virtual double getMoment_lbf_ft() = 0;
};
// перевод в "странную" систему с помощью адаптера
class Adapter : public Sensor
{
private:
    SIMomentSensor* p_SIsensor;
public:
    Adapter(SIMomentSensor* p) : p_SIsensor(p) {}
    ~Adapter() 
    {
        delete p_SIsensor;
    }
    double getMoment_lbf_ft()
    {
        return p_SIsensor->getSIMoment() * 0.73756; 
    }
};

int main()
{
    Sensor* p = new Adapter(new SIMomentSensor);
    cout << "Moment in lbf*ft = " << p->getMoment_lbf_ft() << endl;

    delete p;
    return 0;
}