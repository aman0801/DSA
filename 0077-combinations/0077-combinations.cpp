class Solution {
public:
    void solve(int n, int k, unordered_set<int>& out, vector<vector<int>>& ans, int countn) {
        if (out.size() == k) {
            ans.push_back(vector<int>(out.begin(), out.end()));
            return;
        }

        if (countn > n) {
            return;
        }

        out.insert(countn);
        solve(n, k, out, ans, countn + 1);
        out.erase(countn);
        solve(n, k, out, ans, countn + 1);
    }

    vector<vector<int>> combine(int n, int k) {
        unordered_set<int> out;
        vector<vector<int>> ans;
        solve(n, k, out, ans, 1);
        return ans;
    }
};
