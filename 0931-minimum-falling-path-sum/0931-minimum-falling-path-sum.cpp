class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n));
        dp[m-1]=matrix[m-1];
        for(int i=m-2;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int left=1e9, right=1e9;
                if(j-1>=0) left=dp[i+1][j-1];
                int down=dp[i+1][j];
                if(j+1<n) right=dp[i+1][j+1];
                dp[i][j]=matrix[i][j]+min(left,min(down,right));
            }
        }
        int res=INT_MAX;
        for(int j=0;j<n;j++) res=min(res,dp[0][j]);
        return res;
    }
};