/* Bismillahir Rahmanir Raheem */
/* Shaid Meheraj */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
void NumOfTimeArrRotated(int a[], int n)
{
    int l=0;
    int r=n-1;
    int ans=0;
    while(l<=r)
    {
        int mid=(l+r)/2;

        if(mid < r && a[mid+1] < a[mid]){
            ans = mid + 1;
            break;
        }
        else if(mid > l && a[mid-1]>a[mid])
        {
            ans = mid;
            break;
        }

        if(a[r] > a[mid]) r = mid-1;
        else l=mid+1;
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a[n+1];
    for(int i=0; i<n; i++) cin >> a[i];

    NumOfTimeArrRotated(a, n);

    return 0;
}

//Alhamdulillah...






