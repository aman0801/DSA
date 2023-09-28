class Solution {
public:
    void solve(int i, int j, vector<vector<int>>& ans, int n, int m) {
        for (int col = 0; col < m; col++) {
            ans[i][col] = 0;
        }

        for (int row = 0; row < n; row++) {
            ans[row][j] = 0;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> ans;
        ans = matrix;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    solve(i, j, ans, n, m);
                }
            }
        }
        
        matrix = ans;
    }
};
