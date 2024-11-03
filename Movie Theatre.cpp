#include <iostream>
using namespace std;


struct Node {
    int bookingID;
    Node* next;
    
    Node(int id) : bookingID(id), next(NULL) {}  
};


class BookingQueue {
    Node* front;  
    Node* rear;   

public:
    BookingQueue() : front(NULL), rear(NULL) {}  

   
    void enqueue(int id) {
        Node* newNode = new Node(id);  
        if (rear == NULL) {  
            front = rear = newNode;
        } else {
            rear->next = newNode;  
            rear = newNode;       
        }
        cout << "Booking with ID " << id << " added to the queue.\n";
    }

   
    void dequeue() {
        if (front == NULL) {  
            cout << "No bookings to process. Queue is empty.\n";
        } else {
            Node* temp = front;        
            cout << "Processing booking with ID " << front->bookingID << endl;
            front = front->next;        

            if (front == NULL) {     
                rear = NULL;
            }

            delete temp;                
        }
    }

    
    void displayQueue() {
        if (front == NULL) {
            cout << "No bookings in the queue.\n";
        } else {
            Node* temp = front;
            cout << "Current bookings in the queue:\n";
            while (temp != NULL) {
                cout << "Booking ID: " << temp->bookingID << endl;
                temp = temp->next;
            }
        }
    }

    
    ~BookingQueue() {
        while (front != NULL) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    BookingQueue queue;

    int choice, bookingID;
    do {
        cout << "\n1. Add a booking\n2. Process a booking\n3. Display all bookings\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter booking ID to add: ";
                cin >> bookingID;
                queue.enqueue(bookingID);  
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

