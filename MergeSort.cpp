#include <iostream> // For cout and endl
#include <cstdlib> // For srand and rand
#include <ctime> // Assist with srand and rand

using std::cout;
using std::endl;

// Function to merge two sorted subarrays
template <typename T>
void merge(T arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of the first subarray
    int n2 = right - mid;    // Size of the second subarray

    // Create temporary arrays
    T* leftArr = new T[n1];
    T* rightArr = new T[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; ++i)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        rightArr[i] = arr[mid + 1 + i];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            ++i;
        } else {
            arr[k] = rightArr[j];
            ++j;
        }
        ++k;
    }

    // If one subarray is shorter than the other then previous loop will stop and the following loops will finish any remaining indexes for the larger array
    // Copy any remaining elements of leftArr
    while (i < n1) {
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }

    // Copy any remaining elements of rightArr
    while (j < n2) {
        arr[k] = rightArr[j];
        ++j;
        ++k;
    }

    // Clean up temporary arrays
    delete[] leftArr;
    delete[] rightArr;
}

// Function to implement Merge Sort
template <typename T>
void mergeSort(T arr[], int left, int right) {
    if (left < right) { // Ensures the array being processed contains at least two elements
        int mid = left + (right - left) / 2; // Finds the middle index of passed array

        // Recursively sort the two halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to print an array
template <typename T>
void printArray(const T arr[], int size) {
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    // Test case 1: Array with all elements in ascending order
    int asc[] = {1, 2, 3, 4, 5};
    int sizeAsc = sizeof(asc) / sizeof(asc[0]);
    cout << "Test Case 1 - Ascending - Before: ";
    printArray(asc, sizeAsc);
    mergeSort(asc, 0, sizeAsc - 1);
    cout << "Test Case 1 - After: ";
    printArray(asc, sizeAsc);

    // Test case 2: Array with all elements in descending order
    int desc[] = {5, 4, 3, 2, 1};
    int sizeDesc = sizeof(desc) / sizeof(desc[0]);
    cout << "Test Case 2 - Descending - Before: ";
    printArray(desc, sizeDesc);
    mergeSort(desc, 0, sizeDesc - 1);
    cout << "Test Case 2 - After: ";
    printArray(desc, sizeDesc);

    // Test case 3: Array with duplicate elements
    int duplicates[] = {4, 1, 3, 3, 2};
    int sizeDuplicates = sizeof(duplicates) / sizeof(duplicates[0]);
    cout << "Test Case 3 - Duplicates - Before: ";
    printArray(duplicates, sizeDuplicates);
    mergeSort(duplicates, 0, sizeDuplicates - 1);
    cout << "Test Case 3 - After: ";
    printArray(duplicates, sizeDuplicates);

    // Test case 4: Array with an odd number of elements
    int odd[] = {9, 7, 5, 3, 1};
    int sizeOdd = sizeof(odd) / sizeof(odd[0]);
    cout << "Test Case 4 - Before: ";
    printArray(odd, sizeOdd);
    mergeSort(odd, 0, sizeOdd - 1);
    cout << "Test Case 4 - After: ";
    printArray(odd, sizeOdd);

    // Test case 5: Randomized array
    const int randomSize = 20;
    int randomArr[randomSize];
    std::srand(std::time(0));
    for (int i = 0; i < randomSize; ++i)
        randomArr[i] = std::rand() % 100;

    cout << "Test Case 5 - Randomized Array - Before: ";
    printArray(randomArr, randomSize);
    mergeSort(randomArr, 0, randomSize - 1);
    cout << "Test Case 5 - Randomized Array - After: ";
    printArray(randomArr, randomSize);

    return 0;
}