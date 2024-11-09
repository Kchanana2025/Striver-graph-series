// Time Complexity: O(N) + O(M) + O(M*N)+O(NxMx4)+O(M*N) ~ O(N x M), For the worst case, every element will be marked as ‘O’ in the matrix, and the DFS function will be called for (N x M) nodes and for every node, we are traversing for 4 neighbors, so it will take O(N x M x 4) time. Also, we are running loops for boundary elements so it will take O(N) + O(M).

// Aux Space Complexity ~O(n×m) (visited matrix)+O(n×m) (recursion stack)+O(n×m) (‘ans‘ matrix)=O(n×m)
// Total Space Complexity: O(n×m) (input matrix ‘mat‘)+O(n×m) (visited matrix)+O(n×m) (recursion stack)+O(n×m) (‘ans‘ matrix)=O(n×m)

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
// firstly jo bhi region of 0's mein ek bhi 0 boundary pe nahi hai matlab wo completly X se
// surrounded hai that means it's 0's can be replaced by X's

// so basically algo ye hai ki boundary pe jo 0's hain unse hm dfs chalaienge aur jo jo zero rste mein aeige means they wont be converted to X.
// convert the remaining 0's

class Solution
{
    void dfs(int row, int col, vector<vector<char>> &mat, vector<vector<int>> &visited)
    {
        int n = mat.size();
        int m = mat[0].size();
        visited[row][col] = 1;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && mat[nrow][ncol] == 'O' && visited[nrow][ncol] != 1)
                dfs(nrow, ncol, mat, visited);
        }
    }

public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<char>> ans(mat);

        vector<vector<int>> visited(n, vector<int>(m, 0));
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

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && mat[i][j] == 'O')
                {
                    ans[i][j] = 'X';
                }
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
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];

        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~" << "\n";
    }
    return 0;
}
// } Driver Code Ends