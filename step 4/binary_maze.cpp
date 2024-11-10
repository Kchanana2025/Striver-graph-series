//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// if in question is not given that moving from one cell to another takes how much weight
// take it as 1
// also if weights are constant like here->1 then you can use queue ,no need to use priority queue
// because values apne aap ascending order mein hi store hongi

// hm answer aate hi return ho rhe hai sabhi possibilities check nahi kr rhe because wo zyada hi ayengi socho
// because agar distance=1 pe answer aa gya aage toh distance 1 se zyada hi hoga and hamien shortest distance
//  hi chahie toh isiliye hm ussi smay return kr dege

// Time Complexity: O(m×n)
// Space Complexity: O(m×n)
class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination)
    {
        int m = grid.size();
        int n = grid[0].size();

        // if(source.first==destination.first && source.second==destination.second)return 0;

        if (source == destination)
        {
            return 0;
        }
        if (grid[source.first][source.second] == 0 || grid[destination.first][destination.second] == 0)
        {
            return -1;
        }

        vector<vector<int>> distance(m, vector<int>(n, 1e9));
        distance[source.first][source.second] = 0;

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {source.first, source.second}});

        int delrow[4] = {-1, 0, 0, +1};
        int delcol[4] = {0, 1, -1, 0};

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int dist = it.first;
            int row = it.second.first;
            int col = it.second.second;

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1)
                {
                    if (dist + 1 < distance[nrow][ncol])
                    {
                        distance[nrow][ncol] = dist + 1;

                        if (nrow == destination.first && ncol == destination.second)
                            return dist + 1;
                        q.push({dist + 1, {nrow, ncol}});
                    }
                }
            }
        }
        return -1;
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
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;

        cout << "~" << "\n";
    }
}

// } Driver Code Ends