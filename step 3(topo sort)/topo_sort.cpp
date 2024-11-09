//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return list containing vertices in Topological order.
    // O(V+2E)
    // O(2V)
    // O(2V)+O(V+E)
    // initution is basically jaise hi kisi node ka dfs poora ho jata hai waise
    // hi hum usko stack mein daal dete hai taki sahi ordering follow ho
    void dfs(vector<vector<int>> &adj, int node, vector<int> &visited, stack<int> &st)
    {
        visited[node] = 1;
        for (auto it : adj[node])
        {
            if (!visited[it])
                dfs(adj, it, visited, st);
        }
        st.push(node);
    }
    vector<int> topologicalSort(vector<vector<int>> &adj)
    {
        int V = adj.size();
        vector<int> visited(V, 0);
        stack<int> st;
        vector<int> ans;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(adj, i, visited, st);
            }
        }

        while (!st.empty())
        { // never do this for stack for(int i=0;i<st.size();i++)
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<vector<int>> adj)
{

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++)
    {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<vector<int>> adj(N);

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topologicalSort(adj);

        cout << check(N, res, adj) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends