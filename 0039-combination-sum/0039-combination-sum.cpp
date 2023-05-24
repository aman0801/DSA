class Solution {
public:
    vector<vector<int>>ans;
    vector<int>output;
    void solve(vector<int>& candidates, int target, int index){
       if(target == 0){
           ans.push_back(output);
           return;
        }
        if(target < 0 || index == candidates.size()){
           return;
       }
        
        output.push_back(candidates[index]);
        solve(candidates, target-candidates[index], index);
        output.pop_back();
        solve(candidates, target, index+1);

        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // vector<vector<int> >ans;
        // vector<int>output;
        int index = 0;
        solve(candidates, target, index);
        return ans;
    }
};

