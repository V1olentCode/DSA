// 4 ms | 26.5 MB
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> row_freq(m,0),col_freq(n,0);
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]) {
                    row_freq[i]++;
                    col_freq[j]++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] && (row_freq[i]>1 || col_freq[j]>1)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};