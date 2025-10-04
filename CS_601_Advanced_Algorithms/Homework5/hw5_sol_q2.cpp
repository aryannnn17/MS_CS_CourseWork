// Aryan Bhagat - sl5310
// Moksha Shah - bp4199
// CS_601 - HW5_Q2 Solution

// This program merges two binary min-heaps into a single min-heap.
// The heaps are represented as arrays, and the program uses a bottom-up
// approach to build the min-heap after merging.
// The time complexity is O(n + m) and the auxiliary space is O(n + m).

#include <bits/stdc++.h>
using namespace std;

// Utility function to swap two integers
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// 'heapify' ensures the min-heap property at subtree rooted at index 'index'.
// 'size' is the size of the heap/array.
void heapify(int *arr, int size, int index)
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // If the left child is smaller than the current smallest
    if (left < size && arr[left] < arr[smallest])
        smallest = left;

    // If the right child is smaller than the current smallest
    if (right < size && arr[right] < arr[smallest])
        smallest = right;

    // If 'smallest' has changed, we need to swap and heapify further down
    if (smallest != index)
    {
        swap(arr[index], arr[smallest]);
        heapify(arr, size, smallest);
    }
}

// 'buildMinHeap' builds a min-heap from an array.
void buildMinHeap(int *arr, int size)
{
    for (int i = size / 2 - 1; i >= 0; --i)
        heapify(arr, size, i);
}

// 'Magic' merges two min-heaps T1 and T2 into a new min-heap T3.
// It takes two arrays T1 and T2 of sizes n and m respectively, and returns
// a new array T3 of size (n + m) which is a min-heap.
int *Magic(int *T1, int n, int *T2, int m)
{
    int total = n + m;
    // Create a new array T3 to hold the merged min-heap
    int *T3 = new int[total];

    // Copy elements from T1 and T2 into T3
    for (int i = 0; i < n; ++i)
        T3[i] = T1[i];

    // Append elements from T2 into T3
    for (int i = 0; i < m; ++i)
        T3[n + i] = T2[i];

    // Build the min-heap from the merged array T3    
    buildMinHeap(T3, total);
    return T3;
}


// The main function reads two min-heaps from input, merges them using
// the 'Magic' function, and prints the resulting min-heap.
int main()
{
    int n, m;
    cin >> n;

    int *T1 = new int[n];
    // Read the first min-heap
    for (int i = 0; i < n; ++i)
        cin >> T1[i];

    cin >> m;
    int *T2 = new int[m];
    // Read the second min-heap
    for (int i = 0; i < m; ++i)
        cin >> T2[i];

    // Merge T1 and T2 into T3        
    int *T3 = Magic(T1, n, T2, m);
    for (int i = 0; i < n + m; ++i)
        cout << T3[i] << " ";

    // Clean up dynamically allocated memory
    delete[] T1;
    delete[] T2;
    delete[] T3;
    return 0;
}
