class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int t=-1;
        int m=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                t=i;
                break;
            }
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]==target){
                m=i;
                break;
            }
        }
        
        return {t,m};
    }
};