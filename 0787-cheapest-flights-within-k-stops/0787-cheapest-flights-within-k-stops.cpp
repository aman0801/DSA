class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>>mp;
        for(vector<int>&temp : flights){
            int u = temp[0];
            int v = temp[1];
            int cost = temp[2];
            
            mp[u].push_back({v, cost});
        }
        
        vector<int>dist(n, INT_MAX);
        
        queue<pair<int, int>>q;
        q.push({src, 0});
        dist[src] = 0;
        int count = 0;
        
        while(!q.empty() && count<=k){
            int N = q.size();
            
            while(N--){
                int u = q.front().first;
                int d = q.front().second;
                
                q.pop();
                
                for(pair<int, int>&P : mp[u]){
                    int v = P.first;
                    int cost = P.second;
                    
                    if(dist[v] >= d + cost){
                        dist[v] = d+cost;
                        
                        q.push({v, d+cost});
                    }
                }
            }
            count++;
        }
        return dist[dst] == INT_MAX ? -1:dist[dst];
        
    }
};