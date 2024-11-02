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
Node* buildTree()
{
    int rootVal;
    cin >> rootVal;
    Node* root;
    if(rootVal == -1) root = NULL;
    else root = new Node(rootVal);
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* curr = q.front();
        q.pop();

        int leftVal, rightVal;
        cin >> leftVal >> rightVal;
        Node* myLeft;
        Node* myRight;
        if(leftVal == -1) myLeft = NULL;
        else myLeft = new Node(leftVal);

        if(rightVal == -1) myRight = NULL;
        else myRight = new Node(rightVal);

        curr -> left = myLeft;
        curr->right = myRight;

        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }

    return root;
}
void PostOrderTraversal(Node* root)
{
    if(root == NULL) return;

    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);

    cout << root->val << " ";
    
}
int main()
{
    Node* root = buildTree();
    PostOrderTraversal(root); 
    cout << endl; 

    return 0;
}