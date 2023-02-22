class Solution {
public:
    
    long long ans = 0;
    
    int dfs(vector<vector<int>>& adj, int u, int seats, vector<bool>& vis)
    {
      
        vis[u] = true;

        int count = 1;
        for(auto v : adj[u])
        {
            if(vis[v] == false)
            {
                count += dfs(adj, v, seats, vis);
            }
        }
        
        if(u != 0)
        {
            ans += ceil((double) count / seats);
        }
        
        return count;
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        
        int n = roads.size();

        vector<vector<int>> adj(n + 1);

        for(int i = 0; i < n; i++)
        {
            int u = roads[i][0];
            int v = roads[i][1];
            
            adj[u].push_back(v); 
            adj[v].push_back(u);
        }
        
        vector<bool> vis(n + 1, false);

        dfs(adj, 0, seats, vis);
        
        return ans;
    }
};