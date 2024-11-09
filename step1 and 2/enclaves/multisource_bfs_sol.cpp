// Multisource BFS (Breadth-First Search) is an extension of the traditional Breadth-First Search algorithm used to find the
// shortest path or minimum distance from multiple starting nodes (or sources) to other nodes in a graph, grid, or network.
// Instead of initializing the BFS from a single source node, multisource BFS initializes the search from multiple nodes simultaneously.
// Applications
// Shortest distance in grids: Find the minimum steps from multiple starting points to other points in a grid (e.g., the nearest water source for each land cell).
// Flood fill with multiple sources: Used in scenarios where you want to fill regions from multiple starting points simultaneously.
// Social networks: Finding distances in a network graph, like the minimum "friendship path" from multiple influencers to other users.

// O(M)+O(N)+O(4*(M*N))+O(M*N)
// AS:O(M*N)+O(M*N)
//  TS:3*O(M*N)

void bfs(vector<vector<int>> &grid, queue<pair<int, int>> &pending_nodes, vector<vector<int>> &visited)
{
    int delrow[4] = {-1, 0, 1, 0};
    int delcol[4] = {0, 1, 0, -1};
    int m = grid.size();
    int n = grid[0].size();

    while (!pending_nodes.empty())
    {
        auto it = pending_nodes.front();
        int row = it.first;
        int col = it.second;
        pending_nodes.pop();

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1 && !visited[nrow][ncol])
            {
                visited[nrow][ncol] = 1;
                pending_nodes.push({nrow, ncol});
            }
        }
    }
}

int numEnclaves(vector<vector<int>> &grid)
{
    queue<pair<int, int>> pending_nodes;

    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> visited(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    { // push 1's first column and last column into the grid
        if (grid[i][0])
        {
            pending_nodes.push({i, 0});
            visited[i][0] = 1;
        }
        if (grid[i][n - 1])
        {
            pending_nodes.push({i, n - 1});
            visited[i][n - 1] = 1;
        }
    }
    for (int j = 0; j < n; j++)
    {
        if (grid[0][j])
        {
            pending_nodes.push({0, j});
            visited[0][j] = 1;
        }
        if (grid[m - 1][j])
        {
            pending_nodes.push({m - 1, j});
            visited[m - 1][j] = 1;
        }
    }

    bfs(grid, pending_nodes, visited);
    int counter = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] && !visited[i][j])
            {
                counter++;
            }
        }
    }
    return counter;
}
int main()
{
    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}};
    int result = numEnclaves(grid);
    cout << "Number of enclaves: " << result << endl;
    return 0;
}
