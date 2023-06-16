class Solution {
public:
    
    void solve(vector<int>& nums, set<vector<int>>& output, int idx, vector<int>& out){
        if(idx >= nums.size()){
            output.insert(out);
            return;
        }
        
        out.push_back(nums[idx]);
        solve(nums, output, idx+1, out);
        out.pop_back();
        solve(nums, output, idx+1, out);
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        // vector<int>output;
        sort(nums.begin(), nums.end());
        set<vector<int>>output;
        vector<int>out;
        solve(nums, output, 0, out);
        for(auto i: output){
            ans.push_back(i);
        }
        return ans;
    }
};