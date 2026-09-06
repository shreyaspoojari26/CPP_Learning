#include <iostream>
using namespace std;

class Person {
private:
    int age;

public:
    void setAge(int a) {
        if (a >= 0 && a <= 100)
            age = a;
        else
            cout << "Invalid age";
    }

    void showAge() {
        cout << "Age = " << age;
    }
};

int main() {
    Person p;

    p.setAge(21);
    p.showAge();

    return 0;
}
