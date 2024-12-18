// O(N)+O(2E)
// O(3N)=O(N)
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &ls)
    {
        vis[node] = 1;
        ls.push_back(node);
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, adj, vis, ls);
            }
        }
    }

public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>> &adj)
    {
        // Code here
        int V = adj.size();

        // int *vis=new int[V]; yu bhi bna skte thee
        vector<int> vis(V, 0);
        int start = 0;  // node from where we wish to start dfs
        vector<int> ls; // list where answer will be stored
        for (i = start; i < V; i++)
        { // this is for dissconnected graph(graph which has more than 1 component)
            if (!vis[i])
                dfs(i, adj, vis, ls);
        }
        return ls;
    }
};

//{ Driver Code Starts.

// int main() {
//     int tc;
//     cin >> tc;
//     while (tc--) {
//         int V, E;
//         cin >> V >> E;

//         vector<vector<int>> adj(
//             V); // Use vector of vectors instead of array of vectors.

//         for (int i = 0; i < E; i++) {
//             int u, v;
//             cin >> u >> v;
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }

//         Solution obj;
//         vector<int> ans = obj.dfsOfGraph(adj);
//         for (int i = 0; i < ans.size(); i++) {
//             cout << ans[i] << " ";
//         }
//         cout << endl;
//         cout << "~" << endl;
//     }
//     return 0;
// }

// // } Driver Code Ends