// time:O(M)+O(N)+O(4(M*N))+O(M*N)=O(M*N)
// AS:O(M*N)(vis)+O(M*N)(rec)
// TS:O(M*N)(vis)+O(M*N)(rec)+O(m*n)(grid)

// bfs mein queue mein daalte hi vist mark kr dia krow aur dfs meindfs function start hote hi mark kr dia kro visited
class Solution
{
private:
    void dfs(int row, int col, vector<vector<int>> &visited, vector<vector<int>> &grid)
    {
        int m = visited.size();
        int n = visited[0].size();
        visited[row][col] = 1;
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && grid[nrow][ncol] == 1 && !visited[nrow][ncol])
            {
                // visited[nrow][ncol]=1;//no need
                dfs(nrow, ncol, visited, grid);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int counter = 0;
        for (int j = 0; j < n; j++)
        {
            if (grid[0][j] == 1 && !visited[0][j])
            {
                dfs(0, j, visited, grid); // first and last row
            }
            if (grid[m - 1][j] == 1 && !visited[m - 1][j])
            {
                dfs(m - 1, j, visited, grid);
            }
        }

        for (int i = 0; i < m; i++)
        {
            if (grid[i][0] == 1 && !visited[i][0])
            { // first and last column
                dfs(i, 0, visited, grid);
            }
            if (grid[i][n - 1] == 1 && !visited[i][n - 1])
            {
                dfs(i, n - 1, visited, grid);
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && !visited[i][j])
                {
                    counter++;
                }
            }
        }
        return counter;
    }
};