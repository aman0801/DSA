class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>>adj(n);
        
        for (auto& redE : redEdges) {
            adj[redE[0]].push_back({redE[1], 0});
        }
        for (auto& blueE : blueEdges) {
            adj[blueE[0]].push_back(make_pair(blueE[1], 1));
        }
        
        vector<int>ans(n,-1);
        vector<vector<bool>>vis(n, vector<bool>(2));
        
        queue<vector<int>>q;
        
        q.push({0,0,-1});
        vis[0][1] = vis[0][0] = true;
        ans[0] = 0;
        while(!q.empty()){
            auto temp = q.front();
            
            int node = temp[0];
            int steps = temp[1];
            int prevC = temp[2];
            q.pop();
            
            for(auto& [nei, col] : adj[node]){
                if(!vis[nei][col] && col!=prevC){
                    vis[nei][col] = true;
                    q.push({nei, 1+steps, col});
                    
                    if(ans[nei] == -1) ans[nei] = 1 + steps;
                    
                }
            }
        }
        return ans;
    }
};