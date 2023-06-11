class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int countp = 0;
        int countn = 0;
        int count = 0;
        int l = 0;
        int r = nums.size()-1;
        int m;
        
        
        while(l<=r){
             m = l + (r-l)/2;
            if(nums[m]<0){
                countn = m+1;
                l = m+1;
            }else{
                r = m-1;
            }
        }
        
        l = 0;
        r = nums.size()-1;
        
        while(l<=r){
             m = l + (r-l)/2;
            if(nums[m]>0){
                countp = nums.size()-m;
                // l = m+1;
                r = m-1;
            }else{
                // r = m-1;
                l = m+1;
            }
        }
        
        return max(countp, countn);
    }
};