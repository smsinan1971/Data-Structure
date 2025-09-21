#include <iostream>
using namespace std;

const int MaxSize = 100;
int Stack[MaxSize], Top = 0;

bool isEmpty();
bool isFull();
bool push(int Element);
bool pop();
int topElement();
void show();

int main() {

    push(11);
    push(12);
    push(13);
    push(14);

    cout << "Top element: " << topElement() << endl;

    show();

    pop();
    cout << "After popping, Top element: " << topElement() << endl;

    show();

    return 0;
}

bool isEmpty() {
    return (Top == 0);
}

bool isFull() {
    return (Top == MaxSize);
}

bool push(int Element) {
    if (isFull()) {
        cout << "Stack is Full\n";
        return false;
    }
    Stack[Top++] = Element; //post-increment operator
    return true;
}

bool pop() {
    if (isEmpty()) {
        cout << "Stack is Empty\n";
        return false;
    }
    Top--;
    return true;
}

int topElement() {
    if (!isEmpty()) {
        return Stack[Top - 1];
    }
    cout << "Stack is Empty\n";
    return -1;
}

void show() {
    if (isEmpty()) {
        cout << "Stack is Empty\n";
        return;
    }
    for (int i = Top - 1; i >= 0; i--) {
        cout << Stack[i] << endl;
    }
}
