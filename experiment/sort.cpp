#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void swap(int &a, int &b)
{
    int h = a;
    a = b;
    b = h;
}

void PreparePartition(int a[], int low, int high, int &part)
{
    int pivot = a[(low + high) / 2]; // pivot is the middle element (can be any element
    int i = low - 1;
    int j = high + 1;

    while (i < j)
    {
        do
        {
            i++;
        } while (a[i] < pivot);
        do
        {
            j--;
        } while (a[j] > pivot);
        if (i < j)
        {
            swap(a[i], a[j]);
        }
    }
    swap(a[low], a[j]);
    part = j;
}

void QuickSort(int a[], int low, int high)
{
    int part;
    if (low < high)
    {
        PreparePartition(a, low, high, part);
        QuickSort(a, low, part);
        QuickSort(a, part + 1, high);
    }
}

void Merge(int a[], int low, int high, int mid)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int *L = new int[n1];
    int *R = new int[n2];

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

    delete[] L;
    delete[] R;
}

void MergeSort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        MergeSort(a, low, mid);
        MergeSort(a, mid + 1, high);
        Merge(a, low, high, mid);
    }
}

void MinHeapify(int a[], int low, int high, int root)
{
    int smallest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left <= high && a[left] < a[smallest])
    {
        smallest = left;
    }

    if (right <= high && a[right] < a[smallest])
    {
        smallest = right;
    }

    if (smallest != root)
    {
        swap(a[root], a[smallest]);
        MinHeapify(a, low, high, smallest);
    }
}

void MaxHeapify(int a[], int low, int high, int root)
{
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left <= high && a[left] > a[largest])
    {
        largest = left;
    }

    if (right <= high && a[right] > a[largest])
    {
        largest = right;
    }

    if (largest != root)
    {
        swap(a[root], a[largest]);
        MaxHeapify(a, low, high, largest);
    }
}

void BuildHeap(int a[], int low, int high)
{
    for (int i = (high - 1) / 2; i >= low; i--)
    {
        cout << i << endl;
        MaxHeapify(a, low, high, i);
    }
}

void HeapSort(int a[], int low, int high)
{
    BuildHeap(a, low, high);
    for (int i = high; i >= low; i--)
    {
        swap(a[low], a[i]);
        MaxHeapify(a, low, i - 1, low);
    }
}

int main()
{
    int a[] = {5, 5, 3, 8, 4, 2, 7, 1, 10, 12, 14, 16, 0, -1};
    QuickSort(a, 0, 13);
    cout << "Quick Sort: ";
    for (int i = 0; i < 14; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;

    int b[] = {5, 5, 3, 8, 4, 2, 7, 1, 10, 12, 14, 16, 0, -1};
    MergeSort(b, 0, 13);
    cout << "Merge Sort: ";
    for (int i = 0; i < 14; i++)
    {
        cout << b[i] << " ";
    }

    cout << endl;

    int c[] = {5, 5, 3, 8, 4, 2, 7, 1, 10, 12, 14, 16, 0, -1};
    HeapSort(c, 0, 13);
    cout << "Heap Sort: ";
    for (int i = 0; i < 14; i++)
    {
        cout << c[i] << " ";
    }

    return 0;
}