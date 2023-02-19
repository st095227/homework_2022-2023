#include<iostream>
#include <stdexcept>
using namespace std;

double divide(double a, double b)
{
    if (b == 0)
        throw runtime_error("Division by zero!");
	return a / b;
}
void ch(int a)
{
    if (a > 255)
        throw invalid_argument("ch argument too large.");
    //???
}

int main()
{
    try
    {
        ch(288);
        double a = divide(1221, 0);
    }

    catch (invalid_argument& err)
    {
        cout << "Invalid argument: " << err.what() << std::endl;
        return -1;
    }
    catch (std::runtime_error err)
    {
        std::cout << "Runtime error: " << err.what() << std::endl;
        return -1;
    }
    return 0;
}