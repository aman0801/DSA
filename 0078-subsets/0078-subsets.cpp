class Solution {
public:
    
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& output, int idx){
        if(idx >= nums.size()){
            ans.push_back(output);
            return;
        }
        
        // for(int i=0; i<nums.size(); i++){
            solve(nums, ans, output, idx+1);
            output.push_back(nums[idx]);
            solve(nums, ans, output, idx+1);
            output.pop_back();
        // }
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>output;
        solve(nums, ans, output, 0);
        return ans;
    }
};