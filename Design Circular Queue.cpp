#include <iostream>
using namespace std;

class MyCircularQueue {
private:
    int* queue;
    int front;
    int rear;
    int size;
    int capacity;

public:

    MyCircularQueue(int k) {
        capacity = k;
        queue = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    ~MyCircularQueue() {
        delete[] queue;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % capacity;
        queue[rear] = value;
        size++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        size--;
        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return queue[front];
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return queue[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

int main() {
    MyCircularQueue q(3);

    cout << q.enQueue(1) << endl; // returns true
    cout << q.enQueue(2) << endl; // returns true
    cout << q.enQueue(3) << endl; // returns true
    cout << q.enQueue(4) << endl; // returns false (queue is full)

    cout << q.Rear() << endl; // returns 3
    cout << q.isFull() << endl; // returns true

    cout << q.deQueue() << endl; // returns true
    cout << q.enQueue(4) << endl; // returns true

    cout << q.Rear() << endl; // returns 4

    return 0;
}
