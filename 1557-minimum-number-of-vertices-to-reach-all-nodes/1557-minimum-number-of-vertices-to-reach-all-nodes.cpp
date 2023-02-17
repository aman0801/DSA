class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>ans;
        vector<int>inDe(n, 0);
        
        for(auto i: edges){
            inDe[i[1]]+=1;
        }
        for(int i=0; i<n; i++){
            if(inDe[i] == 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};