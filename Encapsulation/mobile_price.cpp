#include <iostream>
using namespace std;

class Mobile {
private:
    int price;

public:
    void setPrice(int p) {
        price = p;
    }

    void showPrice() {
        cout << "Mobile Price = " << price;
    }
};

int main() {
    Mobile m;

    m.setPrice(25000);
    m.showPrice();

    return 0;
}
