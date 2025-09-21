#include <iostream>
using namespace std;

class MyStack {
    int *Stack, Top, MaxSize;

public:
    MyStack(int Size = 100);
    ~MyStack();
    bool isEmpty();
    bool isFull();
    bool push(int Element);
    bool pop();
    int topElement();
    void show();
    void resize(int Size = 100);
};


MyStack::MyStack(int Size) {
    MaxSize = Size;
    Stack = new int[MaxSize]; // Dynamically allocate memory for the stack
    Top = 0;
}


MyStack::~MyStack() {
    delete[] Stack; // Free the memory used by the stack
}


bool MyStack::isEmpty() {
    return (Top == 0);
}

bool MyStack::isFull() {
    return (Top == MaxSize);
}


bool MyStack::push(int Element) {
    if (isFull()) {
        resize();
    }
    Stack[Top++] = Element;
    return true;
}

bool MyStack::pop() {
    if (isEmpty()) {
        cout << "Stack is empty. Cannot pop.\n";
        return false;
    }
    Top--;
    return true;
}

int MyStack::topElement() {
    if (!isEmpty()) {
        return Stack[Top - 1];
    }
    cout << "Stack is empty.\n";
    return -1;
}

void MyStack::show() {
    if (isEmpty()) {
        cout << "Stack is empty.\n";
        return;
    }
    for (int i = Top - 1; i >= 0; i--) {
        cout << Stack[i] << " ";
    }
    cout << endl;
}

void MyStack::resize(int Size) {
    int *tempStk = new int[MaxSize + Size];
    for (int i = 0; i < MaxSize; i++) {
        tempStk[i] = Stack[i];
    }
    MaxSize += Size;
    delete[] Stack;
    Stack = tempStk;
}
int main() {
    MyStack stack(5);

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);

    cout << "Stack after pushing 5 elements:\n";
    stack.show();

    stack.push(60);
    cout << "Stack after pushing 60 (resized):\n";
    stack.show();

    cout << "Top element: " << stack.topElement() << endl;

    stack.pop();
    cout << "Stack after popping the top element:\n";
    stack.show();

    return 0;
}

