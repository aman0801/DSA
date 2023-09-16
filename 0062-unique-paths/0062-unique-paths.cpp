class Solution {
public:
    
    int solve(int m, int n, vector<vector<int>>& dp, int x, int y){
        if(x>=m || y>=n)return 0;
        if(x == m-1 && y == n-1)return 1;
        if(dp[x][y]!=-1)return dp[x][y];
        
        int left = solve(m, n, dp, x+1, y);
        int right = solve(m, n, dp, x, y+1);
        
        dp[x][y] = left+right;
        return dp[x][y];
    }
    
    int uniquePaths(int m, int n) {
        // vector<vector<int>>arr(m, vector<int>(n));
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return solve(m, n, dp, 0, 0);
    }
};