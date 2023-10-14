class Solution {
public:
    
    int solve(vector<int>& cost, vector<int>& time, int idx, int wall, vector<vector<int>>& dp){
        if(wall <= 0){
            return 0;
        }
        
        if(idx >= cost.size()){
            return 1000000000;
        }
        
        if(dp[idx][wall] != -1){
            return dp[idx][wall];
        }
        
        int not_take = solve(cost, time, idx + 1, wall, dp);
        int take = cost[idx] + solve(cost, time, idx + 1, wall - time[idx] - 1, dp);
        
        dp[idx][wall] = min(take, not_take);
        
        return dp[idx][wall];
    }
    
    int paintWalls(vector<int>& cost, vector<int>& time) {
        vector<vector<int>> dp(cost.size() + 1, vector<int>(time.size() + 1, -1));
        return solve(cost, time, 0, time.size(), dp);
    }
};
