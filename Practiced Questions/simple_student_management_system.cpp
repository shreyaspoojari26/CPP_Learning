// SIMPLE STUDENT MANAGEMENT SYSTEM
#include <iostream>
#include <fstream>
using namespace std;

struct Student
{
    int rollNo;
    char name[50];
    int age;
    char course[30];
};

// Add Student
void addStudent()
{
    Student s;

    cout << "\nEnter Roll Number: ";
    cin >> s.rollNo;

    cout << "Enter Name: ";
    cin >> s.name;

    cout << "Enter Age: ";
    cin >> s.age;

    cout << "Enter Course: ";
    cin >> s.course;

    ofstream file("students.dat", ios::binary | ios::app);

    file.write((char*)&s, sizeof(s));

    file.close();

    cout << "\nStudent added successfully!\n";
}

// Display Students
void displayStudents()
{
    Student s;

    ifstream file("students.dat", ios::binary);

    cout << "\n========== STUDENT RECORDS ==========\n";

    while (file.read((char*)&s, sizeof(s)))
    {
        cout << "\nRoll Number : " << s.rollNo;
        cout << "\nName        : " << s.name;
        cout << "\nAge         : " << s.age;
        cout << "\nCourse      : " << s.course;
        cout << "\n-------------------------------------\n";
    }

    file.close();
}

// Update Student
void updateStudent()
{
    Student s;
    int roll;
    bool found = false;

    cout << "\nEnter Roll Number to update: ";
    cin >> roll;

    fstream file("students.dat", ios::binary | ios::in | ios::out);

    while (file.read((char*)&s, sizeof(s)))
    {
        if (s.rollNo == roll)
        {
            cout << "Enter New Name: ";
            cin >> s.name;

            cout << "Enter New Age: ";
            cin >> s.age;

            cout << "Enter New Course: ";
            cin >> s.course;

            file.seekp(-sizeof(s), ios::cur);
            file.write((char*)&s, sizeof(s));

            found = true;
            break;
        }
    }

    file.close();

    if (found)
        cout << "\nStudent updated successfully!\n";
    else
        cout << "\nStudent not found!\n";
}

// Delete Student
void deleteStudent()
{
    Student s;
    int roll;
    bool found = false;

    cout << "\nEnter Roll Number to delete: ";
    cin >> roll;

    ifstream file("students.dat", ios::binary);
    ofstream temp("temp.dat", ios::binary);

    while (file.read((char*)&s, sizeof(s)))
    {
        if (s.rollNo == roll)
        {
            found = true;
        }
        else
        {
            temp.write((char*)&s, sizeof(s));
        }
    }

    file.close();
    temp.close();

    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (found)
        cout << "\nStudent deleted successfully!\n";
    else
        cout << "\nStudent not found!\n";
}

// Main Function
int main()
{
    int choice;

    do
    {
        cout << "\n\n===== STUDENT MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Student";
        cout << "\n2. Display Students";
        cout << "\n3. Update Student";
        cout << "\n4. Delete Student";
        cout << "\n5. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                updateStudent();
                break;

            case 4:
                deleteStudent();
                break;

            case 5:
                cout << "\nProgram ended.";
                break;

            default:
                cout << "\nInvalid choice!";
        }

    } while (choice != 5);

    return 0;
}
