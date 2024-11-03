#include <iostream>
using namespace std;

#define MAX 5  

class OrderQueue {
    int orders[MAX];   
    int front;         
    int rear;          
    int count;         

public:
    OrderQueue() : front(0), rear(-1), count(0) {}  

    
    void enqueue(int orderNumber) {
        if (count == MAX) {  
            cout << "Queue is full. Cannot add more orders.\n";
        } else {
            rear = (rear + 1) % MAX;   
            orders[rear] = orderNumber;  
            count++;
            cout << "Order number " << orderNumber << " added to the queue.\n";
        }
    }

    
    void dequeue() {
        if (count == 0) {  
            cout << "No orders to process. Queue is empty.\n";
        } else {
            cout << "Processing order number " << orders[front] << endl;
            front = (front + 1) % MAX;  
            count--;
        }
    }

   
    void displayQueue() {
        if (count == 0) {
            cout << "No orders in the queue.\n";
        } else {
            cout << "Current orders in the queue:\n";
            for (int i = 0; i < count; i++) {
                int index = (front + i) % MAX;
                cout << "Order number: " << orders[index] << endl;
            }
        }
    }
};

int main() {
    OrderQueue queue;

    int choice, orderNumber;
    do {
        cout << "\n1. Add an order\n2. Process an order\n3. Display all orders\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter order number to add: ";
                cin >> orderNumber;
                queue.enqueue(orderNumber);  
                break;
            case 2:
                queue.dequeue();             
                break;
            case 3:
                queue.displayQueue();        
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

