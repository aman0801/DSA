class Solution {
public:
    long long mod = 1e9 + 7;

    int solve(int m, int n, int move, int i, int j, vector<vector<vector<int>>>& dp) {
        if (i < 0 || j < 0 || i >= m || j >= n) {
            return 1;
        }
        if (move == 0) {
            return 0;
        }
        if (dp[i][j][move] != -1) {
            return dp[i][j][move];
        }

        int left = solve(m, n, move - 1, i - 1, j, dp);
        int right = solve(m, n, move - 1, i + 1, j, dp);
        int up = solve(m, n, move - 1, i, j - 1, dp);
        int down = solve(m, n, move - 1, i, j + 1, dp);

        dp[i][j][move] = (left % mod + right % mod + up % mod + down % mod) % mod;
        return dp[i][j][move];
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(maxMove + 1, -1)));
        return solve(m, n, maxMove, startRow, startColumn, dp);
    }
};
