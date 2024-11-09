class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        // always initialize all variables shuru mein hi,code ke beech mein nahi
        int m = grid.size();
        int n = grid[0].size();
        int tm = 0; // max time

        // storing row col and time at which that row,col is reached
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0)); // create a visited 2D vector

        for (int i = 0; i < m; i++)
        { // initialize visited 2D vector with rotten oranges
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    vis[i][j] = 2;
                    q.push({{i, j}, 0});
                }
            }
        }
        while (!q.empty())
        {
            auto temp = q.front();
            q.pop();
            int row = temp.first.first;
            int col = temp.first.second;
            int ti = temp.second;
            tm = max(tm, ti);
            int delrow[] = {-1, 0, +1, 0};
            int delcol[] = {0, -1, 0, +1};

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2)
                {

                    q.push({{nrow, ncol}, ti + 1});
                    vis[nrow][ncol] = 2;
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && vis[i][j] != 2)
                {
                    return -1;
                }
            }
        }
        return tm;
    }
};