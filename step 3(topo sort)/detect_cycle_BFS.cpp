#include <bits/stdc++.h>
using namespace std;

// intuition behind this is that topological sort can be calculated only in DAG(Directed Acyclic Graph)
// if Length of topological sort<no of vertices that means cycle exists in grpah and if
//  length of top sort=V graph doesnt contain cycle
// O(2V)+O(V+E)
// O(2V)
//  O(2V)+O(V+E)
class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj)
    {
        // code here
        // Your code here

        queue<int> q;
        int counter = 0;
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
            counter++;
            for (auto x : adj[it])
            {
                indegree[x]--;
                if (indegree[x] == 0)
                {
                    q.push(x);
                }
            }
        }
        if (counter == V)
            return false;
        return true;
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

        cout << "~"
             << "\n";
    }

    return 0;
}