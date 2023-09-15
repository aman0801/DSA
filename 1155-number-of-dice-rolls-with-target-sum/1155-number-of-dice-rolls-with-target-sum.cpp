class Solution {
public:
    int MOD = 1000000007; 

    int solve(int d, int f, int target, vector<vector<int>>& memo) {
      
        if (d == 0 && target == 0) return 1;
        if (d == 0 || target < 0) return 0;
        if (memo[d][target] != -1) return memo[d][target];

        int sum = 0;
        for (int i = 1; i <= f; i++) {
            sum = (sum % MOD + solve(d - 1, f, target - i, memo) % MOD) % MOD;
        }

        memo[d][target] = sum;
        return sum;
    }

    int numRollsToTarget(int d, int f, int target) {
        vector<vector<int>> memo(d + 1, vector<int>(target + 1, -1));
        return solve(d, f, target, memo);
    }
};
