class Solution {
public:
    
    int solve(vector<int>& nums, int st, int end, vector<int>& dp){
        if(st>end) return 0;
        if(dp[st] != -1) return dp[st];
            
        int take = nums[st] + solve(nums, st+2, end, dp);
        int leave = solve(nums, st+1, end, dp);
        
        dp[st] = max(take, leave);
        return dp[st];
    }
    
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        
        vector<int> dp(nums.size(), -1);  // Initialize dp with -1
        
        int takeZero = solve(nums, 0, nums.size() - 2, dp);
        dp.assign(nums.size(), -1);
        int takeOne = solve(nums, 1, nums.size() - 1, dp);
        
        return max(takeZero, takeOne);
    }
};



