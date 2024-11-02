#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    getline(cin, str);
    string delete_word;
    cin >> delete_word;
    int index = str.find(delete_word);

    while(index != -1)
    {
        str.erase(index, delete_word.length());
        index = str.find(delete_word);
    }
    
    cout << str << endl;

    return 0;
}