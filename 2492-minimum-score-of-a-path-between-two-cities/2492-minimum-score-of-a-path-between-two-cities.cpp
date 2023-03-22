class Solution {
public:
    
    int bfs(vector<vector<pair<int, int>>>&adj, vector<bool>&vis, int n){
        int ans = INT_MAX;
        queue<int>q;
        
        q.push(1);
        vis[1] = true;
        
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            
            for(auto &i: adj[temp]){
                ans = min(ans, i.second);
                    if(!vis[i.first]){
                        vis[i.first] = true;
                        q.push(i.first);
                    }
                
            }
            
        }
        return ans;
    }
    
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>>adj(n+1);
        vector<bool>vis(n+1, false);
        for(auto &i: roads){
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        
        int ans = bfs(adj, vis, n);
        return ans;
        
    }
};