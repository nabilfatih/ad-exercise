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

void MinHeap(int a[], int low, int high, int root)
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
        MinHeap(a, low, high, smallest);
    }
}

void MaxHeap(int a[], int low, int high, int root)
{
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    // If left child is larger than root
    if (left <= high && a[left] > a[largest])
    {
        largest = left;
    }

    // If right child is larger than root
    if (right <= high && a[right] > a[largest])
    {
        largest = right;
    }

    // If largest is not root
    // when is
    if (largest != root)
    {
        swap(a[root], a[largest]);
        // Why need recursive call here? Because we need to make sure the subtree is also a max heap
        MaxHeap(a, low, high, largest);
    }
}

void BuildHeap(int a[], int low, int high)
{
    // Why (high - 1) / 2? Because the last element is at index high, so the parent of the last element is at index (high - 1) / 2
    for (int i = (high - 1) / 2; i >= low; i--)
    {
        MaxHeap(a, low, high, i);
    }
}

void HeapSort(int a[], int low, int high)
{
    BuildHeap(a, low, high);
    for (int i = high; i >= low; i--)
    {
        swap(a[low], a[i]);          // swap the root with the last element
        MaxHeap(a, low, i - 1, low); // make sure the heap is still a max heap
    }
}

void InsertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            // shift the elements to the right
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void BubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void SelectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        swap(a[i], a[min]);
    }
}

int main()
{
    int a[] = {-5, 13, -32, 7, -3, 17, 23, 12, -35, 19};
    QuickSort(a, 0, 9);
    cout << "Quick Sort: ";
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;

    int b[] = {-5, 13, -32, 7, -3, 17, 23, 12, -35, 19};
    MergeSort(b, 0, 9);
    cout << "Merge Sort: ";
    for (int i = 0; i < 10; i++)
    {
        cout << b[i] << " ";
    }

    cout << endl;

    int c[] = {-5, 13, -32, 7, -3, 17, 23, 12, -35, 19};
    HeapSort(c, 0, 9);
    cout << "Heap Sort: ";
    for (int i = 0; i < 10; i++)
    {
        cout << c[i] << " ";
    }

    cout << endl;

    int d[] = {-5, 13, -32, 7, -3, 17, 23, 12, -35, 19};
    InsertionSort(d, 10);
    cout << "Insertion Sort: ";
    for (int i = 0; i < 10; i++)
    {
        cout << d[i] << " ";
    }

    cout << endl;

    int e[] = {-5, 13, -32, 7, -3, 17, 23, 12, -35, 19};
    BubbleSort(e, 10);
    cout << "Bubble Sort: ";
    for (int i = 0; i < 10; i++)
    {
        cout << e[i] << " ";
    }

    cout << endl;

    int f[] = {-5, 13, -32, 7, -3, 17, 23, 12, -35, 19};
    SelectionSort(f, 10);
    cout << "Selection Sort: ";
    for (int i = 0; i < 10; i++)
    {
        cout << f[i] << " ";
    }

    return 0;
}