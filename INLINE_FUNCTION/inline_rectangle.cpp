#include <iostream>
using namespace std;

inline int area(int length, int width)
{
    return length * width;
}

int main()
{
    int length = 12;
    int width = 6;

    cout << "Area of Rectangle: " << area(length, width);

    return 0;
}
