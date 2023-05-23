class Solution {
public:
    
    void solve(vector<int>& nums, int l, int mid, int h){
        int total = h - l + 1;
        int gap = total%2 + total/2;
        
        while(gap > 0){
            int i = l;
            int j = l+gap;
            while(j <= h){
                if(nums[i] > nums[j]){
                    swap(nums[i], nums[j]);
                }
                i++;
                j++;
            }
             if (gap <= 1) {
                gap = 0;
            } else {
                gap = (gap / 2) + (gap % 2); 
            }
        }
        
    }
    
    void mergesort(vector<int>&nums, int l, int h){
        if(l>=h) return;

        int mid = l + (h - l)/2;
        mergesort(nums,l,mid);
        mergesort(nums,mid+1,h);
        solve(nums,l,mid,h);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums, 0, nums.size()-1);
        return nums;
    }
};