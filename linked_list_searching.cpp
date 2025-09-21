#include <iostream>
using namespace std;

// Define a node structure
struct Node {
    int data;
    Node *next;
};

void search(Node *head, int item) {
    Node* curr = head;

    while (curr != NULL) {
        if (curr->data == item) {
            cout << "Found" << endl;
            return;
        }
        curr = curr->next;
    }

    cout << "Not Found" << endl;
}
//reference to a pointer
void push(Node* &head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = head;
    head = newNode;
}

int main() {
    Node* head = NULL;

    push(head, 10);
    push(head, 20);
    push(head, 30);

    int item;
    cout << "Enter item to search: ";
    cin >> item;

    search(head, item);

    return 0;
}
