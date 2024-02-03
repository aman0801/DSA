class Solution {
public:
    int solve(vector<int>& arr, int k, int idx, vector<int>& dp) {
        if (idx >= arr.size()) {
            return 0;
        }

        if (dp[idx] != -1) {
            return dp[idx];
        }

        int ans = 0;
        int maxi = -1;

        for (int i = idx; i < arr.size() && i - idx + 1 <= k; i++) {
            maxi = max(maxi, arr[i]);
            ans = max(ans, ((i - idx + 1) * maxi) + solve(arr, k, i + 1, dp));
        }

        dp[idx] = ans;
        return ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(arr, k, 0, dp);
    }
};
