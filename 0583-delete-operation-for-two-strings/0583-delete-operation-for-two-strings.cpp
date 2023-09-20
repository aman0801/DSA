class Solution {
public:
    
    int solve(string& word1, string& word2, int i, int j){
        if(i>=word1.length()){
            return word2.length()-j;
        }
        if(j>=word2.length()){
            return word1.length()-i;
        }
        
        if(word1[i] == word2[j]){
            return solve(word1, word2, i+1, j+1);
        }
        
        int right = 1 + solve(word1, word2, i+1, j);
        int left = 1 + solve(word1, word2, i, j+1);
        
        return min(left, right);
        
    }
    
    int solve(string& word1, string& word2, int i, int j, vector<vector<int>>& dp){
        if(i>=word1.length()){
            return word2.length()-j;
        }
        if(j>=word2.length()){
            return word1.length()-i;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(word1[i] == word2[j]){
            return solve(word1, word2, i+1, j+1, dp);
        }
        
        int right = 1 + solve(word1, word2, i+1, j, dp);
        int left = 1 + solve(word1, word2, i, j+1, dp);
        
        dp[i][j] = min(left, right);
        return dp[i][j];
    }
    
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.length(), vector<int>(word2.length(), -1));
        return solve(word1, word2, 0, 0, dp);
    }
};