class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int ans = nums[0];
        while(low<high){
            int mid = low+(high-low)/2;
            
            if(nums[mid]>nums[high]){
                low = mid+1;
            }else if(nums[mid]<nums[low]){
                high = mid;
            }else{
                high--;
            }
        }
        return min(nums[low], ans);
    }
};