#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Edge
{
    int source, destination, weight;
};

vector<int> bellmanFord(int n, int source, vector<Edge> &edges)
{
    vector<int> dist(n, INF); // 1st initialize all node as infinity
    dist[source] = 0;

    // Relax all edges (n - 1) times
    for (int i = 0; i < n - 1; i++)
    {
        for (const auto &edge : edges)
        {
            if (dist[edge.source] != INF && dist[edge.source] + edge.weight < dist[edge.destination])
            {
                dist[edge.destination] = dist[edge.source] + edge.weight; // notice
            }
        }
    }

    // Check for negative-weight cycles
    for (const auto &edge : edges)
    {
        if (dist[edge.source] != INF && dist[edge.source] + edge.weight < dist[edge.destination])
        {
            cout << "Graph contains a negative-weight cycle" << endl;
            return {}; // Return an empty vector if a negative cycle is detected
        }
    }

    return dist;
}

int main()
{
    int n, e;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> e;

    vector<Edge> edges(e); // Edge
    cout << "Enter each edge (source, destination, weight):" << endl;
    for (int i = 0; i < e; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }

    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    vector<int> distance = bellmanFord(n, src, edges);

    if (!distance.empty())
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Distance from " << src << " to " << i << ": "
                 << (distance[i] == INF ? -1 : distance[i]) << endl;
        }
    }

    return 0;
}

// Enter the number of vertices and edges: 5 8
// Enter each edge (source, destination, weight):
// 0 1 -1
// 0 2 4
// 1 2 3
// 1 3 2
// 1 4 2
// 3 2 5
// 3 1 1
// 4 3 -3
// Enter the source vertex: 0

// Distance from 0 to 0: 0
// Distance from 0 to 1: -1
// Distance from 0 to 2: 2
// Distance from 0 to 3: -2
// Distance from 0 to 4: 1