#include <iostream>

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}
};

// Circular Queue class
class CircularQueue {
private:
    Node* front;
    Node* rear;

public:
    CircularQueue() : front(nullptr), rear(nullptr) {}

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Enqueue operation to insert an element at the rear of the queue
    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        // Make the queue circular
        rear->next = front;

        std::cout << value << " enqueued to the queue." << std::endl;
    }

    // Dequeue operation to remove an element from the front of the queue
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return;
        }

        Node* temp = front;

        if (front == rear) {
            // If there's only one element in the queue
            front = rear = nullptr;
        } else {
            front = front->next;
            rear->next = front; // Make the queue circular
        }

        std::cout << temp->data << " dequeued from the queue." << std::endl;
        delete temp;
    }

    // Display the elements of the queue
    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }

        Node* current = front;
        std::cout << "Queue elements: ";
        do {
            std::cout << current->data << " ";
            current = current->next;
        } while (current != front);

        std::cout << std::endl;
    }
};

int main() {
    CircularQueue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    queue.display();

    queue.dequeue();
    queue.display();

    return 0;
}
