#include<iostream>
using namespace std;

class Node {
public:
    int id, priority;
    Node* next, *prev;
};

class Queue {
    Node* front, *rear, *temp;
public:
    Queue() {
        front = rear = nullptr;
    }

    void create() {
        front = rear = nullptr;
        for (int i = 21301; i <= 21385; i++) {
            Node* t = new Node;
            t->id = i;
            t->priority = 0;
            t->next = t->prev = nullptr;

            if (front == nullptr) {
                front = rear = t;
            }
            else {
                rear->next = t;
                t->prev = rear;
                rear = t;
            }
        }
    }

    void enqueue() {
        int id, pri;
        cout << "Enter id: ";
        cin >> id;
        cout << "Enter priority: ";
        cin >> pri;

        if (id >= 21301 && id <= 21385) {
            temp = front;
            while (temp != nullptr) {
                if (temp->id == id) {
                    temp->priority = pri;
                    cout << "Added to queue" << endl;
                    return;
                }
                temp = temp->next;
            }

            cout << "ID not found!" << endl;
        }
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node* maxPriority = front;
        temp = front->next;

        while (temp != nullptr) {
            if (temp->priority < maxPriority->priority) {
                maxPriority = temp;
            }
            temp = temp->next;
        }

        if (maxPriority->prev != nullptr) {
            maxPriority->prev->next = maxPriority->next;
        }
        else {
            front = maxPriority->next;
        }

        if (maxPriority->next != nullptr) {
            maxPriority->next->prev = maxPriority->prev;
        }
        else {
            rear = maxPriority->prev;
        }
        cout << "Employee: " << maxPriority->id << " had the highest priority, dequeued!" << endl;
        delete maxPriority;
    }

    void first() {
        if (front == nullptr) {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node* maxPriority = front;
        temp = front->next;

        while (temp != nullptr) {
            if (temp->priority < maxPriority->priority) {
                maxPriority = temp;
            }
            temp = temp->next;
        }
        cout << "Employee: " << maxPriority->id << " is the first in queue according to the priority!" << endl;
    }

    void displayMenu() {
        int choice;
        do {
            cout << "\n1. Add Job\n2. Delete Job\n3. Display Job with Highest Priority\n4. Exit\nEnter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                first();
                break;
            case 4:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice! Please enter again.";
                break;
            }
        } while (choice != 4);
    }
};

int main() {
    Queue jobQueue;
    jobQueue.create();
    jobQueue.displayMenu();
    return 0;
}
