class Solution {
public:
    int maxProduct(vector<int>& nums) {
            int left = 1;
            int right = 1;
            int ans = INT_MIN;
            
            for(int i=0; i<nums.size(); i++){
                    if(left == 0){
                            left = 1;
                    }
                    if(right == 0){
                            right = 1;
                    }
                    left = left * nums[i];
                    right = right * nums[nums.size()-i-1];
                    ans = max(ans, max(left, right));
            }
            return ans;
    }
};