#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    getline(cin, str);
    
    string p, q;
    cin >> p >> q;
    int index = str.find(p); 

    while(index != -1) 
    {
        str.replace(index, p.length(), q); 
        index = str.find(p, index + q.length()); //when replace q then move to index + replace word's length
    }
    
    cout << str << endl; 

    return 0;
}