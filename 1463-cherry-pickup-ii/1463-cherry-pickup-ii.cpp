class Solution {
public:
    vector<vector<vector<int>>> dp;

    int solve(vector<vector<int>>& grid, int r, int c1, int c2) {
        if (r == grid.size()) {
            return 0;
        }

        if (dp[r][c1][c2] != -1) {
            return dp[r][c1][c2];
        }

        int cherries = grid[r][c1];
        if (c1 != c2) {
            cherries += grid[r][c2];
        }

        int maxCherries = INT_MIN;

        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                int nr = r + 1, nc1 = c1 + i, nc2 = c2 + j;

                if (nc1 >= 0 && nc1 < grid[0].size() && nc2 >= 0 && nc2 < grid[0].size()) {
             
                    maxCherries = max(maxCherries, solve(grid, nr, nc1, nc2));
                }
            }
        }

        dp[r][c1][c2] = cherries + maxCherries;

        return dp[r][c1][c2];
    }

    int cherryPickup(vector<vector<int>>& grid) {
        
        dp.assign(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(), -1)));

        return solve(grid, 0, 0, grid[0].size() - 1);
    }
};
