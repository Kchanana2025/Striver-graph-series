class Solution
{
public:
    void dfs(int node, vector<int> adj[], vector<int> &visited)
    {
        visited[node] = 1;
        for (auto it : adj[node])
        {
            if (!visited[it])
                dfs(it, adj, visited);
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        // first lets convert adjancy matrix to adjancy list
        int V = isConnected.size();
        vector<int> visited(V, 0);
        vector<int> adj[V];

        for (int i = 0; i < V; i++)
        { // creation of adjancy list
            for (int j = 0; j < V; j++)
            {
                if (isConnected[i][j] == 1 && i != j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int ans = 0;

        for (int i = 0; i < V; i++)
        { // traversing over adjancy list and calling dfs over each unvisited node
            if (!visited[i])
            {
                ans++;
                dfs(i, adj, visited);
            }
        }

        return ans;
    }
};