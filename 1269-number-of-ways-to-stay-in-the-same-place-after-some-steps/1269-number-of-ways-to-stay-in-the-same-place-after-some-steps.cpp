class Solution {
public:
   
    int MOD = 1000000007; 
    int solve(int steps, int arrLen, int rem, int pos, vector<vector<int>>& dp){    
        if(rem == 0 && pos == 0){
            return 1;
        }
        
        if(pos >= arrLen || pos < 0 || rem == 0){
            return 0;
        }
        
        if(dp[pos][rem]!=-1){
            return dp[pos][rem];
        }
        
       long long plus = solve(steps, arrLen, rem-1, pos+1, dp)%MOD;
        // cout << plus << endl;
       long long minus = solve(steps, arrLen, rem-1, pos-1, dp)%MOD;
        // cout << minus << endl;
       long long neutral = solve(steps, arrLen, rem-1, pos, dp)%MOD;
        // cout << neutral << endl;
        // cout << (plus+minus+neutral) << endl;
       return dp[pos][rem] = ((plus+minus+neutral)%MOD);
        
    }
    
    int numWays(int steps, int arrLen) {
        // vector<vector<int>>dp(steps+1, vector<int>(arrLen+1), -1);
        arrLen=min(steps,arrLen);
        vector<vector<int>>dp(arrLen,vector<int>(steps+1,-1));
        return solve(steps, arrLen, steps, 0, dp);
    }
};