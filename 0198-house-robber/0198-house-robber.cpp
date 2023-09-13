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
    
    int sol(vector<int>& nums, int n){
        vector<int>dp(nums.size()+1, 0);
        
        dp[0] = nums[0];
        
        for(int i=1; i<=n; i++){
            int temp = 0;
            if(i-2>=0)
                temp = dp[i-2];
            
            int inc = temp+nums[i];
            int exc = dp[i-1];
            
            dp[i] = max(inc, exc);
        }
        return dp[n];
    }
    
    int rob(vector<int>& nums) {
        // return solve(nums, nums.size()-1);
        // vector<int>dp(nums.size(), INT_MIN);
        // return solve(nums, nums.size()-1, dp);
        return sol(nums, nums.size()-1);
    }
};