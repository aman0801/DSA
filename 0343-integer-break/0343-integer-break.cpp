class Solution {
public:
    
    int solve(int n, int curr, int idx){
        if(curr == 0){
            return 1;
        }
        
        if(curr < 0 || idx > n){
            return 0;
        }
        
        int not_take = solve(n, curr, idx+1);
        int take = idx*(solve(n, curr-idx, idx));
        
        return max(not_take, take);
        
    }
    
    int integerBreak(int n) {
        if(n == 2){
            return 1;
        }
        if(n == 3){
            return 2;
        }
        return solve(n, n, 1);
    }
};
