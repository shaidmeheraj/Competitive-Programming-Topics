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
int find_index_in_SortedList(Node* head, int val)
{
    Node* temp = head;
    int currIndex = 0;

    while(temp != NULL)
    {
        if(temp->val == val) return currIndex;
        else if(temp->val > val) return -1;
        temp= temp->next;
        currIndex++;
    }

    return -1;
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

    print_linked_list(head);

    int value;
    cin >> value;

    int location = find_index_in_SortedList(head, value);

    if(value == -1) cout << "Not found in list!";
    else cout << " found at location : " << location << endl;

}
