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
            int j=0;
            for(auto& i:isConnected[temp]){
                if(!vis[j] && i == 1){
                     q.push(j);
                    vis[j]=true;
                }
                j++;
            }
        }
            
        }
        
        return count;
    }
};