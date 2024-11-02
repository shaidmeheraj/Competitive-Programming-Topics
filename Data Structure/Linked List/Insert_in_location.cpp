#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
   int val;
   Node* next;
   Node(int val)
   {
       this->val=val;
       this->next=NULL;
   }

};
void print_linked_list(Node* head)
{
    Node* tmp=head;
    while(tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp=tmp->next;
    }
    cout << endl;
}
void insert_at_position(Node*& head, int position) //address must be follow
{
    int val;
    cin >> val;
    Node* newNode = new Node(val);

    if(position == 0)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    int currentIndex = 0;
    while(temp != NULL && currentIndex < position - 1)
    {
        temp = temp -> next;
        currentIndex++;
    }

    if(temp == NULL)
    {
        cout << "Position out of bounds" << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp -> next = newNode;
}
int main()
{
    Node *head= new Node(10);
    Node *a= new Node(20);
    Node *b= new Node(30);
    Node *c= new Node(40);
    Node *d= new Node(50);

    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;

    int position;
    cin >> position;

    cout << "Before Insert : ";
    print_linked_list(head);
    insert_at_position(head, position);
    cout << "After insert: ";
    print_linked_list(head);

    return 0;
}
