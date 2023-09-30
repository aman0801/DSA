class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i=digits.size()-1; i>=0; i--){
            if(digits[i]!=9){
                digits[i]++;
                break;
            }else{
                digits[i] = 0;
            }
        }
        if(digits[0] == 0){
            vector<int>ans(digits.size()+1, 0);
            ans[0] = 1;
            return ans;
        }
        return digits;
    }
};