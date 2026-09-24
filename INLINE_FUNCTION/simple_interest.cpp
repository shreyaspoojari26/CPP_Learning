#include <iostream>
using namespace std;

inline float simpleInterest(float p, float r, float t)
{
    return (p * r * t) / 100;
}

int main()
{
    float p = 10000;
    float r = 5;
    float t = 2;

    cout << "Simple Interest = " << simpleInterest(p, r, t);

    return 0;
}
