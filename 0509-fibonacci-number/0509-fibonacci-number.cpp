class Solution {
public:
    
    int solve(int n){
        if(n==0 || n==1){
            return n;
        }
        
        int ans = solve(n-1)+solve(n-2);
        return ans;
        
    }
    
    int fib(int n) {
        int ans = solve(n);
        return ans;
    }
};