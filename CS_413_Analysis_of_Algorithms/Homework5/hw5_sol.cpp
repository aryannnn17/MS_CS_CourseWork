// Submitted by : Aryan Jigneshbhai Bhagat - NetID: sl5310, & Moksha Kumudbhai Shah - NetID: bp4199

// CS_411 - Assignment 5 - C++ program to count the number of odd elements using divide-and-conquer

#include <bits/stdc++.h>
using namespace std;

// Function to count the number of odd elements in an array using divide-and-conquer
int countOdd(int arr[], int left, int right) {
    // Base case: if the array has one element
    if (left == right) 
        return (arr[left] % 2 != 0) ? 1 : 0;
    
    int mid = left + (right - left) / 2;
    // Recursively count odd elements in the left and right halves
    int leftCount = countOdd(arr, left, mid);
    int rightCount = countOdd(arr, mid + 1, right);

    // return the total count of odd elements
    return leftCount + rightCount;
}

int main() {
    // Test cases

    // Test-1: {1, 12, 34, 5, 7}
    // Expected output: 5 (1, 5, 7 are odd)
    int test1[] = {1, 12, 34, 5, 7};
    int n1 = sizeof(test1) / sizeof(test1[0]);

    // Test-2: {7}
    // Expected output: 1 (7 is odd)
    int test2[] = {7};
    int n2 = sizeof(test2) / sizeof(test2[0]);

    // Count the number of odd elements in the array
    int oddCount = countOdd(test1, 0, n1 - 1);
    cout << "#Test-1: Number of odd elements: " << oddCount << endl;

    oddCount = countOdd(test2, 0, n2 - 1);
    cout << "#Test-2: Number of odd elements: " << oddCount << endl;

    return 0;
}
