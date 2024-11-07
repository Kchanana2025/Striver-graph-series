class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        // always initialize all variables shuru mein hi,code ke beech mein nahi
        int m = grid.size();
        int n = grid[0].size();
        int tm = 0;    // max time
        int cnt = 0;   // keeps count of fresh oranges
        int count = 0; // keeps track of how many times a grid element's indexes are pushed into the queue

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
                if (grid[i][j] == 1)
                {
                    cnt++;
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

                    count++;
                    q.push({{nrow, ncol}, ti + 1});
                    vis[nrow][ncol] = 2;
                }
            }
        }

        // if(cnt==tm) ye nahi hoga think why
        if (cnt == count)
        {
            return tm;
        }
        return -1;
    }
};