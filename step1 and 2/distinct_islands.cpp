// ts:O(n*m)+log(n*m)+O(4*m*n)
// as:O(3*n*m)
// ts:O(4*n*m)
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
// if we can store shapes into set data structure then uske baad jitne bhi elements
// set mein honge utne distinct islands honge

// follow ek hi order matlab agar  left to right order follow kr rhe ho toh
//  matlab wohi order follow kro taki agle indexes ko base index se ghatao toh dikkat na aaye

void dfs(vector<vector<int>> &grid, vector<vector<int>> &visited, int row, int col, vector<pair<int, int>> &vec, int row0, int col0)
{
    int m = grid.size();
    int n = grid[0].size();
    visited[row][col] = 1;
    vec.push_back({row - row0, col - col0});
    int delrow[4] = {-1, 0, 1, 0};
    int delcol[4] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && grid[nrow][ncol] == 1 && !visited[nrow][ncol])
            {
                dfs(grid, visited, nrow, ncol, vec, row0, col0);
            }
        }
    }
}

int countDistinctIslands(vector<vector<int>> &grid)
{
    // code here
    int m = grid.size(); // no of rows
    int n = grid[0].size();
    set<vector<pair<int, int>>> shapes; // this set will store shapes in form of indexes
    // hm vector of pairs ka set bna bhi ni skte
    vector<vector<int>> visited(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (grid[i][j] && !visited[i][j])
            {
                vector<pair<int, int>> vec;
                dfs(grid, visited, i, j, vec, i, j);
                shapes.insert(vec);
            }
        }
    }
    return shapes.size();
}

//{ Driver Code Starts.

int main()
{
    // vector<vector<int>> grid = {{1, 1, 1, 0}, {1, 0, 0, 0}, {0, 1, 1, 1}, {1, 1, 1, 1}};
    vector<vector<int>> grid;
    int m, n;
    cout << "enter rows and columns";
    cin >> m >> n;
    int x;

    for (int i = 0; i < m; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            cout << "enter ele";
            cin >> x;
            temp.push_back(x);
        }
        grid.push_back(temp);
    }
    cout << countDistinctIslands(grid);
}

// } Driver Code Ends