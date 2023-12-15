class Solution {
    public int findMin(int[] nums) {
            int ans = Integer.MAX_VALUE;
            int i=0;
            int j=nums.length-1;
            
            while(i<=j){
                    int mid = (i+j)/2;
                    
                    if(nums[mid]<=nums[j]){
                            ans = Math.min(ans, nums[mid]);
                            j=mid-1;
                    }else{
                            i=mid+1;
                    }
                    
            }
            return ans;
    }
}