#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

void print_linked_list(Node* head) {
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
        delete temp;
        return;
    }

    Node* tmp = head;
    int currentIndex = 0;

    while (tmp != NULL && currentIndex < position - 1) {
        tmp = tmp->next;
        currentIndex++;
    }

    if (tmp == NULL || tmp->next == NULL) {
        cout << "Position out of bounds!" << endl;
        return;
    }

    Node* nodeToDelete = tmp->next;
    tmp->next = nodeToDelete->next;
    delete nodeToDelete;
}

int main() {
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);
    Node* d = new Node(50);

    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;

    cout << "Original Linked List: ";
    print_linked_list(head);

    int position;
    cout << "Enter the position to delete (0-indexed): ";
    cin >> position;

    delete_at_location(head, position);

    cout << "Linked List after deletion: ";
    print_linked_list(head);

    return 0;
}
