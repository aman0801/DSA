class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        vector<int>adjB[n];
        
        for(int i=0; i<connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];
            
             adj[u].push_back(v);
             adjB[v].push_back(u);
        }
        
         queue<int> q;
        q.push(0);
        
        vector<bool> visited(n , false);
        visited[0]=true;
        
        int ans=0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
             for(auto x : adj[node])
            {
                if(visited[x]==false)
                {
                    q.push(x);
                    visited[x]=true;
                    ans++;
                }
            }
            
             for(auto x : adjB[node])
            {
                if(visited[x]==false)
                {
                    q.push(x);
                    visited[x]=true;
                    
                }
            }
        }
        return ans;
    }
};