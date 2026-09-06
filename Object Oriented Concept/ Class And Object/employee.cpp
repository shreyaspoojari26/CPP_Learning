#include <iostream>
using namespace std;

class Employee {
public:
    string name;
    int salary;

    void display() {
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary;
    }
};

int main() {
    Employee e;

    cout << "Enter employee name: ";
    cin >> e.name;

    cout << "Enter salary: ";
    cin >> e.salary;

    e.display();

    return 0;
}
