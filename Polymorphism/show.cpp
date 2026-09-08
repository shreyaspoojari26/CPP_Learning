#include <iostream>
using namespace std;

class Display {
public:
    void show(int num) {
        cout << "Number: " << num << endl;
    }

    void show(string text) {
        cout << "Text: " << text;
    }
};

int main() {
    Display d;

    d.show(100);
    d.show("Hello");

    return 0;
}
