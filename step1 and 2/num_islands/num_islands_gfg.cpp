//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    void bfs(vector<vector<char>> &grid, vector<vector<int>> &vis, int i, int j)
    {
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = 1;
        int m = grid.size();
        int n = grid[0].size();
        while (!q.empty())
        {
            auto it = q.front();
            int fir = it.first;
            int sec = it.second;
            q.pop();

            for (int row = -1; row <= 1; row++)
            {
                for (int col = -1; col <= 1; col++)
                {
                    int nrow = row + fir;
                    int ncol = col + sec;

                    if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == '1' && vis[nrow][ncol] != 1)
                    {
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();    // no of rows
        int n = grid[0].size(); // no of columns

        vector<vector<int>> vis(m, vector<int>(n, 0)); // create a visited array
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!vis[i][j] && grid[i][j] == '1')
                {
                    ans++;
                    bfs(grid, vis, i, j);
                }
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';

        cout << "~" << "\n";
    }
    return 0;
}
// } Driver Code Ends