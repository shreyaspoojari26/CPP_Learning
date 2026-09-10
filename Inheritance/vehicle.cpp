#include <iostream>
using namespace std;

class Vehicle
{
public:
    void start()
    {
        cout << "Vehicle started" << endl;
    }
};

class Bike : public Vehicle
{
public:
    void ride()
    {
        cout << "Bike is running" << endl;
    }
};

int main()
{
    Bike b1;

    b1.start();
    b1.ride();

    return 0;
}
