// template<typename> T , is the new learning here

#include <iostream>

// Node class template for the linked list nodes
template<typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Queue class template
template<typename T>
class Queue {
private:
    int size;
    Node<T>* head;
    Node<T>* tail;

public:
    Queue() {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    void enqueue(T data) {
        Node<T>* temp = new Node<T>(data);
        if (isEmpty()) {
            head = temp;
            tail = head;
        } else {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    T dequeue() {
        if (isEmpty()) {
            // Handle empty queue case, returning a default value (0 in this case)
            return 0;
        }
        T data = head->data;
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        size--;
        return data;
    }

    T front() {
        if (isEmpty()) {
            // Handle empty queue case, returning a default value (0 in this case)
            return 0;
        }
        return head->data;
    }
};

int main() {
    // Example usage of the Queue class with int data type
    Queue<int> intQueue;

    intQueue.enqueue(1);
    intQueue.enqueue(2);
    intQueue.enqueue(3);

    std::cout << "Front element: " << intQueue.front() << std::endl;
    std::cout << "Queue size: " << intQueue.getSize() << std::endl;

    while (!intQueue.isEmpty()) {
        std::cout << "Dequeue: " << intQueue.dequeue() << std::endl;
    }

    std::cout << "Queue size after dequeue operations: " << intQueue.getSize() << std::endl;

    return 0;
}

