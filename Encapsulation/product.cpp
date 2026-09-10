#include <iostream>
using namespace std;

class Product
{
private:
    int price;

public:
    void setPrice(int p)
    {
        price = p;
    }

    void showPrice()
    {
        cout << "Product Price: " << price << endl;
    }
};

int main()
{
    Product p1;

    p1.setPrice(500);
    p1.showPrice();

    return 0;
}
