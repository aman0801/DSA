class Solution {
public:
    int n;
    void dfs(unordered_map<int, vector<int>>&adj, vector<bool>&vis, int node){
        vis[node] = true;
        
        for(auto &v:adj[node]){
            if(!vis[v]){
                dfs(adj, vis, v);
            }
        }
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        vector<bool>vis(n, false);
        int count = 0;
        unordered_map<int, vector<int>>adj;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(adj, vis, i);
                count++;
            }
        }
        return count;
    }
};