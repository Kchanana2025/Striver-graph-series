//{ Driver Code Starts
// // O(N)+O(2E)
// // O(2N)
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> adj)
    {
        int V = adj.size();
        int vis[V] = {0};
        queue<int> q;

        vector<int> bfs;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                vis[i] = 1; // 0 ko islye mark kr rhe hain visited aur
                q.push(i);
                while (!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    bfs.push_back(node);

                    for (auto it : adj[node])
                    {
                        if (!vis[it])
                        {
                            vis[it] = 1;
                            q.push(it);
                        }
                    }
                }
            }
        }
        return bfs;
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

        // Now using vector of vectors instead of array of vectors
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.bfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends