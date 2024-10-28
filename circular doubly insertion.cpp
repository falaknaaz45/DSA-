#include <iostream>
using namespace std;

// Node class for circular doubly linked list
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

// CircularDoublyLinkedList class with insertion functions
class CircularDoublyLinkedList {
public:
    Node* head;

    CircularDoublyLinkedList() {
        head = NULL;
    }

    // Function to insert at the start
    void insertAtStart(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
        } else {
            Node* tail = head->prev; // Tail is the previous node of head
            newNode->next = head;     // New node points to head
            newNode->prev = tail;     // New node points to tail
            tail->next = newNode;      // Tail's next points to new node
            head->prev = newNode;      // Head's previous points to new node
            head = newNode;            // Update head to new node
        }
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
        while (count < index - 1 && current != NULL) {
            current = current->next;
            count++;
            if (current == head) {
                break; // Stop if we've looped back to head
            }
        }

        // If current is head, it means index is out of bounds
        if (current == NULL || (current == head && count < index - 1)) {
            cout << "Index out of bounds." << endl;
            delete newNode;
            return;
        }

        // Insert the new node
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode; // Update next node's previous pointer
        current->next = newNode;        // Link previous node to new node
    }

    // Function to insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
        } else {
            Node* tail = head->prev; // Tail is the previous node of head
            tail->next = newNode;     // Link tail to new node
            newNode->prev = tail;     // New node points to tail
            newNode->next = head;     // New node points to head
            head->prev = newNode;     // Head's previous points to new node
        }
    }

    // Function to display the circular doubly linked list
    void display() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Node* current = head;
        do {
            cout << current->data << " <-> ";
            current = current->next;
        } while (current != head);
        cout << "(back to head: " << head->data << ")" << endl;
    }
};

int main() {
    CircularDoublyLinkedList list;

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

