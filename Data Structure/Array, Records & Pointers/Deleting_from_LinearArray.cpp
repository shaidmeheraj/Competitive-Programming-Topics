#include<bits/stdc++.h>
using namespace std;
vector<int> DELETE(vector<int>& v, int n, int pos)
{
    v.resize(n-1);
    for(int j = pos; j > n; j++)
    {
        v[j] = v[j+1];
    }
    return v;
}
int main()
{
    int n;
    cin >> n;
    vector<int>v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    int pos;
    cin >> pos;

    if (pos < 0 || pos > n) {
        cout << "Invalid position" << endl;
        return 1;
    }
    
    vector<int> vec = DELETE(v, n, pos);

    for(int x : vec)
    {
        cout << x << " ";
    }
}