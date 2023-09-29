class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc = true;  
        bool dec = true;  
        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i - 1] > nums[i]) {
                inc = false;  
                break;
            }
        }
        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i - 1] < nums[i]) {
                dec = false; 
                break;
            }
        }
        
        return inc || dec;
    }
};
