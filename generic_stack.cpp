#include <iostream>
using namespace std;

template <typename T> // T is template parameter
class MyStack {
    T *Stack;
    int Top;
    int MaxSize;

public:
    MyStack(int Size = 100) {
        MaxSize = Size;
        Stack = new T[MaxSize];  // Dynamically allocate memory for the stack
        Top = 0;
    }


    ~MyStack() {
        delete[] Stack;  // Free the dynamically allocated stack memory
    }


    bool isEmpty() {
        return (Top == 0);
    }


    bool isFull() {
        return (Top == MaxSize);
    }


    bool push(T Element) {
        if (isFull()) {
            resize(10);
        }
        Stack[Top++] = Element;
        return true;
    }


    bool pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop.\n";
            return false;
        }
        Top--;
        return true;
    }


    T topElement() {
        if (!isEmpty()) {
            return Stack[Top - 1]; // Return the top element
        }
        cout << "Stack is empty.\n";
        return T();
    }


    void show() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }

        for (int i = Top - 1; i >= 0; i--) {
            cout << Stack[i] << " ";
        }
        cout << endl;
    }


    void resize(int Size) {
        T *tempStk = new T[MaxSize + Size];
        for (int i = 0; i < MaxSize; i++) {
            tempStk[i] = Stack[i];
        }
        MaxSize += Size;
        delete[] Stack;
        Stack = tempStk;
    }
};

int main() {
    MyStack<float> stack(5);

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);


    cout << "Stack after pushing 5 elements:\n";
    stack.show();

    stack.push(60);


    cout << "Stack after pushing 6th element (resize triggered):\n";
    stack.show();

    cout << "Top element: " << stack.topElement() << endl;

    stack.pop();
    cout << "Stack after popping the top element:\n";
    stack.show();

    return 0;
}

