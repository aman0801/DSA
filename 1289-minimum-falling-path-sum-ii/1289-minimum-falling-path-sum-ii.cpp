class Solution {
public:
        
    int solve(vector<vector<int>>& matrix, vector<vector<int>>& dp, int r, int c){
            if(r==matrix.size()-1){
                    return matrix[r][c];
            }
            if(dp[r][c]!=-1){
                    return dp[r][c];
            }
            int ans=INT_MAX;
            for(int i=0; i<matrix.size(); i++){
                    if(i!=c){
                            ans=min(ans, solve(matrix, dp, r+1, i));
                    }
            }
            dp[r][c]=matrix[r][c]+ans;
            return dp[r][c];
    }   
        
    int minFallingPathSum(vector<vector<int>>& matrix) {
            vector<vector<int>>dp(matrix.size()+1, vector<int>(matrix[0].size()+1, -1));
            int ans=INT_MAX;
            for(int i=0; i<matrix[0].size(); i++){
                    ans=min(ans, solve(matrix, dp, 0, i));
            }
            return ans;
    }
};