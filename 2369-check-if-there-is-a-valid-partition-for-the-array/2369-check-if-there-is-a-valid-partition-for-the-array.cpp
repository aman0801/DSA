class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        
        for (int i = 2; i <= n; i++) {
            if (nums[i - 1] == nums[i - 2]) {
                dp[i] = dp[i] || dp[i - 2];
            }
            
            if (i - 3 < 0) {
                continue;
            }
            
            if (nums[i - 1] == nums[i - 2] && nums[i - 2] == nums[i - 3]) {
                dp[i] = dp[i] || dp[i - 3];
            }
            
            if (nums[i - 1] == nums[i - 2] + 1 && nums[i - 2] == nums[i - 3] + 1) {
                dp[i] = dp[i] || dp[i - 3];
            }
        }
        
        return dp[n];
    }
};
