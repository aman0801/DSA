class Solution {
public:
    
    int first(vector<int>& nums, int x, int low, int end){
        int ans = -1;
        while(low<=end){
            int mid = end-(end-low)/2;
            
            if(nums[mid] == x){
                ans = mid;
                end = mid-1;
            }else if(nums[mid]>x){
                end = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
    
    int second(vector<int>& nums, int x, int low, int end){
        int ans = -1;
        while(low<=end){
            int mid = end-(end-low)/2;
            
            if(nums[mid] == x){
                ans = mid;
                low = mid+1;
            }else if(nums[mid]>x){
                end = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2);
        ans[0] = first(nums, target, 0, nums.size()-1);
        ans[1] = second(nums, target, 0, nums.size()-1);
        if(ans.size() == 0)return {-1, -1};
        return ans;
    }
};