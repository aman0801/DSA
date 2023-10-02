class Solution {
public:
    
    int first(vector<int>& nums, int target){
        int i=0;
        int j=nums.size()-1;
        int ans = -1;
        while(i<=j){
            int mid = (i+j)/2;
            
            if(nums[mid] == target){
                ans = mid;
                j = mid-1;
            }else if(nums[mid]>target){
                j = mid-1;
            }else{
                i = mid+1;
            }
        }
        return ans;
    }
    
    int second(vector<int>& nums, int target){
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
        vector<int>ans(2, -1);
        ans[0] = first(nums, target);
        ans[1] = second(nums, target);
        
        return ans;
        
    }
};