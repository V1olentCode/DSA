// 346 ms | 62.1 MB
class Solution {
public:
    int ans = INT_MAX;
    vector<vector<vector<bool>>> dp;

    void rec(vector<vector<int>>& grid, int x, int i, int j) {
        x^=grid[i][j];

        if(dp[i][j][x]) return;
        dp[i][j][x] = true;

        if(i==grid.size()-1&&j==grid[0].size()-1) {
            ans=min(ans,x);
            return;
        }

        if (i+1<grid.size()) rec(grid, x, i + 1, j);
        if (j+1<grid[0].size()) rec(grid, x, i, j + 1);
    }

    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        dp.assign(m, vector<vector<bool>>(n, vector<bool>(1024, false)));
        rec(grid, 0, 0, 0);
        return ans;
    }
};