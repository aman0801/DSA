class Solution {
public:
    
    int solve(vector<int>& nums, int n){
        if(n<0){
            return 0;
        }
        
        if(n==0){
            return nums[0];
        }
        
        int inc = solve(nums, n-2) + nums[n];
        int exc = solve(nums, n-1);
        
        return max(inc, exc);
        
    }
    
    int solve(vector<int>& nums, int n, vector<int>& dp){
        if(n<0)return 0;
        if(n==0)return nums[0];
        
        if(dp[n]!=INT_MIN)return dp[n];
        
        int inc = solve(nums, n-2, dp)+nums[n];
        int exc = solve(nums, n-1, dp);
        
        dp[n] = max(inc, exc);
        return dp[n];
        
    }
    
    int rob(vector<int>& nums) {
        // return solve(nums, nums.size()-1);
        vector<int>dp(nums.size(), INT_MIN);
        return solve(nums, nums.size()-1, dp);
    }
};