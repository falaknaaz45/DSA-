#include <iostream>
using namespace std;

// Node class for circular singly linked list
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

// CircularSinglyLinkedList class with deletion functions
class CircularSinglyLinkedList {
public:
    Node* head;

    CircularSinglyLinkedList() {
        head = NULL;
    }

    // Function to insert at the end (for easier testing)
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            newNode->next = head; // Point to itself
        } else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode; // Link last node to new node
            newNode->next = head;    // New node points to head
        }
    }

    // Function to delete from the start
    void deleteAtStart() {
        if (head == NULL) {
            cout << "List is empty, can't delete from start." << endl;
            return;
        }

        if (head->next == head) { // Only one node
            delete head;
            head = NULL;
            return;
        }

        Node* current = head;
        while (current->next != head) { // Find the last node
            current = current->next;
        }
        // Update head and the last node's next pointer
        Node* temp = head;
        head = head->next;
        current->next = head; // Last node points to new head
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
        while (count < index - 1 && current->next != head) {
            current = current->next;
            count++;
        }

        // Check if the index is out of bounds
        if (current->next == head) {
            cout << "Index out of bounds." << endl;
            return;
        }

        Node* temp = current->next; // Node to be deleted
        current->next = temp->next;  // Link previous node to next node
        delete temp;
    }

    // Function to delete from the end
    void deleteAtEnd() {
        if (head == NULL) {
            cout << "List is empty, can't delete from end." << endl;
            return;
        }

        if (head->next == head) { // Only one node
            delete head;
            head = NULL;
            return;
        }

        Node* current = head;
        while (current->next->next != head) { // Find the second last node
            current = current->next;
        }

        // Delete the last node
        delete current->next; 
        current->next = head; // Update the second last node's next pointer
    }

    // Function to display the circular linked list
    void display() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Node* current = head;
        do {
            cout << current->data << " -> ";
            current = current->next;
        } while (current != head);
        cout << "(back to head: " << head->data << ")" << endl;
    }
};

int main() {
    CircularSinglyLinkedList list;

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

    // Delete from the middle (index 1)
    list.deleteAtIndex(1);
    cout << "After deleting at index 1: ";
    list.display();

    return 0;
}

