class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // for(auto i: nums)
        //     cout<<i<<" ";
        // return 0;
        
          //Brute Force Method
         int a=0,max=INT_MIN;
        // for(int i=0;i<nums.size();i++){
        //     a=0;
        //     for(int j=i;j<nums.size();j++){
        //         a+=nums[j];
        //         if(a>max){
        //             max=a;
        //         }
        //     }
        // }
        // return max;
           for(int i=0;i<nums.size();i++){
               a+=nums[i];
               if(a>max){
                   max=a;
               }
               if(a<0){
                   a=0;
               }
           }
        return max;
    }
};