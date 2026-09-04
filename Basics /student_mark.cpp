#include <iostream>
using namespace std;

int main() {
    string name;
    int mark1, mark2, mark3;

    cout << "Enter name: ";
    cin >> name;

    cout << "Enter marks for 3 subjects: ";
    cin >> mark1 >> mark2 >> mark3;

    int total = mark1 + mark2 + mark3;
    float average = total / 3.0;

    cout << "\nName: " << name << endl;
    cout << "Total: " << total << endl;
    cout << "Average: " << average << endl;

    if (average >= 40)
        cout << "Result: Pass" << endl;
    else
        cout << "Result: Fail" << endl;

    return 0;
}
