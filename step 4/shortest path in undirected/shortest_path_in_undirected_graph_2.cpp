// O(M)+O(V+2E)+O(N)
// O(3N)
// O(3N)+O(M)

#include <bits/stdc++.h>
using namespace std;

// unit distance hi hai nodes ke beech mein isliye priority queue vgera use krne ki need nahi hai
// akele queue se bhi kaam chl jaega
class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
    {
        // lets first create graph
        vector<vector<int>> adj(N);
        for (int i = 0; i < M; i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        // learn both of these lines
        vector<int> distance(N, 1e9);
        distance[src] = 0;

        queue<int> q; // store node number
        q.push({src});

        while (!q.empty())
        {
            auto node = q.front();

            q.pop();
            for (auto x : adj[node])
            {

                if (distance[node] + 1 < distance[x])
                {
                    distance[x] = distance[node] + 1;
                    q.push({x});
                }
            }
        }
        vector<int> ans(N, -1);
        for (int i = 0; i < N; i++)
        {
            if (distance[i] != 1e9)
            {
                ans[i] = distance[i];
            }
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
            for (int j = 0; j < 2; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~" << "\n";
    }
}

// } Driver Code Ends