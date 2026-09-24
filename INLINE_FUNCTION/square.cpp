#include <iostream>
using namespace std;

inline int square(int n)
{
    return n * n;
}

int main()
{
    int num = 5;

    cout << "Square = " << square(num);

    return 0;
}
