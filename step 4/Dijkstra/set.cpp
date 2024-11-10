//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User Function Template
// The only difference between using a Priority Queue and a Set is that in a set we can check if there exists a pair with the same node but a greater distance than the current inserted node as there will be no point in keeping that node into the set if we come across a much better value than that. So, we simply delete the element with a greater distance value for the same node.
// O(ElogV)
// O(V)
// O(V+E)
class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src)
    {
        int N = adj.size();
        vector<int> dist(N, 1e9); // we want min distances of src node to all nodes isliye hi
        // we put 1e9 into it(a max value)
        dist[src] = 0;

        // set stores values in ascending order
        set<pair<int, int>> st; // distance from src,that node
        // st.push({0,src});
        st.insert({0, src});

        while (!st.empty())
        {
            auto it = *(st.begin()); // it will give first value in the set
            int dis = it.first;
            int node = it.second;
            st.erase(it);

            for (auto x : adj[node])
            {
                int edgeW = x.second; // ye first aur second dhyan se do first is node and second is edgeweight
                int adjNode = x.first;

                if (dist + edgeW < dist[adjNode])
                {

                    if (dist[adjNode] != 1e9)
                        st.erase({dist[adjNode], adjNode});

                    dist[adjNode] = dis + edgeW;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        vector<int> ans(N, -1);
        for (int i = 0; i < N; i++)
        {
            if (dist[i] != 1e9)
                ans[i] = dist[i];
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends