#include <iostream>
#include <vector>
#include <algorithm>

bool findPairWithSum(std::vector<double> &a, int s)
{
    // Sort the array in non-decreasing order
    std::sort(a.begin(), a.end());

    int left = 0;
    int right = a.size() - 1;

    while (left < right)
    {
        double sum = a[left] + a[right];
        if (sum == s)
        {
            return true; // Found a pair with sum equal to s
        }
        else if (sum < s)
        {
            left++; // Move left pointer to the right
        }
        else
        {
            right--; // Move right pointer to the left
        }
    }

    return false; // No pair found
}

bool findPairWithSumWithoutSorting(std::vector<double> &a, int s)
{
    // just use for loop without additional hash or any other data structure
    // O(n^2) time complexity, true if pair found, false if not
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = i + 1; j < a.size(); j++)
        {
            if (a[i] + a[j] == s)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    std::vector<double> a = {3, 7, 1, 9, 2, 2.4};
    int s = 10;

    std::cout << "With sorting" << std::endl;
    if (findPairWithSum(a, s))
    {
        std::cout << "True, there exist two elements with sum " << s << std::endl;
    }
    else
    {
        std::cout << "False, no such pair exists with sum " << s << std::endl;
    }

    std::cout << "Without sorting" << std::endl;
    if (findPairWithSumWithoutSorting(a, s))
    {
        std::cout << "True, there exist two elements with sum " << s << std::endl;
    }
    else
    {
        std::cout << "False, no such pair exists with sum " << s << std::endl;
    }

    return 0;
}