class Solution {
public:
        
    int solve(vector<int>& nums, int count, int idx){
            if(idx >= nums.size()-2){
                    return 0;
            }
            
            if(nums[idx+2]-nums[idx+1]==nums[idx+1]-nums[idx]){
                    count++;
                    return count + solve(nums, count, idx+1);
            }       
            return solve(nums, 0, idx+1);
    }    
        
    int numberOfArithmeticSlices(vector<int>& nums) {
            if(nums.size()<3){
                    return 0;
            }
            return solve(nums, 0, 0);
    }
};