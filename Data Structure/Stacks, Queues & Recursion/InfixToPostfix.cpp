#include<bits/stdc++.h>
using namespace std;
bool isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}
int precedence(char op)
{
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    if(op == '^') return 3;

    return 0;
}
string infixToPostfix(string infix)
{
    stack<char> stk;
    string postfix = "";

    
    for(char ch : infix)
    {
        //operand 
        if(isalnum(ch))
        {
            postfix += ch;
        }
        //left parenthesis
        else if(ch == '(')
        {
            stk.push(ch);
        }
        else if(ch == ')')
        {
            while(!stk.empty() && stk.top() != '(')
            {
                postfix += stk.top();
                stk.pop();
            }
            stk.pop();
        }
        else if(isOperator(ch))
        {
            while(!stk.empty() && precedence(stk.top()) >= precedence(ch))
            {
                 postfix+= stk.top();
                 stk.pop();
            }
            stk.push(ch);
        }
    }

    while(!stk.empty())
    {
        postfix += stk.top();
        stk.pop();
    }

    return postfix;
    
}
int main()
{
    string infix;
    cin >> infix;
    string postfix = infixToPostfix(infix);

    cout << "The postfix String : ";
    cout << postfix << endl;

}