#include <bits/stdc++.h>
using namespace std;
int main()
{
    string T;
    getline(cin , T);
    string P;
    cin >> P;
    int s = T.length();
    int r = P.length();
    int k = 1, max = s - r + 1;
    int index = 0;
    while (k <= max)
    {
        for (int L = 0; L < r; L++)
        {
            if (P[L] != T[L + k])
            {

                break;
            }
            else if (L == r - 1)
            {
                index = k;
            }
        }
        k++;
    }
    if (index == 0)
    {
        cout << "Error" << endl;
    }
    else
    {
        cout << index << endl;
    }
}