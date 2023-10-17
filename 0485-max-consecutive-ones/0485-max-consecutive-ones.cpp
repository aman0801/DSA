class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
      int currones=0 ;
      int maxones=0 ;  
      for(int i=0;i<nums.size();i++)
      {
       if(nums[i]==1) 
       {
        currones++ ;
        maxones=max(currones,maxones) ;
       }
       else
       {
        currones=0 ;
       }

      }
      return maxones ;
    }
};