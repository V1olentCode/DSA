// 161 ms | 200 MB
class Solution {
public:
    int bfs(vector<vector<int>>& grid, int k,int r,int c,int n, int m) {
        long long sum=grid[r][c];
        queue<pair<int,int>> q;
        grid[r][c]=0;
        q.push({r,c});
        while(!q.empty()) {
            auto [r,c]=q.front();
            q.pop();
            int dr[4]={-1,0,1,0};
            int dc[4]={0,-1,0,1};
            for(int i=0;i<4;i++) {
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]>0) {
                    sum+=grid[nr][nc];
                    grid[nr][nc]=0;
                    q.push({nr,nc});
                }
            }
        }
        if(sum%k==0) return 1;
        return 0;

    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]>0) {
                    ans+=bfs(grid,k,i,j,n,m);
                }
            }
        }
        return ans;
    }
};