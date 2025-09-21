#include <iostream>
using namespace std;

const int maxSize = 5;
int queue[maxSize];
int front = -1, rear = -1;


bool isEmpty() {
    return (front == -1);
}

bool isFull() {
    return ((rear + 1) % maxSize == front);
}

void enqueue(int x) {
    if (isFull()) {
        cout << "Error: Queue is full!" << endl;
    } else {
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % maxSize;
        }
        queue[rear] = x;
    }
}

void dequeue() {
    if (isEmpty()) {
        cout << "Error: Queue is empty!" << endl;
    } else {
        if (front == rear) {
            front = rear = -1; // Queue becomes empty
        } else {
            front = (front + 1) % maxSize;
        }
    }
}

void showQueue() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
    } else {
        int i = front;
        while (i != rear) {
            cout << queue[i] << " ";
            i = (i + 1) % maxSize;
        }
        cout << queue[rear] << endl; // Print the rear element
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    cout << "Queue after enqueuing 5 elements: ";
    showQueue();

    dequeue();
    cout << "Queue after one dequeue: ";
    showQueue();

    enqueue(60);
    cout << "Queue after enqueuing 60: ";
    showQueue();

    return 0;
}

