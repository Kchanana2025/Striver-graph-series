// O(N)+O(ElogV)

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// we need to print shortest path from 1 to n
// we need to remember where we are coming from while applying dijkstra

vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    // create distance vector
    vector<int> distance(n + 1, 1e9);
    distance[1] = 0;

    // create parent vector
    vector<int> parent(n + 1);
    for (int i = 0; i < n + 1; i++)
    { // remember to do this always
        parent[i] = i;
    }

    // create priority queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1}); // src node will need 0 distance to cover

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int dist = it.first;
        for (auto it : adj[node])
        {
            int adjN = it.first;
            int edgeW = it.second;
            if (dist + edgeW < distance[adjN])
            {
                distance[adjN] = dist + edgeW;
                parent[adjN] = node;
                pq.push({distance[adjN], adjN});
            }
        }
    }

    // lets determine path now

    if (distance[n] == 1e9)
        return {-1};

    int node = n;
    vector<int> fin_ans;
    while (parent[node] != node)
    {
        fin_ans.push_back(node);
        node = parent[node];
    }
    fin_ans.push_back(1);
    reverse(fin_ans.begin(), fin_ans.end());
    return fin_ans;
}

//{ Driver Code Starts.
int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(3));
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    vector<int> ans = shortestPath(n, m, edges);

    if (ans.size() == 1 && ans[0] == -1)
    {
        cout << -1 << endl;
    }
    else
    {
        for (auto node : ans)
        {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
