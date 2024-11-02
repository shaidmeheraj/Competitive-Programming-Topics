#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
void preOrderTraversal(Node* root)
{
    if(root == NULL) return;

    stack<Node*>st;
    Node* temp = root;

    while(temp != NULL || !st.empty())
    {
        cout << temp->val << endl;

        if(temp->right != NULL) st.push(temp->right);

        if(temp->left != NULL)
        {
            temp = temp -> left;
        }
        else{
            if(!st.empty())
            {
                temp = st.top();
                st.pop();
            }
            else temp = NULL;
        }
    }
}
int main()
{
    Node* root = new Node(1);
    Node* a = new Node(2);
    Node* b = new Node(3);
    Node* c = new Node(4);
    Node* d = new Node(5);
    Node* e = new Node(6);

    root->left = a;
    root->right = b;
    a->left = c;
    a->right = d;
    b->left = e;

    preOrderTraversal(root);  
}