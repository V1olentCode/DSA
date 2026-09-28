// 0 ms | 19.2 MB
class Solution {
public:
    void DFS(int node, vector<vector<int>> &adj, vector<bool> &visited) {
        visited[node] = true;

        for(int c = 0; c < adj.size(); c++) {
            if(adj[node][c] == 1 && !visited[c]) {
                DFS(c, adj, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &adj) {
        int V=adj.size();
        vector<bool>visited(V,false);
        int count=0;
        for(int i=0;i<V;i++) {
            if(!visited[i]) {
                DFS(i, adj, visited);
                count++;
            }
        }
        return count;
    }
};