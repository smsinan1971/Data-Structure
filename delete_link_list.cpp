#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

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

void deleteNode(Node*& head, Node* prev) {

    if (prev != NULL) {
        Node* curr = prev->next;
        if (curr == NULL) return;
        prev->next = curr->next;
        delete curr;
    }
    else {
        if (head == NULL) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;

    Node* n1 = new Node{10, NULL};
    Node* n2 = new Node{20, NULL};
    Node* n3 = new Node{30, NULL};
    Node* n4 = new Node{40, NULL};

    insertNode(head, n1, NULL);   // Insert at head
    insertNode(head, n2, n1);     // Insert after n1
    insertNode(head, n3, n2);     // Insert after n2
    insertNode(head, n4, n3);     // Insert after n3

    cout << "Original List: ";
    printList(head);

    deleteNode(head, n1);
    cout << "After deleting node after 10: ";
    printList(head);

    deleteNode(head, NULL);
    cout << "After deleting head: ";
    printList(head);

    return 0;
}
