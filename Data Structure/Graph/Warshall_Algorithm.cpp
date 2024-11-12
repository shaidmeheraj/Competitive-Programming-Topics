#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int> adjList[N];

void addEdge(int u, int v) {
    adjList[u].push_back(v);
}

void displayAdjList(int numNodes) {
    cout << "\nAdjacency List:" << endl;
    for (int i = 0; i < numNodes; i++) {
        cout << i << " -> ";
        for (int neighbor : adjList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

bool searchEdge(int u, int v) {
    for (int neighbor : adjList[u]) {
        if (neighbor == v) return true;
    }
    return false;
}

void initializeGraph(int numNodes) {
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(0, 3);
    addEdge(3, 2);
    addEdge(3, 4);
    addEdge(4, 3);
    addEdge(4, 2);
}

void addExtraNodeAndEdge() {
    int u, v;
    cout << "Enter the source node for the extra edge: ";
    cin >> u;
    cout << "Enter the destination node for the extra edge: ";
    cin >> v;
    addEdge(u, v);
}

void handleEdgeSearch() {
    int u_search, v_search;
    cout << "\nEnter the source node of the edge to search: ";
    cin >> u_search;
    cout << "Enter the destination node of the edge to search: ";
    cin >> v_search;

    if (searchEdge(u_search, v_search)) {
        cout << "The directed edge (" << u_search << " -> " << v_search << ") exists in the graph." << endl;
    } else {
        cout << "The directed edge (" << u_search << " -> " << v_search << ") does not exist in the graph." << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    const int numNodes = 5;

    initializeGraph(numNodes);
    displayAdjList(numNodes);

    addExtraNodeAndEdge();
    displayAdjList(numNodes);

    handleEdgeSearch();

    return 0;
}
