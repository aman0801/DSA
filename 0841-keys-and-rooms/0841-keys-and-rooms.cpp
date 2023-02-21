class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_map<int, vector<int> >adj;
        int n = rooms.size();
        vector<bool>vis(n, false);
        queue<int>q;
        int s = 0;
        q.push(0);
        vis[s] = true;
        
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            for(auto i:rooms[temp]){
                if(!vis[i]){
                    vis[i] = true;
                    q.push(i);
                }
            }
        }
        for(int i=0; i<n; i++){
            if(vis[i] == false){
                return false;
                break;
            }
        }
        return true;
    }
};