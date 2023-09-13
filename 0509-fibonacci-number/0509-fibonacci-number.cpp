class Solution {
public:
    
    int solve(int n){
        if(n==0 || n==1){
            return n;
        }
        
        int ans = solve(n-1)+solve(n-2);
        return ans;
        
    }
    
    int solve(int n, vector<int>& dp){
        if(n==0 || n==1){
            return n;
        }
        
        if(dp[n]!=-1){
            return dp[n];
        }
        
        dp[n] = solve(n-1, dp)+solve(n-2, dp);
        return dp[n];
    }
    
    int fib(int n) {
        // int ans = solve(n);
        vector<int>dp(n+1, -1);
        int ans = solve(n, dp);
        return ans;
    }
};