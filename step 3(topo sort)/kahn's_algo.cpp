
#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(2V)+O(V+E), where V = no. of nodes and E = no. of edges. This is a simple BFS algorithm.

// Aux Space Complexity: O(N) + O(N) ~ O(2N), O(N) for the indegree array, and O(N) for the queue data structure used in BFS(where N = no.of nodes).
// TS:O(2V)+O(V+E)

// Function to return list containing vertices in Topological order.
vector<int> topologicalSort(vector<vector<int>> &adj)
{
    // Your code here
    int V = adj.size();
    queue<int> q;
    vector<int> ans;
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
            indegree[it]++;
    }

    for (int i = 0; i < indegree.size(); i++)
    {
        if (indegree[i] == 0)
        { // nodes whoes indegree is zero must be pushed into the queue
            q.push(i);
        }
    }

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        ans.push_back(it);
        for (auto x : adj[it])
        {
            indegree[x]--;
            if (indegree[x] == 0)
            {
                q.push(x);
            }
        }
    }
    return ans;
}

int main()
{
    int V, E;
    cin >> E >> V;
    vector<vector<int>> adj(V);
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> ans = topologicalSort(adj);
    for (auto i : ans)
    {
        cout << i;
    }

    return 0;
}
// } Driver Code Ends