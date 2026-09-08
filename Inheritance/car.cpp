#include <iostream>
using namespace std;

class Vehicle {
public:
    void start() {
        cout << "Vehicle starts" << endl;
    }
};

class Car : public Vehicle {
public:
    void drive() {
        cout << "Car is driving";
    }
};

int main() {
    Car c;

    c.start();
    c.drive();

    return 0;
}
