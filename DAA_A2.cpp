#include <iostream>
using namespace std;

// Merge two halves and move zeroes to the end
void merge(int arr[], int s, int mid, int e) {
    int temp[e - s + 1]; // Temporary array
    int i = s, j = mid + 1, k = 0;

    // Copy non-zero elements from both halves
    while (i <= mid) {
        if (arr[i] != 0) {
            temp[k++] = arr[i];
        }
        i++;
    }
    while (j <= e) {
        if (arr[j] != 0) {
            temp[k++] = arr[j];
        }
        j++;
    }

    // Fill the remaining positions with zeroes
    while (k < (e - s + 1)) {
        temp[k++] = 0;
    }

    // Copy the merged elements back to the original array
    for (i = s; i <= e; i++) {
        arr[i] = temp[i - s];
    }
}

// Divide the array into halves and recursively process them
void moveZeroesToEnd(int arr[], int s, int e) {
    if (s >= e) return; // Base case: single element or invalid range

    int mid = (s + e) / 2;

    // Recursively divide the array
    moveZeroesToEnd(arr, s, mid);
    moveZeroesToEnd(arr, mid + 1, e);

    // Merge the two halves
    merge(arr, s, mid, e);
}

int main() {
    int arr[] = {1, 2, 0, 4, 3, 0, 5, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    moveZeroesToEnd(arr, 0, n - 1);

    // Print the result
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
