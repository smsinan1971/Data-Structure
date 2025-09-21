#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* makeNode(int val) {
    Node* n = new Node();
    n->data = val;
    n->next = NULL;
    return n;
}


void insertNode(Node*& head, Node* node, Node* prev) {
    if (node == NULL) return;

    if (prev == NULL) {
        node->next = head;
        head = node;
        return;
    }

    node->next = prev->next;
    prev->next = node;
}

void push(Node*& head, int val) {
    Node* n = makeNode(val);
    n->next = head;
    head = n;
}

Node* findNode(Node* head, int val) {
    for (Node* p = head; p != NULL; p = p->next) {
        if (p->data == val) return p;
    }
    return NULL;
}
void printList(Node* head) {
    for (Node* p = head; p != NULL; p = p->next) {
        cout << p->data;
        if (p->next) cout << " -> ";
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    push(head, 10);
    push(head, 20);
    push(head, 30);

    cout << "Initial: ";
    printList(head);

    Node* nodeA = makeNode(99);
    insertNode(head, nodeA, NULL);
    cout << "After inserting 99 at head: ";
    printList(head);

    Node* prev = findNode(head, 20);
    Node* nodeB = makeNode(77);
    insertNode(head, nodeB, prev);
    cout << "After inserting 77 after 20: ";
    printList(head);

    return 0;
}

