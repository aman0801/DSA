class Solution {
public:
    
    int firstP(vector<int>& nums, int target){
        int i=0;
        int j=nums.size()-1;
        int ans = -1;
        while(i<=j){
            int mid = (i+j)/2;
            if(nums[mid] == target){
                ans = mid;
                j = mid-1;
            }else if(nums[mid]<target){
                i = mid+1;
            }else{
                j = mid-1;
            }
        }
        return ans;
    }
    
    int lastP(vector<int>& nums, int target){
        int i=0;
        int j=nums.size()-1;
        int ans = -1;
        while(i<=j){
            int mid = (i+j)/2;
            if(nums[mid] == target){
                ans = mid;
                i = mid+1;
            }else if(nums[mid]<target){
                i = mid+1;
            }else{
                j = mid-1;
            }
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstP(nums, target);
        int last = lastP(nums, target);
        return {first, last};
    }
};