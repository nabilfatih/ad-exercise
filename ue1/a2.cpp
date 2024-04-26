#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sieveOfEratosthenes(int n)
{
    vector<bool> prime(n + 1, true);
    vector<int> primeNumbers;

    for (int p = 2; p <= n; p++)
    {
        if (prime[p])
        {
            primeNumbers.push_back(p);
            for (int i = p * p; i <= n; i += p)
            {
                prime[i] = false;
            }
        }
    }
    return primeNumbers;
}

int main()
{
    int n = 100;
    vector<int> primeNumbers = sieveOfEratosthenes(n);
    for (int i = 0; i < primeNumbers.size(); i++)
    {
        cout << primeNumbers[i] << " ";
    }
    return 0;
}