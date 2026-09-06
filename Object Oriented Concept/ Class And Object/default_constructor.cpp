#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int age;

    Student() {
        name = "Shreyas";
        age = 21;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age;
    }
};

int main() {
    Student s;

    s.display();

    return 0;
}
