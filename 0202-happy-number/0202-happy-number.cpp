class Solution {
public:
    
    void solve(int& n, int& ans){
        if(n>=0 && n<=9){
            ans = n;
            return;
        }
        int sum = 0;
        while(n>0){
            int temp = n%10;
            sum = sum + (temp*temp);
            n = n/10;
        }
        solve(sum, ans);
    }
    
    bool isHappy(int n) {
        int ans = 0;
        solve(n, ans);
        if(ans == 1 || ans == 7){
            return true;
        }
        return false;
    }
};