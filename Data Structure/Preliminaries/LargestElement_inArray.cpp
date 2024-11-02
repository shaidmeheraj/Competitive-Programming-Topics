#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    int loc = 0, mx = arr[0];
    for(int i=1; i<n; i++)
    {
         if(arr[i] > mx)
         {
            mx = arr[i];
            loc = i;
         } 
    }
    cout << "Largest Element : " << mx << " Index : " << loc+1 << endl;
}