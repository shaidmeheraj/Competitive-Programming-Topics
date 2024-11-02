#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int d = b*b - 4*a*c; // d for discriminant
    int val1, val2;
    if(d > 0)
    {
        val1 = (-b + sqrt(d)) / 2*a;
        val2 = (-b - sqrt(d)) / 2*a;
        cout << "x1 : " << val1 << ", x2 : " << val2 << endl;
    }
    else if(d == 0)
    {
        val1 = -b / 2*a;
        cout <<"x : " << val1 << endl;
        cout << "Unique Solution" << endl;
    }
    else
    {
        cout << "NO Real Solutions" << endl;
    }

    return 0;
}