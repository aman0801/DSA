class Solution {
public:
    int MOD = 1000000007;    
    int solve(int n, vector<vector<vector<int>>>& dp, int A, int L){
            if(A>=2 || L>=3){
                    return 0;
            }
            if(n==0){
                    return 1;
            }
            if(dp[n][A][L]!=-1){
                    return dp[n][A][L];
            }
            int a = solve(n-1, dp, A+1, 0)%MOD;
            int l = solve(n-1, dp, A, L+1)%MOD;
            int p = solve(n-1, dp, A, 0)%MOD;
            
            return dp[n][A][L] = ((a+l)%MOD+p)%MOD;
    }    
        
    int checkRecord(int n) {
            vector<vector<vector<int>>>dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1))); 
            return solve(n, dp, 0, 0);
    }
};