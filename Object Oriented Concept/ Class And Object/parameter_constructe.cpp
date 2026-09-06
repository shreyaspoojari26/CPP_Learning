#include <iostream>
using namespace std;

class Rectangle {
public:
    int length;
    int width;

    Rectangle(int l, int w) {
        length = l;
        width = w;
    }

    void area() {
        cout << "Area = " << length * width;
    }
};

int main() {
    Rectangle r(10, 5);

    r.area();

    return 0;
}
