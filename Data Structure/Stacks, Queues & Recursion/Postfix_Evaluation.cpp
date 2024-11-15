// C++ program to evaluate value of a postfix expression
#include <bits/stdc++.h>
using namespace std;

int evaluatePostfix(string exp)//int value return korche
{

    stack<int> st;

    for (int i = 0; i < exp.size(); i++)
    {
        // If the scanned character is an operand
        // (number here), push it to the stack.
        if (isdigit(exp[i]))
            st.push(exp[i] - '0');

        // If the scanned character is an operator,
        // pop two elements from stack apply the operator
        else
        {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();
            switch (exp[i])
            {
            case '+':
                st.push(val2 + val1);
                break;

            case '-':
                st.push(val2 - val1);
                break;

            case '*':
                st.push(val2 * val1);
                break;

            case '/':
                st.push(val2 / val1);
                break;
            }
        }
    }
    return st.top();
}

int main()
{
    string exp = "231*+9-";

    // Function call
    cout << "Postfix Evaluation: " << evaluatePostfix(exp);
    return 0;
}
