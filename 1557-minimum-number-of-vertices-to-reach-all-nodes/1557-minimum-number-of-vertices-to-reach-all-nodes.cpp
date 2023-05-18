class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int> >mp;
        vector<bool>vis(n, false);
        
        for(auto &i:edges){
            int u = i[0];
            int v = i[1];
            
            vis[v] = true;
            
        }
        
        vector<int>ans;
        for(int i=0; i<n; i++){
            if(vis[i] == false){
                ans.push_back(i);
            }
        }
        return ans;
    }
};