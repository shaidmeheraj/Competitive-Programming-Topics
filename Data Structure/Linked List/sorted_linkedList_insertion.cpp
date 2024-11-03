#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

void print_linked_list(Node* head) {
    Node* current = head;
    cout << "Linked list: ";
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

Node* insert_in_sorted_list(Node* head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr || val < head->val) {
        newNode->next = head;
        cout << "Inserting " << val << " at the head. Address: " << newNode << endl;
        return newNode;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->val < val) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    cout << "Inserting " << val << " after " << current->val 
         << ". Current Address: " << current  
         << ", Next Address: " << current->next << endl;

    return head;
}

int main() {
    Node* head = nullptr;
    int n, value;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> value;
        head = insert_in_sorted_list(head, value);
    }
    cin >> value;
    head = insert_in_sorted_list(head, value);
    print_linked_list(head);

    return 0;
}
