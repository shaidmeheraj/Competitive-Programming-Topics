#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[],int n, int target){
    int left=0,right=n-1;
    while (left<=right)
    {
        int mid=(left+right)/2;
        if(arr[mid]==target)
        return mid;
        else if(arr[mid]<target)
        left=mid+1;
        else
        right=mid-1;
    }
    return -1;
    
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;
    cin>>target;

    int result = binarySearch(arr,n,target);

    for (int i = 0; i < n; i++)
    {
        cout<< arr[i] <<" ";
    }

    if (result!=-1)
    {
        cout<<"Element found at index "<<result<<endl;
    }
    else{
        cout<<"Element not found at index "<<endl;
    }
    
}