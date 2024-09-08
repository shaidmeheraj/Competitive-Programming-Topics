/* Bismillahir Rahmanir Raheem */
/* Shaid Meheraj */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int lastOccurrence(int a[], int n, int x)
{
    int l=0;
    int r=n-1;
    int ans=-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(a[mid] == x)
        {
            ans = mid;
            l = mid + 1;
        }
        else if(a[mid] < x) l=mid+1;
        else r=mid-1;
    }
    return ans;
}
int firstOccurrence(int a[], int n, int x)
{
    int l=0;
    int r=n-1;
    int ans=-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(a[mid] == x)
        {
            ans = mid;
            r = mid - 1;
        }
        else if(a[mid] < x) l=mid+1;
        else r=mid-1;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a[n+1];
    for(int i=0; i<n; i++) cin >> a[i];
    int x;
    cin >> x;
    int f = firstOccurrence(a, n, x);
    int l = lastOccurrence(a, n, x);

    cout << l-f+1 << endl;
    return 0;
}

//Alhamdulillah...





