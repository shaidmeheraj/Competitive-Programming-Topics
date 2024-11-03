//stack
#include<bits/stdc++.h>
#include<vector>
using namespace std;
const int N=1e5+5;
vector<int>v[N];
bool vis[N];

void dfs(int source){
    stack<int>st;//initialize queue
    st.push(source);
    vis[source]=true;
    while (!st.empty())
    {
        int current = st.top();
        st.pop();
        cout<<current<<endl;

        for(int child : v[current]){
            if (!vis[child])
            {
                st.push(child);
                vis[child]=true;
            }
            
        }
    }
    
}

int main(){
    int n,e;
    cin>>n>>e;
   while (e--)
   {
    int a,b;
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
   }
   memset(vis,false,sizeof(vis));
   int src;
   cin >> src;
   dfs(src);
   
    
}