class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
       int evenIndex = 0;  
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                swap(nums[i], nums[evenIndex++]);
            }
        }
        
        return nums; 
    }
};