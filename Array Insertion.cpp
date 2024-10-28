#include <iostream>
using namespace std;

// Function to insert at the start of the array
void insertAtStart(int arr[], int& size, int value, int capacity) {
    if (size >= capacity) {
        cout << "Array is full, can't insert at start." << endl;
        return;
    }
    // Shift elements to the right
    for (int i = size; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = value;
    size++;
}

// Function to insert at a specific index (for middle insertion)
void insertAtMiddle(int arr[], int& size, int value, int index, int capacity) {
    if (size >= capacity) {
        cout << "Array is full, can't insert in the middle." << endl;
        return;
    }
    if (index < 0 || index > size) {
        cout << "Invalid index." << endl;
        return;
    }
    // Shift elements to the right
    for (int i = size; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    size++;
}

// Function to insert at the end of the array
void insertAtEnd(int arr[], int& size, int value, int capacity) {
    if (size >= capacity) {
        cout << "Array is full, can't insert at end." << endl;
        return;
    }
    arr[size] = value;
    size++;
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

    // Inserting at the start
    insertAtStart(arr, size, 10, capacity);
    cout << "After inserting 10 at the start: ";
    printArray(arr, size);

    // Inserting in the middle (at index 3)
    insertAtMiddle(arr, size, 20, 3, capacity);
    cout << "After inserting 20 in the middle: ";
    printArray(arr, size);

    // Inserting at the end
    insertAtEnd(arr, size, 30, capacity);
    cout << "After inserting 30 at the end: ";
    printArray(arr, size);

    return 0;
}

