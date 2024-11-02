#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;

    Node(int val) {
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print_doubly_linked_list(Node* head) {
    Node* tmp = head;
    while (tmp != NULL) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void insert_at_location(Node*& head, int position, int value) {
    Node* newNode = new Node(value);

    if (position == 0) {
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        return;
    }

    Node* tmp = head;
    int currentIndex = 0;

    while (tmp != NULL && currentIndex < position - 1) {
        tmp = tmp->next;
        currentIndex++;
    }

    if (tmp == NULL) {
        cout << "Position out of bounds!" << endl;
        delete newNode;
        return;
    }

    newNode->next = tmp->next;
    newNode->prev = tmp;

    if (tmp->next != NULL) {
        tmp->next->prev = newNode;
    }

    tmp->next = newNode;
}

int main() {
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);
    Node* d = new Node(50);

    head->next = a;
    a->prev = head;
    a->next = b;
    b->prev = a;
    b->next = c;
    c->prev = b;
    c->next = d;
    d->prev = c;

    cout << "Original Doubly Linked List: ";
    print_doubly_linked_list(head);

    int position, value;
    cout << "Enter the position to insert (0-indexed): ";
    cin >> position;
    cout << "Enter the value to insert: ";
    cin >> value;

    insert_at_location(head, position, value);

    cout << "Doubly Linked List after insertion: ";
    print_doubly_linked_list(head);

    return 0;
}
