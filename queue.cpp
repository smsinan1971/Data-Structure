#include <iostream>
using namespace std;

#define maxSize 5


int queue[maxSize];
int front = -1, rear = -1;


bool isEmpty() {
    return (front == -1 && rear == -1);
}


bool isFull() {
    return (rear == maxSize - 1);
}


void enqueue(int x) {
    if (isFull()) {
        cout << "Error: Queue full!" << endl;
        return;
    }

    else if (isEmpty()) {
        front = rear = 0;
        queue[rear] = x;
    } else {
        rear++;
        queue[rear] = x;
    }
}


void dequeue() {
    if (isEmpty()) {
        cout << "Error: Queue is empty! Dequeue not possible" << endl;
        return;
    }

    else if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

int frontElement() {
    if (isEmpty()) {
        cout << "Error: Queue is empty!" << endl;
        return -1;
    }
    return queue[front];
}

void showQueue() {
    if (isEmpty()) {
        cout << "Error: Cannot show queue because it is empty" << endl;
        return;
    }

    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
    }
    cout << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    showQueue();

    cout << "Front Element: " << frontElement() << endl;

    dequeue();
    showQueue();

    enqueue(60);
    showQueue();

    dequeue();
    dequeue();
    showQueue();

    return 0;
}
