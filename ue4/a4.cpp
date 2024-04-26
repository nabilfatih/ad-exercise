#include <iostream>
#include <vector>

void RecursiveInsertionSort(std::vector<double> &a, int n)
{
    if (n <= 1)
        return;

    RecursiveInsertionSort(a, n - 1);

    double last = a[n - 1];
    int j = n - 2;

    while (j >= 0 && a[j] > last)
    {
        a[j + 1] = a[j];
        j--;
    }

    a[j + 1] = last;
}

void Merge(int a[], int low, int high, int mid)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = a[low + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = a[mid + 1 + j];
    }

    int i = 0, j = 0, k = low;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

int main()
{
    std::vector<double> a = {3, 7, 1, 9, 2, 2.4};
    RecursiveInsertionSort(a, a.size());

    for (int i = 0; i < a.size(); i++)
    {
        std::cout << a[i] << " ";
    }

    return 0;
}