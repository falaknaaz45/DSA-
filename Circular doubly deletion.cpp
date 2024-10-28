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

// CircularDoublyLinkedList class with deletion functions
class CircularDoublyLinkedList {
public:
    Node* head;

    CircularDoublyLinkedList() {
        head = NULL;
    }

    // Function to insert at the end (for easier testing)
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

        Node* tail = head->prev; // Find the tail
        Node* temp = head;       // Node to be deleted
        head = head->next;       // Update head to next node
        tail->next = head;       // Update tail's next to new head
        head->prev = tail;       // New head's previous points to tail
        delete temp;             // Delete the old head
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
        while (count < index && current != NULL) {
            current = current->next;
            count++;
            if (current == head) { // Stop if we've looped back to head
                break;
            }
        }

        // If current is head, it means index is out of bounds
        if (count == index && current != head) {
            cout << "Index out of bounds." << endl;
            return;
        }

        if (current == head) {
            cout << "Node not found at index " << index << "." << endl;
            return;
        }

        // Delete the current node
        Node* temp = current; // Node to be deleted
        current->prev->next = current->next; // Link previous to next
        current->next->prev = current->prev; // Link next to previous
        delete temp; // Delete the current node
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

        Node* tail = head->prev; // Find the tail
        tail->prev->next = head;  // Link second last to head
        head->prev = tail->prev;   // Update head's previous
        delete tail;               // Delete the tail
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

    // Try deleting at an out-of-bounds index
    list.deleteAtIndex(10);

    return 0;
}

