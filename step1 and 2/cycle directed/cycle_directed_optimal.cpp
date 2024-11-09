// we did this this question in a single visited array

// T:O(V+2E)
// AS:O(V)
// TS:O(2V)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &visited)
    {
        visited[node] = 2; // Mark as part of the current DFS path

        for (auto it : adj[node])
        {
            if (visited[it] == 0)
            { // If the node is unvisited, recurse
                if (dfs(it, adj, visited))
                    return true;
            }
            else if (visited[it] == 2)
            { // Node is in the current path, so a cycle is detected
                return true;
            }
        }

        visited[node] = 1; // Mark as processed and no longer in the current path
        return false;
    }

    bool isCyclic(int V, vector<vector<int>> &adj)
    {
        vector<int> visited(V, 0); // Initialize all nodes as unvisited

        for (int i = 0; i < V; i++)
        {
            if (visited[i] == 0)
            { // If the node is unvisited, start DFS
                if (dfs(i, adj, visited))
                    return true;
            }
        }

        return false; // No cycle found after checking all nodes
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
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

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
