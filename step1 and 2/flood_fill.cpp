// O(X)+O(4*X)=O(X)=O(N*M)(X denotes no of nodes jinpe DFS call hua)
// as:O(N*M)+O(N*M)
// Ts:O(N*M)+O(N*M)+O(N*M)

// bina baat ke kisi ko by refernce pass mat kia kar kalesh hota hai
// isme visited array ki need nahi hai because color hua hai ya nahi ussi se pta lag jayega ki wo cell visited hai ya nahi
class Solution
{
private: // extra functions should always be created in private
    // we send vectors by reference so that original answers are sent in function and not their copies
    void dfs(vector<vector<int>> &image, int sr, int sc, int &initialColor, int &color, int directions[4][2], vector<vector<int>> &ans)
    {
        int m = image.size();
        int n = image[0].size();
        ans[sr][sc] = color;
        for (int i = 0; i < 4; i++)
        {
            int newsr = sr + directions[i][0];
            int newsc = sc + directions[i][1];

            if (newsr >= 0 && newsr < m && newsc >= 0 && newsc < n && image[newsr][newsc] == initialColor && ans[newsr][newsc] != color)
            {
                ans[newsr][newsc] = color;
                dfs(image, newsr, newsc, initialColor, color, directions, ans);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int initialColor = image[sr][sc];
        if (initialColor == color)
            return image; // avoid unnecessary recursion if color is the same
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> ans = image; // you can copy like this also
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        dfs(image, sr, sc, initialColor, color, directions, ans);
        return ans;
    }
};