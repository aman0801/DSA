class Solution {
public:
    int solve(int n, vector<int>& memo) {
        if (n == 0) {
            return 0;
        }
        if (memo[n] != -1) {
            return memo[n];
        }
        int ans = INT_MAX;
        for (int i = 1; i * i <= n; i++) {
            int temp = 1 + solve(n - i * i, memo);
            ans = min(ans, temp);
        }
        memo[n] = ans;
        return ans;
    }

    int numSquares(int n) {
        vector<int> memo(n + 1, -1);
        return solve(n, memo);
    }
};
