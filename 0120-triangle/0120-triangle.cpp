class Solution {
public:
        
    int solve(vector<vector<int>>& triangle, int x, int y, vector<vector<int>>&dp){
            if(x>triangle.size() || y>triangle[x-1].size()) return 0;
            
            if(dp[x][y]!=-1){
                    return dp[x][y];
            }
            
            int sum1 = solve(triangle, x+1, y, dp);
            int sum2 = solve(triangle, x+1, y+1, dp);
            
            dp[x][y] = min(sum1, sum2) + triangle[x-1][y-1];
            return dp[x][y];
    }
        
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return solve(triangle, 1, 1, dp);
    }
};