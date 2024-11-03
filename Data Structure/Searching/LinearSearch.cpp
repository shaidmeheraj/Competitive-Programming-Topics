#include<bits/stdc++.h>
using namespace std;

int linearSearch(int arr[],int n,int target){
    for (int i = 0; i < n; i++)
    {
        if (arr[i]==target)
        {
            return i;
        }
        
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

    int result = linearSearch(arr,n,target);

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