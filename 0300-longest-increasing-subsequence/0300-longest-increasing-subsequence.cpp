class Solution {
public:
    
    int solve(vector<int>& nums, int curr, int prev, vector<vector<int>>& dp){
        if(curr>=nums.size())return 0;
        
        if(dp[curr][prev+1]!=-1)return dp[curr][prev+1];
        
        int inc=0, exc=0;
        if(prev == -1 || nums[curr]>nums[prev]){
            inc = 1 + solve(nums, curr+1, curr, dp);
        }
        
        exc = solve(nums, curr+1, prev, dp);
        
        dp[curr][prev+1] = max(inc, exc);
        return dp[curr][prev+1];
    }
    
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(), vector<int>(nums.size()+1, -1));
        return solve(nums, 0, -1, dp);
    }
};