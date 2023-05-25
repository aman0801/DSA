class Solution {
public:
    
    void solve(vector<int>& candidates, int target, vector<vector<int>>&ans, vector<int>&output, int index){
        if(target == 0){
            ans.push_back(output);
            return;
        }
        if(target<0 || index == candidates.size()){
            return;
        }
        
        for(int i = index; i<candidates.size(); i++){
            if(candidates[i] > target) break;  
            if(i  > index && candidates[i] == candidates[i-1])
                continue;
            output.push_back(candidates[i]);
            solve(candidates, target-candidates[i], ans, output, i+1);
            output.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int>output;
        solve(candidates, target, ans, output, 0);
        return ans;
    }
};