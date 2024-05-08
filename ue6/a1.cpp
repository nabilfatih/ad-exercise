#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

// Function to perform Count Sort
void countSort(std::vector<int> &arr, int k)
{
    std::vector<int> count(k + 1, 0); // Count array to store the frequency of each number

    // Count each number's frequency
    for (int num : arr)
    {
        count[num]++;
    }

    // Rebuild the original array using the count array
    int index = 0;
    for (int i = 0; i <= k; i++)
    {
        while (count[i] > 0)
        {
            arr[index++] = i;
            count[i]--;
        }
    }
}

// Function to perform Heap Sort
void heapify(std::vector<int> &arr, int n, int i)
{
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // left = 2*i +1
    int right = 2 * i + 2; // right = 2*i +2

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than root
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i)
    {
        std::swap(arr[i], arr[largest]);
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void heapSort(std::vector<int> &arr)
{
    int n = arr.size();
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--)
    {
        // Move current root to end
        std::swap(arr[0], arr[i]);
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Function to perform Map Sort (Assuming it's similar to Count Sort for demonstration)
void mapSort(std::vector<int> &arr, int k)
{
    countSort(arr, k); // Using count sort as map sort for demonstration
}

int main()
{
    std::vector<int> arr = {10000, 1001, 2005, 3000, 4500, 6750, 9000}; // Example array
    int k = 10000;                                                      // Maximum value in the range

    auto start = std::chrono::high_resolution_clock::now();
    countSort(arr, k);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Count Sort took " << duration.count() << " microseconds" << std::endl;

    // Similarly, you can time Heap Sort and Map Sort
    // Heap Sort
    std::vector<int> arr2 = {10000, 1001, 2005, 3000, 4500, 6750, 9000}; // Example array
    start = std::chrono::high_resolution_clock::now();
    heapSort(arr2);
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Heap Sort took " << duration.count() << " microseconds" << std::endl;

    // Map Sort
    std::vector<int> arr3 = {10000, 1001, 2005, 3000, 4500, 6750, 9000}; // Example array
    start = std::chrono::high_resolution_clock::now();
    mapSort(arr3, k);
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Map Sort took " << duration.count() << " microseconds" << std::endl;

    return 0;
}