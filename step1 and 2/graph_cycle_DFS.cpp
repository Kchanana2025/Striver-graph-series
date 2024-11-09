//{ Driver Code Starts
#include <bits/stdc++.h>
// #include <iostr
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool dfs(int curr_node, int curr_parent, vector<vector<int>> &adj, vector<int> &visited)
    {
        visited[curr_node] = 1;
        for (auto child : adj[curr_node])
        {
            if (!visited[child])
            {
                if (dfs(child, curr_node, adj, visited) == true)
                    return true;
            }
            else if (child != curr_parent)
            {
                return true;
            }
        }
        return false; // isko yu hi likh dia hai taki hr area mein kuch value return ho lekin yaha false likhne se doesnt prove ki cycle nahi hai ,ecause cycle kisi aur component mein bhi ho skti hai.
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>> &adj)
    {
        // Code here
        int V = adj.size();
        vector<int> visited(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, -1, adj, visited) == true)
                    return true;
            }
        }
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
        cout << "~"
             << "\n";
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