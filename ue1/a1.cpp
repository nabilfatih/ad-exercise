#include <iostream>

using namespace std;

int gcdIterative(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int gcdRecursive(int a, int b)
{
    if (b == 0)
        return a;
    return gcdRecursive(b, a % b);
}

int lcm(int a, int b)
{
    return a * b / gcdIterative(a, b);
}

int main()
{
    int a = 30, b = 50;
    cout << "GCD of " << a << " and " << b << " is " << gcdIterative(a, b) << endl;
    cout << "GCD of " << a << " and " << b << " is " << gcdRecursive(a, b) << endl;
    cout << "LCM of " << a << " and " << b << " is " << lcm(a, b) << endl;
    return 0;
}
