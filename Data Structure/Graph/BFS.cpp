//using stack just use stack where you use queue in BFS
#include<bits/stdc++.h>
#include<vector>
using namespace std;
const int N=1e5+5;
vector<int>v[N];
bool vis[N];

void bfs(int source){
    queue<int>q;//initialize queue
    q.push(source);
    vis[source]=true;
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        cout<<current<<endl;

        for(int child : v[current]){
            if (!vis[child])
            {
                q.push(child);
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
   bfs(src);
   
    
}