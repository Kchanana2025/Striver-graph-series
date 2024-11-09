// if a node finds a node that is visited but it is not the parent of node currently then cycle exists

#include <bits/stdc++.h>
using namespace std;

// T:O(V+2E)
//  AS:O(V)
//  TS:O(V)+O(V)
class Solution
{
public:
    bool bfs(int node, vector<int> &visited, vector<vector<int>> &adj)
    {
        visited[node] = 1; // it will be the first node the connected component we are taking about
        queue<pair<int, int>> pending_nodes;
        pending_nodes.push({node, -1});
        while (!pending_nodes.empty())
        {
            auto it = pending_nodes.front();
            int curr = it.first;
            int curr_par = it.second;
            pending_nodes.pop();
            for (auto curr_child : adj[curr])
            {
                if (!visited[curr_child])
                {
                    pending_nodes.push({curr_child, curr});
                    visited[curr_child] = 1;
                }
                else if (curr_child != curr_par)
                { // if it is visited and it is not parent of current node then definately true will be returned

                    return true;
                }
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>> &adj)
    {
        int V = adj.size();
        vector<int> visited(V, 0);

        for (int node = 0; node < V; node++)
        {
            if (!visited[node])
            {

                if (bfs(node, visited, adj) == true)
                    return true;
            }
        } // sabhi components ko visit krke bhi cycle nahi mili matlab cycle nahi hai

        return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends