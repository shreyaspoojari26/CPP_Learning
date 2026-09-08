#include <iostream>
using namespace std;

class ATM {
private:
    int balance;
    int pin;

public:

    // Constructor
    ATM(int p, int b) {
        pin = p;
        balance = b;
    }

    // Check PIN
    bool checkPin(int enteredPin) {
        return enteredPin == pin;
    }

    // Check Balance
    void checkBalance() {
        cout << "Current Balance: ₹" << balance << endl;
    }

    // Deposit
    void deposit(int amount) {
        balance = balance + amount;
        cout << "Amount deposited successfully!" << endl;
    }

    // Withdraw
    void withdraw(int amount) {
        if (amount <= balance) {
            balance = balance - amount;
            cout << "Please collect your cash." << endl;
        }
        else {
            cout << "Insufficient balance!" << endl;
        }
    }
};

int main() {

    ATM account(1234, 10000);

    int enteredPin;
    int choice;
    int amount;

    cout << "===== ATM =====" << endl;

    cout << "Enter PIN: ";
    cin >> enteredPin;

    if (!account.checkPin(enteredPin)) {
        cout << "Incorrect PIN!";
        return 0;
    }

    do {
        cout << "\n===== ATM MENU =====" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            account.checkBalance();
            break;

        case 2:
            cout << "Enter amount: ";
            cin >> amount;
            account.deposit(amount);
            break;

        case 3:
            cout << "Enter amount: ";
            cin >> amount;
            account.withdraw(amount);
            break;

        case 4:
            cout << "Thank you for using ATM!";
            break;

        default:
            cout << "Invalid choice!";
        }

    } while (choice != 4);

    return 0;
}
