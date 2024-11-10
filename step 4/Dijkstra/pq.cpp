// This complexity arises because:
// Processing each edge and performing priority queue updates takes
// O(ElogV) in the worst case.
// Summary
// Time Complexity:O(ElogV)
// Space Complexity: O(V) for storing distances and priority queue.

#include <bits/stdc++.h>
using namespace std;

// Function to find the shortest distance of all the vertices
// from the source vertex src.
vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src)
{
    // Code here
    int V = adj.size();
    vector<int> distance(V, 1e9);
    distance[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty())
    {
        auto it = pq.top();
        int dis = it.first;
        int node = it.second;
        pq.pop();
        for (auto x : adj[node])
        {
            int adjacentNode = x.first;
            int weight = x.second;
            if (distance[node] + weight < distance[adjacentNode])
            {
                distance[adjacentNode] = distance[node] + weight;
                pq.push({distance[adjacentNode], adjacentNode});
            }
        }
    }
    return distance;
}

int main()
{
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<pair<int, int>>> adj(V);

    cout << "Enter the edges (u, v, w) where u and v are nodes and w is the weight:\n";
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // If the graph is directed, remove this line
    }

    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    vector<int> distances = dijkstra(adj, src);

    cout << "Shortest distances from node " << src << " to all other nodes:\n";
    for (int i = 0; i < V; i++)
    {
        if (distances[i] == 1e9)
            cout << "Node " << i << ": Unreachable\n";
        else
            cout << "Node " << i << ": " << distances[i] << "\n";
    }

    return 0;
}
// run this for:-
//  Enter the number of vertices and edges: 6
//  8
//  Enter the edges (u, v, w) where u and v are nodes and w is the weight:
//  0 1 4
//  0 2 4
//  1 2 2
//  2 3 3
//  2 5 6
//  2 4 1
//  4 5 3
//  3 5 2
//  Enter the source vertex: 0