#include <bits/stdc++.h>
#include <stack>
using namespace std;

int quickSortProcess(int arr[], int beg, int end) {
    int left = beg, right = end, loc = beg;
    while (true) {
        while (arr[loc] <= arr[right] && loc != right) {
            right--;
        } if (loc == right) return loc; 
        if (arr[loc] > arr[right]) {
            swap(arr[loc], arr[right]);
            loc = right;
        } 
        
        while (arr[loc] >= arr[left] && loc != left) {
            left++;
        } if (loc == left) return loc;
        if (arr[loc] < arr[left]) {
            swap(arr[loc], arr[left]);
            loc = left;
        }
    }
}

void quickSort(int arr[], int beg, int end) {
    stack<int> lower, upper;
    lower.push(beg);
    upper.push(end);
    while (!lower.empty()) {
        int loc = quickSortProcess(arr, lower.top(), upper.top());
        beg = lower.top(), end = upper.top();
        lower.pop(), upper.pop();
        if (loc + 1 < end) {
            lower.push(loc+1);
            upper.push(end);
        } if (beg < loc - 1 ) {
            lower.push(beg);
            upper.push(loc - 1);
        }
    }
}

int main() {
    
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
