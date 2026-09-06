#include <iostream>
using namespace std;

class Bank {
private:
    int balance;

public:
    void setBalance(int b) {
        balance = b;
    }

    void showBalance() {
        cout << "Balance = " << balance;
    }
};

int main() {
    Bank b;

    b.setBalance(5000);
    b.showBalance();

    return 0;
}
