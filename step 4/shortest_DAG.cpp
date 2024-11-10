// Graph Construction:

// The code builds an adjacency list from the input edges vector.
// This takes O(E) time, where
// 𝐸
// E is the number of edges.
// Topological Sort:

// The topoSort function is called for each unvisited node.
// In a DAG, each node and edge is visited once during the topological sort, giving a time complexity of O(V + E), where
// 𝑉
// V is the number of vertices.
// Shortest Path Calculation:

// After obtaining the topological sort, each node is processed in order. For each node, the algorithm iterates through its adjacent nodes to update distances.
// This step also has a time complexity of O(V + E), as each edge and node is processed once.
// thereforce total O(V+E)

// Space Complexity
// Graph Representation: The adjacency list requires O(V + E) space.
// Auxiliary Data Structures:
// visited vector: O(V).
// stack for topological sort: O(V).
// distance and ans vectors: O(V) each.
// Thus, the space complexity is O(V + E).

// Notes:Intuition:
// Finding the shortest path to a vertex is easy if you already know the shortest paths to all the vertices that can precede it. Processing the vertices in topological order ensures that by the time you get to a vertex, you've already processed all the vertices that can precede it which reduces the computation time significantly. In this approach, we traverse the nodes sequentially according to their reachability from the source.

// Dijkstra's algorithm is necessary for graphs that can contain cycles because they can't be topologically sorted. In other cases, the topological sort would work fine as we start from the first node, and then move on to the others in a directed manner.

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
    void topoSort(int node, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &st)
    {
        // This is the function to implement Topological sort.
        vis[node] = 1;
        for (auto it : adj[node])
        {
            int v = it.first;
            if (!vis[v])
            {
                topoSort(v, adj, vis, st);
            }
        }
        st.push(node);
    }

public:
    vector<int> shortestPath(int V, int E, vector<vector<int>> &edges)
    {

        // lets first create a graph
        vector<pair<int, int>> adj[V]; // we will push node along with weight of the edge
        for (int i = 0; i < E; i++)
        {
            int u = edges[i][0];  // first vertex
            int v = edges[i][1];  // second vertex
            int wt = edges[i][2]; // weight on the edge

            adj[u].push_back({v, wt});
        }
        // lets find topological sort of graph

        vector<int> vis(V, 0);
        stack<int> st;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                topoSort(i, adj, vis, st);
            }
        }

        // learn both of these lines
        vector<int> distance(V, 1e9);
        distance[0] = 0;

        while (!st.empty())
        {
            auto node = st.top();

            st.pop();

            for (auto x : adj[node])
            {
                int val = x.first;
                int dist = x.second;
                if (distance[node] + dist < distance[val])
                {
                    distance[val] = distance[node] + dist;
                }
            }
        }

        vector<int> ans(V, -1);
        for (int i = 0; i < V; i++)
        {
            if (distance[i] != 1e9)
                ans[i] = distance[i];
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends