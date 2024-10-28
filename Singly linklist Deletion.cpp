#include <iostream>
using namespace std;

// Node class for singly linked list
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

// LinkedList class with deletion functions
class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    // Function to insert at the end (for easier testing)
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

    // Function to delete from the start
    void deleteAtStart() {
        if (head == NULL) {
            cout << "List is empty, can't delete from start." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Function to delete at a specific index (for middle deletion)
    void deleteAtIndex(int index) {
        if (head == NULL) {
            cout << "List is empty, can't delete at index " << index << "." << endl;
            return;
        }

        if (index == 0) {
            deleteAtStart();
            return;
        }

        Node* current = head;
        int count = 0;

        // Traverse to the node before the one to be deleted
        while (current != NULL && count < index - 1) {
            current = current->next;
            count++;
        }

        // Check if the index is out of bounds
        if (current == NULL || current->next == NULL) {
            cout << "Index out of bounds." << endl;
            return;
        }

        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }

    // Function to delete from the end
    void deleteAtEnd() {
        if (head == NULL) {
            cout << "List is empty, can't delete from end." << endl;
            return;
        }

        if (head->next == NULL) {  // Only one element
            delete head;
            head = NULL;
            return;
        }

        Node* current = head;
        while (current->next->next != NULL) {  // Traverse to second last node
            current = current->next;
        }

        delete current->next;
        current->next = NULL;
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

    // Insert some elements
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);

    cout << "Original list: ";
    list.display();

    // Delete from the start
    list.deleteAtStart();
    cout << "After deleting from start: ";
    list.display();

    // Delete from the end
    list.deleteAtEnd();
    cout << "After deleting from end: ";
    list.display();

    // Delete from the middle (at index 1)
    list.deleteAtIndex(1);
    cout << "After deleting at index 1: ";
    list.display();

    return 0;
}

