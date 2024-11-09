#include <bits/stdc++.h>
using namespace std;

// Function to detect cycle in a directed graph.
// in undirected graph we used that ki agar we visited an adjacent node
// and it is visited that means cycle exists in that graph
// But this logic wont work here

// i directed graph:in the same path node has to be visited again then we can say that it is a cycle

// T:O(V+2E)
// AS:O(2V)
// TS:O(3V)

// it can done from a single visited array as well by placing 1 in array(for visited) and 2 in array(for path visited)
bool dfs(int node, vector<vector<int>> adj, vector<int> &visited, vector<int> &path_visited)
{
    visited[node] = 1;
    path_visited[node] = 1;

    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            if (dfs(it, adj, visited, path_visited) == true)
                return true;
        }
        else if (path_visited[it])
        { // node has to be visited in the same path for cycle to exist
            return true;
        }
    }
    // Mark as processed and no longer in the current path
    path_visited[node] = 0; // hm visited array mein 0 nahi kr rhe hain because visit th ho chuka hai na ab traverse krte hue wo node wapis aayi toh kya point hai dobara visit krne ka  aur aage traverse krne ka jab phle traverse krke koi cycle nahi mili
    return false;
}
bool isCyclic(int V, vector<vector<int>> adj)
{
    int n = adj.size(); // no of vertices
    vector<int> visited(n, 0);
    vector<int> path_visited(n, 0);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, adj, visited, path_visited) == true)
                return true;
        }
    }
    return false; // if all nodes nodes are visited and cycle isnt found it means that it is not present and false must be returned
}

int main()
{

    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    cout << isCyclic(V, adj) << "\n";
}
