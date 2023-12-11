class Solution {
public:
        
     void merge(vector<int>& nums, int low, int high, int mid, int& count){
             int j=mid+1;
             for(int i=low; i<=mid; i++){
                     while(j<=high && nums[i]> 2*(long long)nums[j]){
                             j++;
                     }
                     count = count + j-(mid+1);
             }
             
             int size = high-low+1;
             vector<int>arr(size, 0);
             
             int left=low, right=mid+1, k=0;
             
             while(left<=mid && right<=high){
                     if(nums[left]<nums[right]){
                             arr[k++] = nums[left++];
                     }else{
                             arr[k++] = nums[right++];
                     }     
             }
             
             while(left<=mid){
                     arr[k++] = nums[left++]; 
             }
             while(right<=high){
                     arr[k++] = nums[right++]; 
             }
             int m=0;
             for(int i=low; i<=high; i++){
                     nums[i] = arr[m++];
             }
          
     }   
        
    void mergesort(vector<int>& nums, int low, int high, int& count){
            if(low>=high){
                    return;
            }
                   int mid = (low+high)/2;
                   mergesort(nums, low, mid, count);
                   mergesort(nums, mid+1, high, count);
                   merge(nums, low, high, mid, count);
    }    
        
    int reversePairs(vector<int>& nums) {
            int count=0;
            mergesort(nums, 0, nums.size()-1, count);
            return count;
    }
};