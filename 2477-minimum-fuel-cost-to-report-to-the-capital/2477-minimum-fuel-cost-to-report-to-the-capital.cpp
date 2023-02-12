class Solution {
public:
    
    long long bfs(vector<vector<int> >&adj, vector<int>&degree, int s, int n){
        queue<int>q;
        for(int i=1; i<n; i++){
            if(degree[i] == 1){
                q.push(i);
            }
        }
        
        vector<int>representatives(n, 1);
        long long fuel = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            fuel += ceil((double)representatives[node] / s);
            
            for(auto &nei: adj[node]){
                degree[nei]--;
                representatives[nei] += representatives[node];
                
                if(degree[nei] == 1 && nei != 0){
                    q.push(nei);
                }
            }
        }
        return fuel;
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size()+1; //total no. nodes in tree
        vector<vector<int> >adj(n);
        vector<int>degree(n);
        for(auto &road: roads){
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
            
            degree[road[0]]++;
            degree[road[1]]++;
        }
        
        return bfs(adj, degree, seats, n);
        
    }
};