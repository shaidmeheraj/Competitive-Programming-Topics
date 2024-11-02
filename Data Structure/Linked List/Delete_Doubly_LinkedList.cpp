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

void delete_at_location(Node*& head, int position) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    if (position == 0) {
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;
        return;
    }

    Node* tmp = head;
    int currentIndex = 0;

    while (tmp != NULL && currentIndex < position) {
        tmp = tmp->next;
        currentIndex++;
    }

    if (tmp == NULL) {
        cout << "Position out of bounds!" << endl;
        return;
    }

    if (tmp->prev != NULL) {
        tmp->prev->next = tmp->next;
    }

    if (tmp->next != NULL) {
        tmp->next->prev = tmp->prev;
    }

    delete tmp;
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

    int position;
    cout << "Enter the position to delete (0-indexed): ";
    cin >> position;

    delete_at_location(head, position);

    cout << "Doubly Linked List after deletion: ";
    print_doubly_linked_list(head);

    return 0;
}
