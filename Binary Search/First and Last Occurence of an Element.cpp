/* Bismillahir Rahmanir Raheem */
/* Shaid Meheraj */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
void lastOccurrence(int a[], int n, int x)
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
    cout << "Last Occurrence : " << ans << endl;
}
void firstOccurrence(int a[], int n, int x)
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
    cout << "First Occurrence : " << ans << endl;
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
    firstOccurrence(a, n, x);
    lastOccurrence(a, n, x);
    return 0;
}

//Alhamdulillah...




