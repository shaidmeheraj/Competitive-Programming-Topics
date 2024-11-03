#include <bits/stdc++.h>
#include <vector>
using namespace std;
const int N = 1e5 + 5;
const int INF = 1e9;
vector<pair<int, int>> v[N];

vector<int> dijkstra(int source, int n)
{
    vector<int> dist(n, INF); // prottekta n infinity korechi

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[source] = 0;
    pq.push({0, source}); // pair dekhe {} use hoise

    while (!pq.empty())
    {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (d > dist[node])
            continue;

        for (auto child : v[node])
        {
            int next = child.first;
            int weight = child.second;

            if (dist[node] + weight < dist[next])
            {
                dist[next] = dist[node] + weight;
                pq.push({dist[next], next}); // pair
            }
        }
    }
    return dist;
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--) // notice
    {
        int a, b, w;
        cin >> a >> b >> w;
        v[a].push_back({b, w}); // pair dekhe {}
        v[b].push_back({a, w});
    }

    int src;
    cin >> src;
    vector<int> distance = dijkstra(src, n);

    for (int i = 0; i < n; i++)
    {
        cout << "distance " << src << " to " << i << " :" << (distance[i] == INF ? -1 : distance[i]) << endl;
    }
    return 0;
}
//input
// 5 6
// 0 1 2
// 0 2 4
// 1 2 1
// 1 3 7
// 2 4 3
// 3 4 2
// 0

// distance 0 to 0 :0
// distance 0 to 1 :2
// distance 0 to 2 :3
// distance 0 to 3 :9
// distance 0 to 4 :6