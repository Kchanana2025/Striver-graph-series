// Time Complexity
// BFS Traversal: Since BFS explores each cell of the N×N grid only once, and each cell can have up to 8 moves (due to the knight's movement), the worst-case time complexity is 𝑂(𝑁2)
// Queue Operations: Each cell is pushed and popped from the queue only once, and processing each cell involves checking 8 possible moves, making this part 𝑂(8×𝑁2)=𝑂(𝑁2).Thus, the overall
// time complexity is:𝑂(𝑁2)
// Aux Space Complexity:Visited Matrix: A N×N matrix is used to keep track of visited cells, which requires 𝑂(𝑁2)2) space.
// Queue: In the worst case, the queue can hold up to 𝑁2 elements if all cells are visited, so the queue also requires O(N2) space.Therefore, the space complexity is:𝑂(𝑁2)
// T space complexity=Aux space complexity
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
    {
        vector<vector<int>> vis(N, vector<int>(N, 0));
        int startx = KnightPos[0] - 1;
        int starty = KnightPos[1] - 1;
        int targetx = TargetPos[0] - 1;
        int targety = TargetPos[1] - 1;
        if (startx == targetx && starty == targety)
            return 0;

        queue<pair<int, int>> q;
        q.push({startx, starty});
        vis[startx][starty] = 1;
        int level = 0;

        while (!q.empty())
        {
            int n = q.size();

            // Process all nodes at the current level
            while (n--)
            {
                pair<int, int> p = q.front();
                int row = p.first;
                int col = p.second;
                q.pop();
                // If we reached the target position
                if (row == targetx && col == targety)
                {
                    return level;
                }

                int delrow[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
                int delcol[8] = {1, 2, 2, 1, -1, -2, -2, -1};

                // Explore all knight moves
                for (int i = 0; i < 8; i++)
                {
                    int nrow = row + delrow[i];
                    int ncol = col + delcol[i];
                    if (nrow >= 0 && nrow < N && ncol >= 0 && ncol < N && !vis[nrow][ncol])
                    {
                        q.push({nrow, ncol});
                        vis[nrow][ncol] = 1;
                    }
                }
            }
            level++; // Increment level after processing the current layer
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        vector<int> KnightPos(2);
        vector<int> TargetPos(2);
        int N;
        cin >> N;
        cin >> KnightPos[0] >> KnightPos[1];
        cin >> TargetPos[0] >> TargetPos[1];
        Solution obj;
        int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
        cout << ans << "\n";

        cout << "~" << "\n";
    }
    return 0;
}
// } Driver Code Ends