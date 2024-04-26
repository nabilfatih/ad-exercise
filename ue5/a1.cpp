#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    int h = a;
    a = b;
    b = h;
}

void Merge(int a[], int low, int high, int mid)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int *L = new int[n1];
    int *R = new int[n2];

    // copy data to temp arrays
    for (int i = 0; i < n1; i++)
    {
        L[i] = a[low + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = a[mid + 1 + j];
    }

    // merge the temp arrays back into a[]
    int i = 0;
    int j = 0;
    int k = low;

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

void MaxHeap(int a[], int low, int high, int root)
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
        MaxHeap(a, low, high, largest);
    }
}

void BuildHeap(int a[], int low, int high)
{
    for (int i = (high - 1) / 2; i >= 0; i--)
    {
        MaxHeap(a, low, high, i);
    }
}

void HeapSort(int a[], int low, int high)
{
    BuildHeap(a, low, high);

    for (int i = high; i >= low; i--)
    {
        swap(a[low], a[i]);
        MaxHeap(a, low, i - 1, low);
    }
}

int main()
{
    int a[] = {-5, 13, -32, 7, -3, 17, 23, 12, -35, 19};
    MergeSort(a, 0, 9);
    cout << "Merge Sort: ";
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;

    int b[] = {-5, 13, -32, 7, -3, 17, 23, 12, -35, 19};
    HeapSort(b, 0, 9);
    cout << "Heap Sort: ";
    for (int i = 0; i < 10; i++)
    {
        cout << b[i] << " ";
    }

    return 0;
}