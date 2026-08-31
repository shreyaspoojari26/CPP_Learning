#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Book
{
    int id;
    char title[30];
    char author[30];
    int issued;
};

struct Member
{
    int id;
    char name[30];
};

void addBook()
{
    Book b;

    cout << "Enter Book ID: ";
    cin >> b.id;

    cout << "Enter Title: ";
    cin >> b.title;

    cout << "Enter Author: ";
    cin >> b.author;

    b.issued = 0;

    ofstream file("library.dat", ios::binary | ios::app);
    file.write((char*)&b, sizeof(b));
    file.close();

    cout << "Book added successfully!\n";
}

void displayBooks()
{
    Book b;

    ifstream file("library.dat", ios::binary);

    cout << "\n--- Books ---\n";

    while (file.read((char*)&b, sizeof(b)))
    {
        cout << "\nID: " << b.id;
        cout << "\nTitle: " << b.title;
        cout << "\nAuthor: " << b.author;

        if (b.issued == 1)
            cout << "\nStatus: Issued\n";
        else
            cout << "\nStatus: Available\n";
    }

    file.close();
}

void searchBook()
{
    Book b;
    char search[30];
    int found = 0;

    cout << "Enter title or author: ";
    cin >> search;

    ifstream file("library.dat", ios::binary);

    while (file.read((char*)&b, sizeof(b)))
    {
        if (strcmp(b.title, search) == 0 ||
            strcmp(b.author, search) == 0)
        {
            cout << "\nID: " << b.id;
            cout << "\nTitle: " << b.title;
            cout << "\nAuthor: " << b.author << endl;

            found = 1;
        }
    }

    file.close();

    if (found == 0)
        cout << "Book not found!\n";
}

void issueBook()
{
    Book b;
    int id;
    int found = 0;

    cout << "Enter Book ID: ";
    cin >> id;

    fstream file("library.dat", ios::binary | ios::in | ios::out);

    while (file.read((char*)&b, sizeof(b)))
    {
        if (b.id == id)
        {
            found = 1;

            if (b.issued == 1)
            {
                cout << "Book is already issued!\n";
            }
            else
            {
                b.issued = 1;

                file.seekp(-sizeof(b), ios::cur);
                file.write((char*)&b, sizeof(b));

                cout << "Book issued successfully!\n";
            }

            break;
        }
    }

    file.close();

    if (found == 0)
        cout << "Book not found!\n";
}

void returnBook()
{
    Book b;
    int id;
    int found = 0;

    cout << "Enter Book ID: ";
    cin >> id;

    fstream file("library.dat", ios::binary | ios::in | ios::out);

    while (file.read((char*)&b, sizeof(b)))
    {
        if (b.id == id)
        {
            found = 1;

            b.issued = 0;

            file.seekp(-sizeof(b), ios::cur);
            file.write((char*)&b, sizeof(b));

            cout << "Book returned successfully!\n";
            break;
        }
    }

    file.close();

    if (found == 0)
        cout << "Book not found!\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== LIBRARY MANAGEMENT =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addBook();
                break;

            case 2:
                displayBooks();
                break;

            case 3:
                searchBook();
                break;

            case 4:
                issueBook();
                break;

            case 5:
                returnBook();
                break;

            case 6:
                cout << "Thank you!\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
