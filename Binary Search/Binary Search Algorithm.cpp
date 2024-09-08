/* Bismillahir Rahmanir Raheem */
/* Shaid Meheraj */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
void solve(void)
{
    int n;
    cin >> n;
    int a[n+1];
    for(int i=0; i<n; i++) cin >> a[i];
    int x;
    cin >> x;
    int l=0;
    int r=n-1;

    while(l<=r)
    {
        int mid=(l+r)/2;
        if(a[mid] == x)
        {
            cout << "Found. The index is : " << mid << endl;
            return;
        }
        else if(a[mid] < x) l=mid+1;
        else r=mid-1;
    }
    cout << "Not Found" << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}

//Alhamdulillah...




