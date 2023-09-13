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
    
    int sol(int n){
        vector<int>dp(n+1, -1);
        dp[0] = 0;
        if(n == 0){
            return dp[0];
        }
        dp[1] = 1;
        
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    
    int fib(int n) {
        // int ans = solve(n);
        // vector<int>dp(n+1, -1);
        // int ans = solve(n, dp);
        int ans = sol(n);
        return ans;
    }
};