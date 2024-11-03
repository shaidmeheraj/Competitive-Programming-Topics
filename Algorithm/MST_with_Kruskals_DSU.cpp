//kruskals_with_DSU
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int par[N];
int level[N];
class Edge
{
    public: 
       int u,v,w;
       Edge(int x,int y,int z)
       {
         u=x;
         v=y;
         w=z;
       }
};
int dsu_find(int node)
{
    if(par[node]==-1) return node;
    int leader = dsu_find(par[node]);
    par[node]=leader;
    return leader;
}
void dsu_union_by_rank(int a,int b)// firt = c second = d
{
    int leaderA = dsu_find(a);//-1
    int leaderB = dsu_find(b);//c

    if(level[leaderA] < level[leaderB])
    {
        par[leaderA]=leaderB;
        level[leaderB]++;
    }
    else
    {
        par[leaderB]=leaderA;
        level[leaderA]++;
    }
}
bool cmp(Edge list1, Edge list2)
{
    return list1.w < list2.w;
}
int main()
{

  int n,e;
  cin >> n >> e;
  vector<Edge> list;
  while(e--)
  {
    int a,b,c;
    cin >> a >> b >> c;
    list.push_back(Edge(a,b,c));
  }
  sort(list.begin(),list.end(),cmp);
  memset(par,-1,sizeof(par));
  memset(level,0,sizeof(level));
  int totalcost = 0;
  for(Edge ed:list)
  {
    int ledA = dsu_find(ed.u);
    int ledB = dsu_find(ed.v);
    if(ledA == ledB) continue;
    else
    {
        dsu_union_by_rank(ed.u,ed.v);
        totalcost += ed.w;
        cout << ed.u << " " << ed.v << " " << ed.w << endl;

    }
  }
  // cout << totalcost << endl;
  
}
// input 
// 4 5
// 1 2 4
// 1 3 8
// 1 4 4
// 2 3 3
// 3 4 2

// ouput

// 3 4 2
// 2 3 3
// 1 2 4