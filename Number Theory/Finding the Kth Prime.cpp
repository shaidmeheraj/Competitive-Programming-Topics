/* Bismillahir Rahmanir Raheem */
/* Shaid Meheraj */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

bool prime[90000001]; // basically array size is greater than n
int n=90000000; // globally declared
vector<ll> v;
void solve()
{
    for(int i=2; i*i<=n; i++)
    {
        if(prime[i] == false)
        {
            for(int j= i*i; j<=n; j+=i)
            {
                prime[j] = true;
            }
        }
    }

    for(int i=2; i<=n; i++){
        if(prime[i]==false) v.push_back(i);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    int t;
    cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       cout << v[n-1] << endl; //initially vector index starts from 0
    }

    return 0;
}

//Alhamdulillah...




