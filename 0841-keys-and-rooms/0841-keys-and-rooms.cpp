class Solution {
public:
    
    void BFS(vector<vector<int>>& rooms, int u, vector<bool>&vis){
        queue<int>q;
        q.push(u);
        vis[u] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto &v:rooms[node]){
                if(!vis[v]){
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        unordered_map<int, vector<int>>adj;
        vector<bool>vis(n, false);
        // BFS(rooms, 0, vis);
         queue<int>q;
        q.push(0);
        vis[0] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto &v:rooms[node]){
                if(!vis[v]){
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
        for(int i=0; i<n; i++){
            if(vis[i] == false){
                return false;
            }
        }
        return true;
    }
};