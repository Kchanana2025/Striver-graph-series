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
        // Direction vectors for up, down, left, and right movements
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty())
        {
            auto it = q.front();
            int fir = it.first;
            int sec = it.second;
            q.pop();

            // Loop through the four cardinal directions
            for (int k = 0; k < 4; k++)
            {
                int nrow = fir + directions[k][0];
                int ncol = sec + directions[k][1];

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == '1' && vis[nrow][ncol] != 1)
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
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