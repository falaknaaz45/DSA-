#include <iostream>
using namespace std;

// Node class for doubly linked list
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = NULL;
        next = NULL;
    }
};

// DoublyLinkedList class with insertion functions
class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() {
        head = NULL;
    }

    // Function to insert at the start
    void insertAtStart(int value) {
        Node* newNode = new Node(value);
        if (head != NULL) {
            head->prev = newNode;
            newNode->next = head;
        }
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

        // Insert the new node at the specified index
        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != NULL) {
            current->next->prev = newNode;
        }
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
        newNode->prev = current;
    }

    // Function to display the list from the start
    void display() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " <-> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyLinkedList list;

    // Insert at the start
    list.insertAtStart(10);
    cout << "After inserting 10 at the start: ";
    list.display();

    // Insert at the end
    list.insertAtEnd(30);
    cout << "After inserting 30 at the end: ";
    list.display();

    // Insert at the middle (index 1)
    list.insertAtIndex(20, 1);
    cout << "After inserting 20 at index 1: ";
    list.display();

    // Insert at the start again
    list.insertAtStart(5);
    cout << "After inserting 5 at the start: ";
    list.display();

    // Insert at the end again
    list.insertAtEnd(40);
    cout << "After inserting 40 at the end: ";
    list.display();

    // Insert at index 3
    list.insertAtIndex(25, 3);
    cout << "After inserting 25 at index 3: ";
    list.display();

    return 0;
}

