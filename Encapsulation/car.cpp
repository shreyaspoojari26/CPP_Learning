#include <iostream>
using namespace std;

class Car {
private:
    int speed;

public:
    void setSpeed(int s) {
        speed = s;
    }

    void showSpeed() {
        cout << "Speed = " << speed << " km/h";
    }
};

int main() {
    Car c;

    c.setSpeed(80);
    c.showSpeed();

    return 0;
}
