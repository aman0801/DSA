class Solution {
public:
    int solve(string &s,int n,int curr_index,int prev_val,vector<vector<int>>&dp){
        if(curr_index>=n) return 0;
        
        if(dp[curr_index][prev_val]!=-1) return dp[curr_index][prev_val];

        int flip=INT_MAX;
        int no_flip=INT_MAX;
        

        if(s[curr_index]=='1'){
            if(prev_val==0){
                flip=1+solve(s,n,curr_index+1,0,dp);
                no_flip=solve(s,n,curr_index+1,1,dp);
            }
            else{
                no_flip=solve(s,n,curr_index+1,1,dp);
            }
        }
        else{
            if(prev_val==0){
                flip=1+solve(s,n,curr_index+1,1,dp);
                no_flip=solve(s,n,curr_index+1,0,dp);
            }
            else{
                flip=1+solve(s,n,curr_index+1,1,dp);
            }
        }
        return dp[curr_index][prev_val]=min(flip,no_flip);
    }

    int minFlipsMonoIncr(string s) {
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solve(s,n,0,0,dp);
    }
};