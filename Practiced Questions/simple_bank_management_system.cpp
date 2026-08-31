// SIMPLE BANK MANAGEMENT SYSTEM

#include <iostream>
#include <fstream>
using namespace std;

class Bank
{
private:
    int accountNo;
    char name[50];
    float balance;

public:

    // Create Account
    void createAccount()
    {
        cout << "\nEnter Account Number: ";
        cin >> accountNo;

        cout << "Enter Customer Name: ";
        cin >> name;

        cout << "Enter Initial Balance: ";
        cin >> balance;

        cout << "\nAccount created successfully!\n";
    }

    // Display Account
    void display()
    {
        cout << "\nAccount Number : " << accountNo;
        cout << "\nCustomer Name  : " << name;
        cout << "\nBalance        : Rs. " << balance << endl;
    }

    // Deposit
    void deposit()
    {
        float amount;

        cout << "\nEnter Deposit Amount: ";
        cin >> amount;

        balance = balance + amount;

        cout << "Amount deposited successfully!\n";
        cout << "New Balance: Rs. " << balance << endl;
    }

    // Withdraw
    void withdraw()
    {
        float amount;

        cout << "\nEnter Withdrawal Amount: ";
        cin >> amount;

        if (amount <= balance)
        {
            balance = balance - amount;
            cout << "Amount withdrawn successfully!\n";
            cout << "New Balance: Rs. " << balance << endl;
        }
        else
        {
            cout << "Insufficient balance!\n";
        }
    }

    // Get Account Number
    int getAccountNo()
    {
        return accountNo;
    }
};


// Create Account
void createAccount()
{
    Bank b;

    ofstream file("bank.dat", ios::binary | ios::app);

    b.createAccount();

    file.write((char*)&b, sizeof(b));

    file.close();
}


// Display All Accounts
void displayAccounts()
{
    Bank b;

    ifstream file("bank.dat", ios::binary);

    cout << "\n========== BANK ACCOUNTS ==========\n";

    while (file.read((char*)&b, sizeof(b)))
    {
        b.display();
        cout << "-----------------------------------\n";
    }

    file.close();
}


// Deposit Money
void depositMoney()
{
    Bank b;
    int account;
    bool found = false;

    cout << "\nEnter Account Number: ";
    cin >> account;

    fstream file("bank.dat", ios::binary | ios::in | ios::out);

    while (file.read((char*)&b, sizeof(b)))
    {
        if (b.getAccountNo() == account)
        {
            b.deposit();

            file.seekp(-sizeof(b), ios::cur);
            file.write((char*)&b, sizeof(b));

            found = true;
            break;
        }
    }

    file.close();

    if (!found)
        cout << "Account not found!\n";
}


// Withdraw Money
void withdrawMoney()
{
    Bank b;
    int account;
    bool found = false;

    cout << "\nEnter Account Number: ";
    cin >> account;

    fstream file("bank.dat", ios::binary | ios::in | ios::out);

    while (file.read((char*)&b, sizeof(b)))
    {
        if (b.getAccountNo() == account)
        {
            b.withdraw();

            file.seekp(-sizeof(b), ios::cur);
            file.write((char*)&b, sizeof(b));

            found = true;
            break;
        }
    }

    file.close();

    if (!found)
        cout << "Account not found!\n";
}


// Check Balance
void checkBalance()
{
    Bank b;
    int account;
    bool found = false;

    cout << "\nEnter Account Number: ";
    cin >> account;

    ifstream file("bank.dat", ios::binary);

    while (file.read((char*)&b, sizeof(b)))
    {
        if (b.getAccountNo() == account)
        {
            b.display();
            found = true;
            break;
        }
    }

    file.close();

    if (!found)
        cout << "Account not found!\n";
}


// Main Function
int main()
{
    int choice;

    do
    {
        cout << "\n\n========== BANK MANAGEMENT SYSTEM ==========";
        cout << "\n1. Create Account";
        cout << "\n2. Display Accounts";
        cout << "\n3. Deposit Money";
        cout << "\n4. Withdraw Money";
        cout << "\n5. Check Balance";
        cout << "\n6. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                createAccount();
                break;

            case 2:
                displayAccounts();
                break;

            case 3:
                depositMoney();
                break;

            case 4:
                withdrawMoney();
                break;

            case 5:
                checkBalance();
                break;

            case 6:
                cout << "\nThank you for using Bank Management System!\n";
                break;

            default:
                cout << "\nInvalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
