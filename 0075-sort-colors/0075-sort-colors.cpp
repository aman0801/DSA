class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count=0;
        int count1=0;
        int count2=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count++;
            }
            if(nums[i]==1){
                count1++;
            }
            if(nums[i]==2){
                count2++;
            }
        }
          for(int i =0; i< count; i++){
            nums[i] =0;
        }
        for(int i =count; i< (count1 + count); i++){
            nums[i] =1;
        }
        for(int i =(count1 + count); i< nums.size(); i++){
            nums[i] =2;
        }
    }
};