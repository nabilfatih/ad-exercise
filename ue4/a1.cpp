#include <iostream>
using namespace std;

void InsertionSort(int a[], int n)
{
    int i, j, key;
    // über das Minimum einsortieren
    for (i = n - 2; i >= 0; --i)
    {
        key = a[i];
        j = i + 1;
        while (j < n && key > a[j])
        {
            a[j - 1] = a[j];
            j++;
        }
        a[j - 1] = key;
    }
}

void BubbleSort(int a[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        // das Maximum nach hinten wandern, statt das Minimum nach vorne wandern zu lassen.
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int h = a[j];
                a[j] = a[j + 1];
                a[j + 1] = h;
            }
        }
    }
}

void SelectionSort(int a[], int n)
{
    // Setzen Sie bei SelectionSort anstelle des Minimums jeweils das Maximum an die richtige Stelle
    int i, j, max;
    for (i = n - 1; i >= 0; i--)
    {
        max = i;
        for (j = i - 1; j >= 0; j--)
        {
            if (a[j] > a[max])
            {
                max = j;
            }
        }
        int h = a[i];
        a[i] = a[max];
        a[max] = h;
    }
}

void Swap(int &a, int &b)
{
    int h = a;
    a = b;
    b = h;
}

void PreparePartition(int a[], int f, int l, int &p)
{
    // random pivot
    int pivot = a[f + rand() % (l - f + 1)];
    cout << "pivot: " << pivot << endl;
    p = f - 1;
    for (int i = f; i <= l; i++)
    {
        if (a[i] <= pivot)
        {
            p++;
            Swap(a[p], a[i]);
        }
    }
    // pivot an die richtige Stelle
    Swap(a[p], a[f]);
}

void QuickSort(int a[], int f, int l)
{
    int part;
    if (f < l)
    {
        PreparePartition(a, f, l, part);
        QuickSort(a, f, part - 1);
        QuickSort(a, part + 1, l);
    }
}

int main()
{
    // InsertionSort
    int a[] = {5, 2, 4, 6, 1, 3};
    InsertionSort(a, 6);
    cout << "InsertionSort" << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    // BubbleSort
    int b[] = {5, 2, 4, 6, 1, 3};
    BubbleSort(b, 6);
    cout << "BubbleSort" << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;

    // SelectionSort
    int c[] = {5, 2, 4, 6, 1, 3};
    SelectionSort(c, 6);
    cout << "SelectionSort" << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;

    // QuickSort
    // Wählen Sie bei QuickSort als Pivot-Element ein zufälliges Element.
    int d[] = {5, 2, 4, 6, 1, 3};
    QuickSort(d, 0, 5);
    cout << "QuickSort" << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;
    return 0;
}