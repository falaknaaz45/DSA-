#include <iostream>
using namespace std;

// Function to delete from the start of the array
void deleteAtStart(int arr[], int& size) {
    if (size <= 0) {
        cout << "Array is empty, can't delete from start." << endl;
        return;
    }
    // Shift elements to the left
    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;  // Reduce the size
}

// Function to delete from a specific index (for middle deletion)
void deleteAtMiddle(int arr[], int& size, int index) {
    if (size <= 0) {
        cout << "Array is empty, can't delete from middle." << endl;
        return;
    }
    if (index < 0 || index >= size) {
        cout << "Invalid index." << endl;
        return;
    }
    // Shift elements to the left
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;  // Reduce the size
}

// Function to delete from the end of the array
void deleteAtEnd(int& size) {
    if (size <= 0) {
        cout << "Array is empty, can't delete from end." << endl;
        return;
    }
    size--;  // Reduce the size
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int capacity = 10;  // Maximum capacity of the array
    int arr[capacity] = {1, 2, 3, 4, 5};  // Initial array
    int size = 5;       // Current size of the array

    cout << "Original array: ";
    printArray(arr, size);

    // Deleting from the start
    deleteAtStart(arr, size);
    cout << "After deleting from the start: ";
    printArray(arr, size);

    // Deleting from the middle (index 2)
    deleteAtMiddle(arr, size, 2);
    cout << "After deleting from the middle: ";
    printArray(arr, size);

    // Deleting from the end
    deleteAtEnd(size);
    cout << "After deleting from the end: ";
    printArray(arr, size);

    return 0;
}

