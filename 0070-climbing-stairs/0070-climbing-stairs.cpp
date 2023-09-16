class Solution {
public:
    
    int solve(int n, int total, vector<int>& dp){
        if(total == n)return 1;
        
        if(total>n)return 0;
        
        if(dp[total]!=-1)return dp[total];
        
        int oneStep = solve(n, total+1, dp);
        int twoStep = solve(n, total+2, dp);
        
        dp[total] = oneStep+twoStep;
        return dp[total];
        
    }
    
    int solve(int n, int total){
        int count = 0;
        if(total == n)return 1;
        
        if(total>n)return 0;
        
        int oneStep = solve(n, total+1);
        int twoStep = solve(n, total+2);
        
        return oneStep+twoStep;
        
    }
    
    int climbStairs(int n) {
        vector<int>dp(n+1, -1);
        // return solve(n, 0);
            return solve(n, 0, dp);
    }
};