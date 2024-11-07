// T:O(4(M*N))
//  time for BFS only
//  During BFS, each cell is visited at most once. For each cell, the algorithm checks its four neighbors (up, down, left, and right). Since each cell is processed exactly once and each edge (neighbor relationship) is also processed once, this step has a time complexity of
//  𝑂(𝑉+𝐸) , where V is the number of cells (𝑚×𝑛) and E is the number of edges.In this grid-based graph, there are roughly 4V edges (each cell has up to 4 neighbors), so O(V+E)=O(V+4V)=O(5V)=O(V), where
//  V=m×n.
// TS:4(M*N)
// AS:3(M*N)
class Solution
{

    void bfs(vector<vector<int>> &mat, vector<vector<int>> &ans, vector<vector<int>> &visited, queue<pair<pair<int, int>, int>> &pending)
    {
        int m = mat.size();
        int n = mat[0].size();
        while (!pending.empty())
        {
            auto it = pending.front();
            pending.pop();
            int row = it.first.first;
            int col = it.first.second;
            int step = it.second;
            ans[row][col] = step;

            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && visited[nrow][ncol] != 1 && mat[nrow][ncol] == 1)
                {
                    pending.push({{nrow, ncol}, step + 1});
                    visited[nrow][ncol] = 1;
                }
            }
        }
    }

public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> pending;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (mat[i][j] == 0)
                {
                    visited[i][j] = 1; // ans[i][j] mein zero daalne ki need hai because it is originally initialized to zero
                    pending.push({{i, j}, 0});
                }
            }
        }
        bfs(mat, ans, visited, pending);
        return ans;
    }
};