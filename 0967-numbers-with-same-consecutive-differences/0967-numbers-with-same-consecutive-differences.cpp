class Solution {
public:
    vector<int>ans;
    
    int counting(int digit){
        int count = 0;
        while(digit > 0){
            count++;
            digit = digit/10;
        }
        return count;
    }
    
    void solve(int digit, int n, int k){
        if(counting(digit) == n){
            ans.push_back(digit);
            return;
        }
        
        for(int i=0; i<=9; i++){
            int temp = digit%10;
            if(abs(temp-i) == k){
                int num = digit*10+i;
                solve(num, n, k);
            }
        }
        
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i=1; i<=9; i++){
            solve(i, n, k);
        }
        return ans;
    }
};