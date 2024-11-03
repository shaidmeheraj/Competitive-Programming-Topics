// primes
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<pair<int,int>> mat[N];
bool vis[N];

class cmp
{
    public:
           bool operator()(pair<int,int> a,pair<int,int> b)
           {
               return a.second > b.second;
           }
};
int  prims(int src)
{
   priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
   pq.push({src,0});
   int totalcost = 0;
   while(!pq.empty())
   {
       pair<int,int> papa = pq.top();
       int pnode = papa.first;
       int pcost = papa.second;
       if(vis[pnode]==false) 
       {
        totalcost += pcost;
        cout << pnode << " "<< pcost << endl;
       }
       pq.pop();
       vis[pnode]=true;
       for(pair<int,int> child:mat[pnode])
       {
           int cnode = child.first;
           int ccost = child.second;
           if(vis[cnode]==false)
           {
             pq.push({cnode,ccost});
           }
       }
       
   }
   return totalcost;
}

int main()
{
    int n,e;
    cin >> n >> e;
    while(e--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        mat[a].push_back({b,c});
        mat[b].push_back({a,c});
    }
    memset(vis,false,sizeof(vis));
    int totalcost = prims(1);
    // cout << totalcost << endl;

}

// input 

// 4 5
// 1 2 4
// 1 3 8
// 1 4 4
// 2 3 3
// 3 4 2

// output

// 1 0
// 2 4
// 3 3
// 4 2