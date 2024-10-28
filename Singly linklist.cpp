#include <iostream>
using namespace std;

// Node class for singly linked list
class Node {
public:
    int data;
    Node* next;

    // Constructor without initializer list
    Node(int value) {
        data = value;
        next = NULL;
    }
};

// LinkedList class with insertion functions
class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    // Function to insert at the start
    void insertAtStart(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Function to insert at a specific index (for middle insertion)
    void insertAtIndex(int value, int index) {
        if (index == 0) {
            insertAtStart(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* current = head;
        int count = 0;

        // Traverse to the position before the desired index
        while (current != NULL && count < index - 1) {
            current = current->next;
            count++;
        }

        // Check if index is out of bounds
        if (current == NULL) {
            cout << "Index out of bounds." << endl;
            delete newNode;
            return;
        }

        // Insert newNode at the specified index
        newNode->next = current->next;
        current->next = newNode;
    }

    // Function to insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Function to display the linked list
    void display() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;

    // Inserting at the start
    list.insertAtStart(10);
    cout << "After inserting 10 at the start: ";
    list.display();

    // Inserting at the end
    list.insertAtEnd(20);
    cout << "After inserting 20 at the end: ";
    list.display();

    // Inserting in the middle (at index 1)
    list.insertAtIndex(15, 1);
    cout << "After inserting 15 at index 1: ";
    list.display();

    // Inserting at the start again
    list.insertAtStart(5);
    cout << "After inserting 5 at the start: ";
    list.display();

    // Inserting at the end again
    list.insertAtEnd(25);
    cout << "After inserting 25 at the end: ";
    list.display();

    // Inserting at index 3
    list.insertAtIndex(12, 3);
    cout << "After inserting 12 at index 3: ";
    list.display();

    return 0;
}

