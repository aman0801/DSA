class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int, int >adj;
        vector<int>inDeg(n+2, 0);
        for(int i=0; i<edges.size(); i++){
             adj[edges[i][0]]++;
             adj[edges[i][1]]++;
        }
        
        // int mini = INT_MIN;
        int ans;
        // for(int i=0; i<n-1; i++){
        //     if(mini < inDeg[i]){
        //         mini = inDeg[i];
        //         ans = i;
        //     }
        // }
        for(auto i:adj){
            if(i.second == n){
                ans = i.first;
            }
        }
        return ans;
    }
};