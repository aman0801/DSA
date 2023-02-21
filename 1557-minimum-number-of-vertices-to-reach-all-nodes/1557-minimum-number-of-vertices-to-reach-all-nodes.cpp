class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>ans;
        vector<int>inD(n, 0);
        vector<bool>vis(n, false);
        unordered_map<int, vector<int> >adj;
        
        for(auto i:edges){
            inD[i[1]]++;
            vis[i[0]] = false;
            vis[i[1]] = false;
        }
        
        for(int i=0; i<n; i++){
            if(inD[i] == 0 && !vis[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};