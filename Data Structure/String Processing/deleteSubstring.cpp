#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    getline(cin, str);
    string delete_word;
    cin >> delete_word;
    int index = str.find(delete_word); //find index from string where the word in start

    while(index != -1) //if index is not find then -1
    {
        str.erase(index, delete_word.length()); //do erase from index to word length
        index = str.find(delete_word); //if have any similar word!!
    }
    
    cout << str << endl; 

    return 0;
}