// 2 ms | 16.7 MB
class Solution {
public:
    int bfs(vector<vector<int>> &grid,int r,int c,int m,int n) {
        queue<pair<int,int>> q;
        bool valid=true;
        grid[r][c]=1;
        q.push({r,c});
        while(!q.empty()) {
            auto [row,col]=q.front();
            q.pop();

            if(row==0 || row==m-1 || col==0 || col==n-1) valid=false;

            int dr[4]={-1,0,1,0};
            int dc[4]={0,-1,0,1};
            for(int i=0;i<4;i++) {
                int nr=row+dr[i];
                int nc=col+dc[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==0) {
                    grid[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
        if(valid) return 1;
        return 0;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=1;i<m-1;i++) {
            for(int j=1;j<n-1;j++) {
                if(grid[i][j]==0) {
                    ans+=bfs(grid,i,j,m,n);
                }
            }
        }
        return ans;
    }   
};