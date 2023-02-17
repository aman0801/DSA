class Solution {
public:
    
    void dfs(int node, int parent, int timer, vector<int>&dist, vector<int>&low, vector<vector<int>>&ans, unordered_map<int, list<int> >&adj, unordered_map<int, bool>&vis){
        vis[node] = true;
        dist[node] = low[node] = timer++;
        for(auto nbr: adj[node]){
            if(nbr == parent){
                continue;
            }
            if(!vis[nbr]){
                dfs(nbr, node, timer, dist, low, ans, adj, vis);
                low[node] = min(low[node], low[nbr]);
                
                if(low[nbr] > dist[node]){
                    vector<int>temp;
                    temp.push_back(node);
                    temp.push_back(nbr);
                    ans.push_back(temp);
                }
                
            }else{
                low[node] = min(low[node], dist[nbr]);
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int, list<int> >adj;
        vector<vector<int>>ans;
        for(int i=0; i<connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int timer = 0;
        vector<int>dist(n, -1);
        vector<int>low(n, -1);
        int parent = -1;
        unordered_map<int, bool>vis;
        
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i, parent, timer, dist, low, ans, adj, vis);
                // cout<<ans[i][0];
            }
        }
        return ans;
    }
};