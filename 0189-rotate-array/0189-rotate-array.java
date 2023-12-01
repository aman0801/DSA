class Solution {
        
    public void reverse(int[] nums, int st, int end){
        int tmp = 0;
            while(st<end){
                tmp = nums[st];
                nums[st] = nums[end];
                nums[end] = tmp;
                st++;
                end--;    
            }
    }    
        
    public void rotate(int[] nums, int k) {
         k = k % nums.length;
         reverse(nums, 0, nums.length - k - 1);
         reverse(nums, nums.length - k, nums.length - 1);
         reverse(nums, 0, nums.length - 1);   
    }
}