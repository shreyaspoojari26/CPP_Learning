#include <iostream>
using namespace std;

inline int cube(int n)
{
    return n * n * n;
}

int main()
{
    int num = 4;

    cout << "Cube = " << cube(num);

    return 0;
}
