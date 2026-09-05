// 35 ms | 24.5 MB
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        >pq;
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        pq.push({0,{0,0}});

        while(!pq.empty()) {
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            int d=pq.top().first;
            pq.pop();
            int di[]={-1,0,1,0};
            int dj[]={0,-1,0,1};
            if(d > dist[i][j]) continue;
            if(i==n-1 && j==m-1) return d;
            for(int k=0;k<4;k++) {
                int newi=i+di[k];
                int newj=j+dj[k];
                if(newi<0 || newj<0 || newi>=n || newj>=m) continue;
                int curr_effort=max(d,abs(heights[i][j]-heights[newi][newj]));
                if(curr_effort<dist[newi][newj]) {
                    dist[newi][newj]=curr_effort;
                    pq.push({curr_effort,{newi,newj}});
                }
            }
        }
        return -1;
    }
};