class Solution {
public:
    
    int solve(vector<int>& coins, int amount){
        if(amount<0){
            return INT_MAX;
        }
        
        if(amount == 0){
            return 0;
        }
        
        int mini = INT_MAX;
        
        for(int i=0; i<coins.size(); i++){
            int ans = solve(coins, amount-coins[i]);
            if(ans != INT_MAX){
                mini = min(ans+1, mini);
            }
        }
        return mini;
    }
    
    int solve(vector<int>& coins, int amount, vector<int>& dp){
        if(amount<0){
            return INT_MAX;
        }
        
        if(amount == 0){
            return 0;
        }
        
        if(dp[amount]!=-1){
            return dp[amount];
        }
        
        int mini = INT_MAX;
        
        for(int i=0; i<coins.size(); i++){
            int ans = solve(coins, amount-coins[i], dp);
            if(ans != INT_MAX){
                mini = min(ans+1, mini);
            }
        }
        dp[amount] = mini;
        return dp[amount];
    }
    
    int sol(vector<int>& coins, int amount){
        
        vector<int>dp(amount+1, INT_MAX);
        
        dp[0] = 0;
        
        for(int i=1; i<=amount; i++){
            int mini = INT_MAX;
            
            for(int j=0; j<coins.size(); j++){
                if(i-coins[j]>=0){
                    int ans = dp[i-coins[j]];
                    if(ans != INT_MAX){
                        mini = min(ans+1, mini);
                    }
                }
            }
            dp[i] = mini;
        }
        return dp[amount];
    }
    
    int coinChange(vector<int>& coins, int amount) {
       // int ans = solve(coins, amount);
        // vector<int>dp(amount+1, -1);
        // int ans = solve(coins, amount, dp);
        int ans = sol(coins, amount);
        if(ans == INT_MAX){
            return -1;
        }
            return ans;
        
    }
};