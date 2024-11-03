#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
class Queue {
public:
    Node* front;  
    Node* rear;   
    Queue() {
        front = rear = NULL;
    }
    void enqueue(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;
        if (rear == NULL) {
            front = rear = newNode;  
        } else {
            rear->next = newNode;    
            rear = newNode;          
        }
        cout << "Enqueue: " << data << "\n";
    }

    bool isEmpty() {
        return front == NULL;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow\n";
            return -1;
        }
        int value = front->data;  
        Node* temp = front;
        front = front->next;      
        delete temp;              

        if (front == NULL) {      
            rear = NULL;
        }

        cout << "Dequeue: " << value << "\n";
        return value;
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Current queue elements: ";
        Node* current = front;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }
};
int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.display();
    q.enqueue(4);
    q.display();
    int data = q.dequeue();
    q.display();
    data = q.dequeue();
    q.display();
    data = q.dequeue();
    q.display();
    data = q.dequeue();
    q.display();
    data = q.dequeue();
    return 0;
}
