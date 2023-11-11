class Solution {
public:
        
int solve(vector<vector<int>>& grid, int x, int y,vector<vector<int>>&dp){
        
        if(dp[x][y]!=-1){
                return dp[x][y];
        }
        
             if (x == grid.size() - 1 && y == grid[0].size() - 1) {
                     return grid[x][y];
             }

                if (x >= grid.size() || y >= grid[0].size()) {
                        return INT_MAX;
                }  
                
                int sum2 = solve(grid, x+1, y, dp);
                int sum3 = solve(grid, x, y+1, dp);
                
                dp[x][y] = min(sum2, sum3)+ grid[x][y];
                return dp[x][y];
        }
        
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size()+1, vector<int>(grid[0].size()+1, -1));
        return solve(grid, 0, 0, dp);
    }
};
/*
1 2 3
4 5 6
*/