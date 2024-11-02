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

    if(rootVal == -1) return NULL;

    Node* root = new Node(rootVal);
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* curr = q.front();
        q.pop();

        int leftVal, rightVal;
        cin >> leftVal;
        if(leftVal != -1)
        {
            curr -> left = new Node(leftVal);
            q.push(curr -> left);
        }

        cin >> rightVal;
        if(rightVal != -1)
        {
            curr -> right = new Node(rightVal);
            q.push(curr->right);
        }
    }

    return root;
}
void InOrderTraversal(Node* root)
{
    if(root == NULL) return;

    stack<Node*>st;
    Node* temp = root;

    while(temp != NULL || !st.empty())
    {
        while(temp != NULL)
        {
            st.push(temp);
            temp = temp -> left;
        }

        temp = st.top();
        st.pop();
        
        //processing the current node
        cout << temp->val << " ";
        
        //Move to the right child
        temp = temp -> right;
    }
    cout << endl;
}
int main()
{
    Node* root = buildTree();
    InOrderTraversal(root);  
}