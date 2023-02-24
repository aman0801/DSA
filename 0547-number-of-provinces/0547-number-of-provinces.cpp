class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>vis(n, false);
        int count = 0;
        for(int i=0; i<n; i++){
            if(vis[i])continue;
            queue<int>q;
            q.push(i);
            count++;
            
            while(!q.empty()){
            int temp = q.front();
            q.pop();
            vis[temp] = true;
            // for(auto& i:isConnected[temp]){
                for(int i=0; i<isConnected[temp].size(); i++){
                if(!vis[i] && isConnected[temp][i] == 1){
                     q.push(i);
                    vis[i]=true;
                }
            }
        }
            
        }
        
        return count;
    }
};