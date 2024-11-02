#include<bits/stdc++.h>
using namespace std;
vector<int> INSERT(vector<int>& v, int n, int pos, int item)
{
    v.resize(n+1);
    for(int j = n; j > pos ; j--)
    {
        v[j] = v[j-1];
    }
    v[pos] = item;

    return v;
}
int main()
{
    int n;
    cin >> n;
    vector<int>v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    int pos, item;
    cin >> pos >> item;

    if (pos < 0 || pos > n) {
        cout << "Invalid position" << endl;
        return 1;
    }
    
    vector<int> vec = INSERT(v, n, pos, item);

    for(int x : vec)
    {
        cout << x << " ";
    }
}