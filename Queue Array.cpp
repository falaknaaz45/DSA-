#include <iostream>
using namespace std;

#define MAX 3  // Maximum number of plates that can be stacked

class PlateStack {
    int top;
    int plates[MAX];

public:
    PlateStack() { top = -1; }  // Constructor initializes the stack

    // Function to add a plate to the stack
    void push(int plate) {
        if (top >= MAX - 1) {
            cout << "Stack is full, cannot add more plates.\n";
        } else {
            plates[++top] = plate;
            cout << "Added plate " << plate << " to the stack.\n";
        }
    }

    // Function to remove the top plate from the stack
    void pop() {
        if (top < 0) {
            cout << "Stack is empty, no plates to remove.\n";
        } else {
            cout << "Removed plate " << plates[top--] << " from the stack.\n";
        }
    }

    // Function to check the top plate on the stack
    void peek() {
        if (top < 0) {
            cout << "Stack is empty, no plates on top.\n";
        } else {
            cout << "The top plate is " << plates[top] << ".\n";
        }
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return (top < 0);
    }

    // Function to check if the stack is full
    bool isFull() {
        return (top >= MAX - 1);
    }
};

int main() {
    PlateStack stack;
    int choice, plate;

    do {
        cout << "\n1. Add a plate\n2. Remove the top plate\n3. Check the top plate\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (!stack.isFull()) {
                    cout << "Enter the plate number to add: ";
                    cin >> plate;
                    stack.push(plate);
                } else {
                    cout << "The stack is full, you can't add more plates.\n";
                }
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.peek();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

